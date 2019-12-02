#include "Graph.h"
Graph::Graph(){
	//TODO: PARTA:
	//@ creation, determine if Graph is directed or undirected
	//empty constructor
}

Graph::Graph(bool D){
	 :isDirectd = D;
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
void Graph::DepthFirstSearch(int source){

		map<int, vector<int>>::iterator sIt = adj.begin();

		std::cout << "#" << numElements << std::endl;
		color = vector<color_t>(numElements + 1, WHITE);
		distance = vector<int>(numElements + 1, -1);
		parent = vector<int>(numElements + 1, -1);
		stack<int> Neighbors = stack<int>();
		//adjacency list storage ^^
		globaltime = 0;
		numCycles = 0;

		int curr = source;

		// Vertex[source] -> color = WHITE;
		// Vertex[source] -> parent = NULL;
		// Vertex[source] -> discovertime = Vertex[source] -> finishtime = 0;

	while(sIt != adj.end()){

		if(color[sIt->first] != BLACK){//if finished vertex

			current = sIt->first;
			int u = current;

			if(color[parent[u]] == WHITE) //new subgraph{


				cout << "new sub-graph " << sIt->first;
				vector<vector<int>>::iterator subGraphsIter = subGraphs.begin();
				subGraphs.insert(subGraphsIter, topoSort);
				topoSort.clear();
				
			}
			
			//adjacency list \/
			for(auto E = vertices[V].begin(); E != vertices[V].end(); E++){
				if((*E)->color == WHITE){
					DFS_Visit(V);
					}//end inside if
				}//end for
			}//end while
	}
}

void Graph::DFS_Visit(int source){
	globaltime = globaltime++;
	Vertex[source]->discovertime = globaltime;
	Vertex[source]->color = GRAY;

	//source is s...
	//This loop detects cycles 
	for(auto E = vertices[V].begin(); E != vertices[V].end(); E++){
		if((*E)->color == WHITE){
			(*E)->parent = vertices[V]; //s
			DFS_Visit(E);
		}
		//TODO: PARTD: Check if this works
		//DAG detection
		if((E*)->color == GRAY){
			numCycles++;
			std::cout << "The graph has cycles in it!\n";
			return;
		}
	}//end for

	globaltime = globaltime++;
	Vertex[source]->finishtime = globaltime;
	Vertex[source]->color = BLACK;
}

void Graph::AddVertex(int InsertVertex){
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
	vertices[InsertEdge1].push_back(Vertex[InsertEdge2]);
	vertices[InsertEdge2].push_back(Vertex[InsertEdge1]);
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

//PART E: TOPOLOGICAL SORT
//	needs DAG check
//  needs Transpose function
// is an ordering of the vertices{v1, v2, . . . , vn} so that if i > j,
// then there cannot be a path in the graph from vi to vj (there may or may not be a path from vj to vi).
vector<int> Graph::topSort()
{
	vector<int> output;
	map<int, vector<int>>::iterator it = vertices.begin();
	if(isDAG() || numCycles < 0)//if cycles isn't computed it will still try dfs
	{
		output = Dfs(it->first);
	}else //it's not directed or has a cycle
	{
		cout << "The graph is not a DAG." << endl;
	}
	for(int i : output)
		cout << i << " ";
	cout << endl;
	return output;
}
//PART F: SCC detection, d/n have to be acyclic (so no DAG check)
// vector<vector<int>> Graph::SCC()
// {
// 	if(!isDAG() || numCycles < 0) //numcycles is -1 if it hasn't been computed
// 	{
// 		if(isDirected())
// 			Dfs(0);
// 	}
// 	vector<int> output = Dfs(1, transpose);

// 	return subGraphs;//calculated in DFS
// }

// vector<int> Graph::getTranspose()
// {
// 	vector<int> t;
// 	vector<int>::reverse_iterator rit = parent.begin();
// 	for(; rit != parent.end(); ++rit )
// 		t.push_back(*rit);
// 	return t;
// }