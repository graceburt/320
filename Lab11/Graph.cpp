#include "Graph.h"

Graph::Graph(bool D){
	//TODO: PARTA:
	//@ creation, determine if Graph is directed or undirected
	setDirection(D);
}

Graph::~Graph(){
	for(auto iter = Vertex.begin(); iter != Vertex.end(); iter++){
		delete Vertex[iter -> first];
	}
}
void Graph::BreadthFirstSearch(int source){
	if(vertices.find(source) != vertices.end()){
		std::queue<int> Q;
		Vertex[source] -> color = GRAY;
		Vertex[source] -> distance = 0;
		Q.push(source);
		while(!Q.empty()){
			int V = Q.front();
			Q.pop();
			for(auto E = vertices[V].begin(); E != vertices[V].end(); E++){
				if((*E) -> color == WHITE){
					(*E) -> color = BLACK;
					(*E) -> distance = Vertex[V] -> distance + 1;
					(*E) -> parent = Vertex[V];
					Q.push((*E) -> value);
					std::cout << (*E) -> value << " ";
				}
			}

		}
	}
	//std::cout << std::endl;
	else{
		std::cout << "Error: Start value is not in list\n";
	}
}

// std::vector<int> Graph::Dfs(int start){

// 	return DepthFirstSearch(start);
// }

std::vector<int> Graph::DepthFirstSearch(int source){

	if(vertices.find(source) != vertices.end()){
			std::stack<int> S;
			Vertex[source] -> color = WHITE;
			Vertex[source] -> parent = NULL;
			Vertex[source] -> discovertime = Vertex[source] -> finishtime = 0;
		
		while(!S.empty()){

			int V = S.top();
			S.pop();
			//adjacency list \/
			for(auto E = vertices[V].begin(); E != vertices[V].end(); E++){
				
				if((*E)->color == WHITE){
					DFS_Visit(V, S);
					}//end inside if
				}//end for
			}//end while

	//------------------ TOPO SORT --------------------//

	vector<int> output;
	std::map<int, vector<Node*>>::iterator it = vertices.begin();

	//if cycles isn't computed it will still try dfs
			if(isDAG() || numCycles < 0){
				output = DepthFirstSearch(it->first);
			}else //it's not directed or has a cycle
			{
				std::cout << "The graph is not a DAG." << endl;
			}

			for(int i : output)
				std::cout << i << " ";
			std::cout << endl;
	
		return output;

	}//end outside if
	else{
		std::cout << "Error: Start value is not in list\n";
	}
}

void Graph::DFS_Visit(int source, std::stack<int> S){

	int globaltime = 0;
	globaltime++;

	Vertex[source]->discovertime = globaltime;
	Vertex[source]->color = GRAY;

	int V = S.top();
	//source is s...
	//This loop detects cycles 
	for(auto E = vertices[V].begin(); E != vertices[V].end(); E++){
		if((*E)->color == WHITE){
			(*E)->parent = *E; //s
			DFS_Visit((*E)->value, S);
		}
		//TODO: PARTD: Check if this works
		//Technically DAG detection
		if((*E)->color == GRAY){
			numCycles++;
			std::cout << "The graph has cycles in it!\n";
			return;
		}
	}//end for

	globaltime++;
	Vertex[source]->finishtime = globaltime;
	Vertex[source]->color = BLACK;
}

void Graph::AddVertex(int InsertVertex){
	numElements++;
	if(vertices.find(InsertVertex) == vertices.end()){ // Check to determine if value of InsertVertex is in list
		Node * insertion = new Node;
		insertion -> value = InsertVertex;
		insertion -> color = WHITE;
		insertion -> parent = NULL;
		insertion -> distance = std::numeric_limits<int>::max(); //To set distance to infinity, https://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c was referenced
		Vertex[InsertVertex] = insertion;
		vertices[InsertVertex] = std::vector<Node *>(); 
	}
}

//TODO: PART B: Check if Graph is directed or undirected. 
//		IF UNDIRECTED: both directions of edge should be added
void Graph::AddEdge(int InsertEdge1, int InsertEdge2){
	// check if vertices exist, then add edge
	if(vertices.find(InsertEdge1) == vertices.end()){
		AddVertex(InsertEdge1);
	}
	if(vertices.find(InsertEdge2) == vertices.end()){
		AddVertex(InsertEdge2);
	}
	//push_back puts element at end of vector
	//increases vector size by 1

	//If directed, add both edges (<- directions? ->)
	if(isDirectd){
		vertices[InsertEdge2].push_back(Vertex[InsertEdge1]);
	}else{
		vertices[InsertEdge2].push_back(Vertex[InsertEdge1]);
	}
}

// prints the adjacency list of each vertex, to show the structure
void Graph::Print(){
	for(auto iter = vertices.begin(); iter != vertices.end(); iter++){
		std::cout << "Neighbors of node " << iter -> first << ": "; 
		for(Node* curr : iter -> second){
			std::cout << curr -> value << ' ';
		}
		std::cout << std::endl;
	}
}
void Graph::PrintBFS(int start){
	std::cout << "Visited/Discovered: " << start << ' ';
	BreadthFirstSearch(start);
}


//PART F: SCC detection, d/n have to be acyclic (so no DAG check)
// vector<vector<int>> Graph::SCC()
// {
// 	if(!isDAG() || numCycles < 0) //numcycles is -1 if it hasn't been computed
// 	{
// 		if(isDirected()){
// 			DepthFirstSearch(0);
	//}
// 	}
// 	vector<int> output = Dfs(1, transpose);

// 	return subGraphs;//calculated in DFS
// }
