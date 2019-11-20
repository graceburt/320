/*
* Lab 8 320
* Grace Burton
* Dr. Anderson
* October 
*/

//main.cpp
#include "BST.cpp"

int main(){

BinaryTree* Tree = new BinaryTree;

Tree->insert(12);
Tree->insert(13);
Tree->insert(14);
Tree->insert(1);
Tree->insert(20);

Tree->searchVal(1);

Tree->minimum();
Tree->maximum();
Tree->successor();
Tree->printTree();

Tree->deleteNode(20);



// timing bs

int sec = 60;

double start2 = double(clock())/sec;

for(int i = 0; i < 10000; i++){

	Tree->insert(i);

}

double finish2 = double(clock())/sec;

std::cout << "Timing for 1000 inserts in milliseconds: " << finish2 - start2 << std::endl;



// double start3 = double(clock())/sec;

// for(int i = 0; i < 2000; i++){

// 	Tree->insert(i);

// }

// double finish3 = double(clock())/sec;

// std::cout << "Timing for 2000 inserts in milliseconds: " << finish3 - start3 << std::endl;

// //

// double start = double(clock())/sec;

// for(int i = 0; i < 3000; i++){

// 	Tree->insert(i);

// }

// double finish = double(clock())/sec;

// std::cout << "Timing for 3000 inserts in milliseconds: " << finish - start << std::endl;



return 0;

}