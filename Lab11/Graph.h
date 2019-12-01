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

int globaltime = 0;

class Graph{
private:
	/* will map an int to a list of its neighbors */
	std::map<int, std::vector<Node*>> vertices; 
	std::map<int, Node*> Vertex; // creation of adjancey list
	void BreadthFirstSearch(int); // Applies BFS algorithm has outlined in lab
	void DepthFirstSearch(int);
	void DFS_Visit(int);
public:
	Graph(); //constructor
	~Graph(); //deconstructor
	void AddVertex(int); // Adds a vertex to the graph
	void AddEdge(int, int); // Adds an undirected edge to the graph
	void Print(); // Prints the adjacency list of each vertex, to show the structure
	void PrintBFS(int); // Prints the vertices discovered by Breadth-First Search (BFS), starting at a given vertex
};
#endif