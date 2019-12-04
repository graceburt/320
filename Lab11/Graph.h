#ifndef GRAPH_H
#define GRAPH_H

//standard libraries frequently referenced
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

int globaltime = 0;

enum color_t{

	WHITE, GRAY, BLACK
};
struct Node{

	color_t color;
	int distance;
	int discovertime;
	int finishtime;
	int value;
	Node * parent;
};

class Graph{

private:

	/* will map an int to a list of its neighbors */
	//i.e. Adjacency List!
	std::map<int, std::vector<Node*>> vertices; 
	std::map<int, Node*> Vertex; // creation of adjacency list

	// std::vector<color_t> color; //stores color
	// std::vector<int> distance; //stores distance
	// std::vector<int> parent; //stores parent nodes
	
	void BreadthFirstSearch(int); // Applies BFS algorithm has outlined in lab
	void DepthFirstSearch(int);
	void DFS_Visit(int, std::stack<int>);

	bool isDirectd;

	int numElements = 0;

	std::map<int, std::vector<int>> transpose;

	int numCycles;
	std::vector<vector<int>> cycles;



public:

	Graph(bool); //constructor
	~Graph(); //deconstructor
	void AddVertex(int); // Adds a vertex to the graph
	void AddEdge(int, int); // Adds an undirected edge to the graph
	void Print(); // Prints the adjacency list of each vertex, to show the structure
	void PrintBFS(int); // Prints the vertices discovered by Breadth-First Search (BFS), starting at a given vertex

	std::vector<int> topSort();
	std::vector<vector<int>> SCC();
	std::vector<int> getTranspose();

	void setDirection(bool s){
		isDirectd = s;
	}

	bool isDirected(){

		return isDirectd;
	};

	bool hasCycle() const {

		return numCycles > 0;
	};

	bool isDAG() const{

		return isDirectd && numCycles == 0;
	};

};
#endif