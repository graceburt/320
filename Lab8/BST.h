/*
* Lab 8 320
* Grace Burton
* Dr. Anderson
* October 
*/

struct TreeNode {
		int key;
		TreeNode* left;
		TreeNode* right;
		TreeNode* parent;

		TreeNode(){

			key = 0;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		};

		TreeNode(int n){

			key = n;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		};

};

class BinaryTree
{

	private:
		
	TreeNode* root;

	void transplant(TreeNode* u, TreeNode* v){
		
		if(u = root){
			root = v;
			return;
		}

		if(u == u->left->parent){
			u->left->parent = v; //is left child
		}else{
			u->right->parent = v; //is right child
		}

		if(v != nullptr){
			v->parent == u->parent;
		}
	};

	int minimum(TreeNode* n);
	int maximum(TreeNode* n);
	int successor(TreeNode* n);

	public:

		BinaryTree();
		~BinaryTree();
		
		int minimum();
		int maximum();
		int successor();
		
		TreeNode* parent(TreeNode* child);
		void inOrder(TreeNode* root);
		void printTree();
		TreeNode* searchVal(int x);
		void insert(int x);
		void deleteNode(int v);
		void deleteTree(TreeNode* c);

}; //end BST