/*
* Grace Burton and Lauren Golian
* Dr. Anderson 320
* Project 3
* main.cpp
*/
#include "graph.h"


bool menu(Map* graph){

	int response = 0;
	bool quit = false;


	while(response != 5){

		std::cout << std::endl;
		std::cout << "Welcome to Project 3: Four Coloring Algorithm! " << std::endl;
		std::cout << std::endl;
		std::cout << "	1. Add vertex" << std::endl;
		std::cout << "	2. Add edge" << std::endl;
		std::cout << "	3. Delete edge" << std::endl;
		std::cout << "	4. Color my graph!" << std::endl;
		std::cout << "	5. Quit" << std::endl;


		std::cout << std::endl;
		std::cout << "Please input the option you would like: " << std::endl;
		std::cout << std::endl;
		std::cin >> response;
		std::cout << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << std::endl;

		int val; 

		if(response >= 1 && response <=4){

			switch(response){

				case 1:
				{
					std::cout << "What would you like the id of the vertex to be? " << std::endl;
					std::cout << "	(Takes int value) " << std::endl;
					std::cout << std::endl;
					std::cin >> val;
					graph->addVertex(val);


					break;
				}
				case 2:
				{

	    			//USE ADJ MATRIX
	    			// EX [1][2]
	    			//UNDIRECTED [2][1]
					int res;
					std::cout << "Would you like to add an edge to an existing vertex or create a new one? " << std::endl;
					std::cout << "	1. Add a new vertex" << std::endl;
					std::cout << "	2. Use old vertices" << std::endl;
					std::cout << "	3. Quit" << std::endl;

					std::cout << std::endl;
					std::cin >> res;

					int val, val2;

					switch(res){

						case 1:
						{
							std::cout << "What would you like the name of the new vertex to be? " << std::endl;
							std::cout << "	(Takes INT value) " << std::endl;
							std::cout << std::endl;
							std::cin >> val;
							graph->addVertex(val);

							std::cout << "Which vertex would you like to attach this one to?" << std::endl;
							std::cout << "	(Takes INT value) " << std::endl;
							std::cout << std::endl;
							std::cin >> val2;
			    			//graph->searchVertex(val2);
			    			graph->addEdge(val, val2);
			    			graph->printGraph();
							break;
			    		}//close 1
			    		case 2:
			    		{
			    			std::cout << "Which vertices would you like to use?" << std::endl;
			    			std::cout << "	(Takes int value) " << std::endl;
			    			std::cout << std::endl;

			    			std::cout << "Vertex one" << std::endl;
			    			std::cout << std::endl;
			    			int strv1;
			    			std::cin >> strv1;
			    			std::cout << std::endl;
			    			std::cout << "Vertex two" << std::endl;
			    			int strv2;
			    			std::cin >> strv2;

			    				graph->addEdge(strv1, strv2);
			    				graph->printGraph();
			    			
			    			break;

			    		}//close 2
			    		case 3:
			    		{
			    			quit = true;
			    			break;
			    		}//close 3

	    		}//close 3 switch

	    		break;
	    	}//case 3
	    	case 3:
	    	{
	    		int res;

	    		std::cout << "What edge would you like to delete?" << std::endl;
	    		std::cout << "	(Takes int value) " << std::endl;
			    			std::cout << std::endl;
			    	//graph->printGraph();
	    		std::cout << std::endl;
						//select the vertices the edge is connected to:
	    		std::cout << "Vertex one" << std::endl;
	    		std::cout << std::endl;
	    		int strv1;
	    		std::cin >> strv1;
	    		std::cout << std::endl;
	    		std::cout << "Vertex two" << std::endl;
	    		std::cout << std::endl;
	    		int strv2;
	    		std::cin >> strv2;
	    		std::cout << std::endl;

	    		graph->adj[strv1][strv2] == 0;

	    			break;
		    	} //case 4
				case 4:
				{
					graph->greedyColoring();
				}
			}//end switch
	    }//end if
	    else{

	    	std::cout << "Invalid response" << std::endl;
	    }

	}//while loop

	return quit;
};


int main(){

	Map* USA = new Map();

	menu(USA);

	//USA->greedyColoring();




	return 0;
};