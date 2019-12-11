/*
* Grace Burton and Lauren Golian
* Dr. Anderson 320
* Project 3
* graph.h
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

enum color_t{

	ONE, TWO, THREE, FOUR
};

class Node{

public:

	color_t color;
	std::string name;
	int id;
	Node* parent;

	Node(){

		name = "";
		id = 0;
		parent = NULL;
	};

	Node(std::string n){

		name = n;
		id = 0;
		parent = NULL;
	};
};

class Map{

    int E; //num of edges
	int numElements; //number of vertices

    public:

    std::vector<Node*> vertices; //list of vertices
    int** adj;

	    Map(){ 

	    	this->numElements = 0; 
	    	this->E = 0;
	    	adj = new int*[1000];
    
		    for(int i = 0; i < 1000; i++){
		    	adj[i] = new int[1000];
		    };

	    };
	    
	    // ~Map(){ 

	    //    	delete [] adj;
	    // };

	    void addEdge(int InsertEdge1, int InsertEdge2);
	    void addVertex(int n);
	    void writeEdges();
	    void greedyColoring();
	    //void Print();

	    int getEdges(Map g);
	    void displayMatrix(int v); //v is number of elements
	    void printGraph();
	    void printNodes(std::vector<Node*> n);


};

//ORGINIAL PSEUDO CODE:
//
// color first_available(){
//     //using only three colors
//     //Finds color not used yet, and returns first available color
//     count = [0] * (list.length() + 1);     //Allocate long-enough array of zeros
//     for (color in arr){
//             if(color < count.length()){
//                     count[color] += 1
//                 }//end inside if
//             }//end first for
//     for(color in range(list.length() + 1)){
//     	if(count[color] == 0){

//     	}
//     }

//   return color;
// };

// Map coloring_alg(vector<int> adj){
//     //colors a map of vertices, using 4 colors
//     //step 1: color vertices using 3 color cycle
//     for(int i = 0; i < n; i++){
//         Vertex[i].color = first_available();
//         //if colors from 0-3
//     }
//     //step 2: color all vertices, avoiding the use of a fourth color until absolutely necessary
//     if(Vertex[i].color != color(0,1,2)){
//     	Vertex[i].color = color(3);
//     //3 colors are used up & are touching which is ILLEGAL
//     //step 3: color it the fourth color
//     }

//     return map;

// };




#endif