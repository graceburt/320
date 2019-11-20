/*
* Lab 8 320
* Grace Burton
* Dr. Anderson
* October 
*/

#include "BST.h"
#include <iostream>

BinaryTree::BinaryTree(){

			root = nullptr;

};

BinaryTree::~BinaryTree(){

	deleteTree(root);
};

void BinaryTree::deleteTree(TreeNode* curr){
	if(curr != nullptr){
		deleteTree(curr->left);
		deleteTree(curr->right);
		delete curr;
	}
};

TreeNode* BinaryTree::searchVal(int x){

	TreeNode* curr = root;
	while(curr != nullptr && x != curr->key){
		if(x < curr->key){
			curr = curr->left;
		}else{
			curr = curr->right;
		}
	}

	std::cout << "We found the node! " << curr->key << std::endl;
	return curr;

};

void BinaryTree::insert(int x){

	TreeNode* newNode = new TreeNode;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->parent = nullptr;
	newNode->key = x;

	TreeNode* temp = root; //parent of prev
	TreeNode* prev = root; //curr

	while(temp != nullptr){
		prev = temp;
		if(newNode->key < temp->key){
			temp = temp->left;
		}else{
			temp = temp->right;
		}
	}

	newNode->parent = prev;

	if(prev == nullptr){
		root = newNode;
	}
	else if(newNode->key < prev->key){
		prev->left = newNode;
	}else{
		prev->right = newNode;
	}

};

int BinaryTree::minimum(TreeNode* n){

	TreeNode* temp = n;
	while(n -> left != nullptr){
		n = n->left;
	}

	std::cout << "We found the minimum! " << n->key << std::endl;
	return n->key;
};

int BinaryTree::minimum(){

	return minimum(root);
};

int BinaryTree::maximum(){

	return maximum(root);
};

int BinaryTree::maximum(TreeNode* n){

	TreeNode* temp = n;
	while(n->right != nullptr){
		n = n->right;
	}

	std::cout << "We found the maximum! " << n->key << std::endl;
	return n->key;
};

int BinaryTree::successor(){

	return successor(root);
};

int BinaryTree::successor(TreeNode* n){

	if(n->right != nullptr){
		return minimum(n->right);
	}
	else{
	TreeNode* y = n->parent;

	while(y != nullptr && n == y->right){
		n = y;
		y = y->parent;
	}
}//end else

};

void BinaryTree::deleteNode(int value){

	TreeNode* tree = searchVal(value);

	if(tree == nullptr){
		std::cout << "Cannot delete null" << std::endl;
	}
	else{

		if(tree->left == nullptr){ //if n is leaf
			std::cout << "Left is null" << std::endl;
			transplant(tree, tree->right);
		}
		else if(tree-> right == nullptr){
			std::cout << "right is null " << std::endl;
			transplant(tree, tree->left);
		}
		else{

			std::cout << "Left and right are not null " << std::endl;
			TreeNode *Y = searchVal(minimum(tree->right));
			
			if(Y->parent != tree){
				transplant(tree, tree->right);
				Y->right = tree->right;
				Y->right->parent = Y;
			}
			transplant(tree, Y);
			Y->left = tree->left;
			Y->left->parent = Y;
		}//end else

	}//end first else

};


void BinaryTree::inOrder(TreeNode* curr){

	if(curr != nullptr){
		inOrder(curr->left);
		std::cout << curr->key << " " << std::endl;
		inOrder(curr->right);
	}
};

void BinaryTree::printTree(){
	
	inOrder(root);
	std::cout << std::endl;
};