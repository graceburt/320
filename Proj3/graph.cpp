/*
* Grace Burton and Lauren Golian
* Dr. Anderson 320
* Project 3
* graph.cpp
*/

#include "graph.h"

void Map::addEdge(int e1, int e2){

    adj[e1][e2] = 1;
    adj[e2][e1] = 1;

    E++;
};


void Map::addVertex(int num){

	numElements++;
	Node* insertion = new Node();
	insertion->id = num;
	vertices.push_back(insertion);
	// insertion -> distance = std::numeric_limits<int>::max(); //To set distance to infinity, https://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c was referenced

};

void Map::greedyColoring(){

    bool availableColors[numElements + 1]; // availableColors[2] == 0 means that color # 2 is not available for tested vertex
    int colors[numElements + 1]; // which colors have vertices

    for(int i = 0; i < numElements + 1; i++) {
        colors[i] = -1;
    }
    colors[0] = 0; // first vertex has the color number 0

    for(int i = 0; i < numElements + 1; i++) {

       // every color is available at the beginning
        for(int j = 0; j < numElements + 1; j++) {
            availableColors[j] = 1;
        }
        // if there is any colored vertex connected to the "i" one with edge, sign it in availableColors array
        // colors[x] == -1 means that there is no assigned color to x vertex
        for(int j = 0; j < numElements + 1; j++) { //used to be adj[i].size()
            if(colors[adj[i][j]] != -1) {
                availableColors[colors[adj[i][j]]] = 0;
            }
        }
       
        for(int j = 0; j < numElements; j++) {
            if(availableColors[j] == 1) {
                colors[i] = j;
                break;
            }
        }

    }

    // find max # of color
    int maximum = -1;
    for (int i = 0; i < numElements; i++){
        if(colors[i] > maximum){
        	maximum = colors[i];
        }
    }

    std::cout << "To color this graph we need: " << maximum + 1 << " colors."<< std::endl;
};

//print out edges
void Map::printGraph(){

        std::cout << "\n Adjacency list \n"; 

        for(int i = 1; i < numElements; i++){

        	std::cout << i << " -> ";

	      for(int j = 1; j < numElements; j++){

	      	if(adj[i][j] == 1){

	      		std::cout << j << " ";

	      	}//end inside if 

	      }//end inside for
      std::cout << std::endl;
   }//end outside for

};

//returns # of edges
int Map::getEdges(Map g){

	return g.E;
};

//display adj matrix
void Map::displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         std::cout << adj[i][j] << " ";
      }
      std::cout << std::endl;
   }
};


//display adj matrix
void Map::printNodes(std::vector<Node*> input){
   
   for(int i = 0; i < input.size(); i++){
		std::cout << input[i]->id << ' ';
	}
};
