#include <iostream>
#include <stdlib.h>
#include "Graph.h"

int main(){


	Graph graphing(true); //instantiation of graphing class
	graphing.AddVertex(1);	
	graphing.AddVertex(2);	
	graphing.AddEdge(1, 2);
	std::cout << "----------------PRINTING ADJACENCY LIST----------------\n";
	graphing.Print();
	std::cout << "--------------------PRINTING BFS--------------------\n";
	graphing.DepthFirstSearch(1);
	std::cout << std::endl;
}