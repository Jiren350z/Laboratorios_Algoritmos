#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Grafo
{
	public:
		Grafo(); 						   //constructor por defecto
		Grafo(vector<vector<int>> graph); //constructor por parametros
		~Grafo(); 						 //destructor
		
		void addEdge(vector<vector<int>>& graph, int u, int v); 				   //funcion para añadir aristas entre vertices
		void printGraph(const vector<vector<int>>& graph); 						  //Function para imprimir el grafo
		void isAdyacent(vector<vector<int>>& graph); 							 //funcion para imprimir la matriz adyacente
		bool ExisteCamino(const vector<vector<int>>& graph, int init, int end); //funcion para confirmar casi existe un camino entre vertices
		
		//grafo dirigido
		Grafo(int n) : vertices(n), lista_Ady(n) {}   								 //constructor para el grafo dirigido
		void agregarArista(int origen, int destino); 								//funcion para crear una arista dirigida al grafo
		void imprimirGrafoDirigido(); 											   //funcion para imprimir el grafo dirigido
		bool esCiclico(); 						   								  //funcion para determinar si un grafo es ciclico
		bool busquedaCiclo(int node, vector<bool>& visited, vector<bool>& stack);//funcion que realiza una busqueda en profundidad de los nodos que contengan un ciclo
		void eliminarVertice(int vertice); 										//funcion que permite eliminar uno o mas vertices para crear subgrafos
		
		private:
			vector<vector<int>> graph_;     //grafo normal 
			vector<vector<int>> lista_Ady; //lista adyacente para el grafo dirigido
			int vertices;				  //declaracion de los vertices
};

Grafo::Grafo() //constructor por parametros
{
	
}

Grafo::Grafo(vector<vector<int>> graph) //constructor por parametros
{
	graph_=graph;
	cout<<"constructor por parametros"<<endl;
}

Grafo::~Grafo() //destructor
{
	cout<<"destructor"<<endl;
}

void Grafo::addEdge(vector<vector<int>>& graph, int u, int v) //funcion para añadir aristas entre vertices
{
	graph[u][v] = 1;
	graph[v][u] = 1;
}

//Ejecicio_2
void Grafo::printGraph(const vector<vector<int>>& graph) // funcion para imprimir la matriz adyacente
{
	cout << "Matriz Adyacente(Grafo):\n";
	for (const auto& row : graph) 
	{
		for (int val : row) 
		{
			cout << val << " ";
		}
		cout << '\n';
	}
}
//Ejercicio_3
void Grafo::isAdyacent(vector<vector<int>>& graph)//funcion para saber casi es adyacente
{
	int x,y; //vertices a ingresar
	cout<<"Ingrese el valor de el primer vertice y el segundo para buscar puntos adyacentes"<<endl;
	
	cout<<"Ingrese el valor del primer vertice"<<endl;
	while (!(std::cin >> x)) //validar entradas
	{
        cout << "Entrada invalida. Intente nuevamente: "; 
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	
	cout<<"Ingrese el valor del segundo vertice"<<endl;
	while (!(std::cin >> y)) //validar entradas
	{
        cout << "Entrada invalida. Intente nuevamente: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	
	while(x<-1 || y>8 || x>8 || y<-1) //metodo para validar de que los vertices pertenecen al tamaño del grafo
	{
		cout<<"Datos Erroneos, reingrese los datos"<<endl;
		
		cout<<"Reingrese el valor del primer vertice"<<endl;
		while (!(std::cin >> x)) //validar entradas
		{
	        cout << "Entrada invalida. Intente nuevamente: ";
	        cin.clear();
	        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    }
		
		cout<<"Reingrese el valor del segundo vertice"<<endl;
		while (!(std::cin >> y)) //validar entradas
		{
	        cout << "Entrada invalida. Intente nuevamente: ";
	        cin.clear();
	        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    }	
	}
		
	if(graph[x][y]==1 && graph[y][x]==1) // si se detecta un 1 entre dos vertices, entonces son adyacentes
	{
		cout<<"Los puntos son adyacentes"<<endl;
	}
	else                               //en caso de que no, se dira con un mensaje
	{
		cout<<"No son adyacentes"<<endl;
	}
}
 
 //Ejercicio_4
 bool Grafo::ExisteCamino(const vector<vector<int>>& graph, int init, int end) //funcion para confirmar casi existe un camino entre vertices
 {
	int numVertices = graph.size();            //se le saca el tamaño al grafo para detectar la cantidad de vertices
    vector<bool> visited(numVertices, false); //se crea un vector que valida casi un vertice ya fue visitado
	vector<int> stack;                       //se crea una pila para almacenar los vertices ya visitados
	
	stack.push_back(init);					//se almacenan los vertices visitados al final
	visited[init] = true;					
	
	while(!stack.empty())				  //si la pila no esta vacia se accede al ultimo elemento de esta
	{									 //y se saca en caso de encontrar un vertice  
		int current = stack.back();
		stack.pop_back();
		
		if(current == end)			 //verifica que el vertice actual tenga una arista que conecte al vertice de destino 
		{							//de ser el caso retorna verdadero
			return true;
		}
		
		for(int vecino = 0; vecino < numVertices ;vecino++) //arreglo que busca entre el grafo los vertices que contengan una arista
		{												   //que los una, asegurandose de no pasar por el mismo vertice					
			if(graph[current][vecino] && !visited[vecino])
			{
				stack.push_back(vecino);
				visited[vecino] = true;
			}
		}
	}
	return false;
    
 }
 
 //Ejercicio_5
 void Grafo::agregarArista(int origen, int destino) //funcion para crear una arista dirigida al grafo
 {
	lista_Ady[origen].push_back(destino); //se agregan vertices a una lista adyacente
 }
 
 //Ejercicio_5
 void Grafo::imprimirGrafoDirigido() //funcion para imprimir el grafo dirigido
 {
	for (int i = 0; i < vertices; ++i) //arreglo que imprime el grafo dirigido en forma de lista adyacente
	{
        cout << "Nodo " << i << " -> ";
        for (int v : lista_Ady[i]) 
		{
            cout << v << " ";
        }
        cout << endl;
    }
 }
//Ejercicio_6
bool Grafo::busquedaCiclo(int node, vector<bool>& visited, vector<bool>& stack) //funcion que realiza una busqueda en profundidad de los nodos que contengan un ciclo
{
	visited[node] = true; 				 //verificacion en caso de que un vertice ya se visito		
    stack[node] = true;					//verificacion de la existencia de la pila en la lista adyacente
		for (int v : lista_Ady[node])  //arreglo que busca un vertice en la lista adyacente, para saber si es ciclico
		{							 
            if (!visited[v]) 		 //se verifica si es que ya se visito y se almacena en una pila en caso de ser ciclico
			{
                if (busquedaCiclo(v, visited, stack)) 
				{
                    return true;
                }
            } 
			else if (stack[v])  
			{
                return true;
            }
        }

        stack[node] = false;

        return false;
}

//Ejercicio_6
bool Grafo::esCiclico() //funcion para determinar si un grafo es ciclico
{
	vector<bool> visited(vertices, false); 	  //vector que se encarga de almacenar la cantidad de vertices ya visitados
    vector<bool> stack(vertices, false);  	 //pila para almacenar los vertices visitados

        for (int i = 0; i < vertices; i++) //arreglo que se encarga de buscar vertices que sean ciclicos
		{
            if (busquedaCiclo(i, visited, stack)) 
			{
                return true;
            }
        }

        return false;
}
//Ejercicio_7
void Grafo::eliminarVertice(int vertice)//funcion que permite eliminar uno o mas vertices para crear subgrafos
{
	lista_Ady.erase(lista_Ady.begin() + vertice); //eliminacion de vertices de la lista de adyacencia
    vertices--;
    for (auto& lista : lista_Ady)  				//arreglo que ajusta los indices de los vertices restantes
	{
        for (int i = 0; i < lista.size(); i++) 
		{
            if (lista[i] > vertice) 
			{
                lista[i]--;
            }
        }
    }
}

int main() 
{
	int V = 8; // numero de vertices
	int A = 0; //numero de aristas
	cout << "numero de vertices: "<<V<<endl;
	cout << "numero de aristas: " <<A<<endl; 
	//cin >> V;
	
	// Create an empty adjacency matrix
	vector<vector<int>> graph(V, vector<int>(V, A));
	//Ejercicio_1	
	//introduciendo los vertices y aristas a mano
	//A
	graph[0][1] = 1;
	graph[0][2] = 1;
	//B
	graph[1][0] = 1;
	graph[1][3] = 1;
	graph[1][4] = 1;
	graph[1][5] = 1;
	//C
	graph[2][0] = 1;
	graph[2][3] = 1;
	graph[2][5] = 1;
	graph[2][6] = 1;
	//D
	graph[3][1] = 1;
	graph[3][2] = 1;
	graph[3][4] = 1;
	//E
	graph[4][1] = 1;
	graph[4][3] = 1;
	graph[4][5] = 1;
	graph[4][7] = 1;
	//F
	graph[5][1] = 1;
	graph[5][2] = 1;
	graph[5][4] = 1;
	graph[5][6] = 1;
	graph[5][7] = 1;
	//G
	graph[6][2] = 1;
	graph[6][5] = 1;
	graph[6][7] = 1;
	//H
	graph[7][4] = 1;
	graph[7][5] = 1;
	graph[7][6] = 1;
	
	cout<<endl;
	
	//Ejercicio_2
	cout<<"Ejercicio_2"<<endl;	
	Grafo g;
	g.printGraph(graph); //imprimir la matriz adyacente
	
	cout<<endl;
	
	//Ejercicio_3
	cout<<"Ejercicio_3"<<endl;	
	g.isAdyacent(graph);
	
	cout<<endl;
	
	//Ejercicio_4
	cout<<"Ejercicio_4"<<endl;	
	int init, end; //variables para definir el vertice de inicio y final en cual buscar una arista
	
	cout << "Ingrese el vertice de inicio: "<<endl;
    while (!(std::cin >> init)) //validar entradas
	{
	    cout << "Entrada invalida. Intente nuevamente: ";
	    cin.clear();
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
    cout << "Ingrese el vertice de destino: "<<endl;
  	while (!(std::cin >> end)) //validar entradas
	{
		cout << "Entrada invalida. Intente nuevamente: ";
	    cin.clear();
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	bool existe_camino = g.ExisteCamino(graph,init,end);
	
	if(existe_camino)
	{
		cout << "Existe un camino entre el vertice " << init << " y el vertice " << end << endl;
	}
	else
	{
		cout << "No existe un camino entre el vertice " << init << " y el vertice " << end << endl;
	}
	
	cout<<endl;
	
	//Ejercicio_5
	cout<<"Ejercicio_5"<<endl;	
	Grafo grafoDirigido(V); //creando un nuevo grafo que servira para convertirlo a dirigido
	//añadiendo las aristas que apuntan a los vertices
	//A
	grafoDirigido.agregarArista(0,1); 
	grafoDirigido.agregarArista(0,2); 
	//B
	grafoDirigido.agregarArista(1,0); 
	grafoDirigido.agregarArista(1,3);
	grafoDirigido.agregarArista(1,4);
	grafoDirigido.agregarArista(1,5);
	//C
	grafoDirigido.agregarArista(2,0); 
	grafoDirigido.agregarArista(2,3);
	grafoDirigido.agregarArista(2,5);
	grafoDirigido.agregarArista(2,6);   
	//D
	grafoDirigido.agregarArista(3,1); 
	grafoDirigido.agregarArista(3,2);
	grafoDirigido.agregarArista(3,4); 
	//E
	grafoDirigido.agregarArista(4,1);
	grafoDirigido.agregarArista(4,3);
	grafoDirigido.agregarArista(4,5);
	grafoDirigido.agregarArista(4,7);
	//F
	grafoDirigido.agregarArista(5,1);
	grafoDirigido.agregarArista(5,2);
	grafoDirigido.agregarArista(5,4);
	grafoDirigido.agregarArista(5,6);
	grafoDirigido.agregarArista(5,7);
	//G
	grafoDirigido.agregarArista(6,2);
	grafoDirigido.agregarArista(6,5);
	grafoDirigido.agregarArista(6,7);
	//H
	grafoDirigido.agregarArista(7,4);
	grafoDirigido.agregarArista(7,5);
	grafoDirigido.agregarArista(7,6);
	
	cout<<"Grafo Dirigido:"<<endl;	
	grafoDirigido.imprimirGrafoDirigido(); //imprimir el grafo dirigido
	
	cout<<endl;
	
	//Ejercicio_6
	cout<<"Ejercicio_6"<<endl;	
	Grafo grafociclico(V); //creando un nuevo grafo que servira para convertirlo a dirigido
	
	//añadiendo las aristas que apuntan a los vertices
	grafociclico.agregarArista(0, 1);
    grafociclico.agregarArista(1, 2);
    grafociclico.agregarArista(2, 3);
    grafociclico.agregarArista(3, 4); 
    grafociclico.agregarArista(4, 5);
    grafociclico.agregarArista(5, 6);
    grafociclico.agregarArista(6, 7);
    grafociclico.agregarArista(7, 1); // Ciclo: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 1
    
    cout<<"Grafo Ciclico:"<<endl;	
    grafociclico.imprimirGrafoDirigido();
    
    //determinando si el grafo contiene ciclos
    if(grafociclico.esCiclico())
    {
    	cout << "El grafo contiene un ciclo." << endl;
	}
    else 
	{
        cout << "El grafo no contiene ciclos." << endl;
    }
    
	cout<<endl;
    
    //Ejercicio_7
    cout<<"Ejercicio_7"<<endl;	
    Grafo grafoDirigido2(V); //creando un nuevo grafo que servira para convertirlo a dirigido
    
	//añadiendo las aristas que apuntan a los vertices
	grafoDirigido2.agregarArista(0,1); 
	grafoDirigido2.agregarArista(1,2); 
	grafoDirigido2.agregarArista(1,3); 
    grafoDirigido2.agregarArista(2,3); 
    grafoDirigido2.agregarArista(3,4);
	grafoDirigido2.agregarArista(4,2);
	grafoDirigido2.agregarArista(4,5);  
    grafoDirigido2.agregarArista(5,4);  
    grafoDirigido2.agregarArista(6,1);
	grafoDirigido2.agregarArista(7,0);
	    
    cout<<"Grafo Original:" << endl;
    grafoDirigido2.imprimirGrafoDirigido();
    
    int eliminarvertice; //variable para eliminar un vertice
    cout<<"indique el vertice que quiere eliminar"<<endl;
    
    while (!(std::cin >> eliminarvertice)) //validar entradas
	{
	    cout << "Entrada invalida. Intente nuevamente: ";
	    cin.clear();
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
    while(eliminarvertice<-1 || eliminarvertice>8) //metodo para validar de que los vertices pertenecen al tamaño del grafo
	{
		cout<<"Dato Erroneo, reingrese el dato"<<endl;
		
		cout<<"Reingrese el vertice que quiere eliminar"<<endl;
		while (!(std::cin >> eliminarvertice)) //validar entradas
		{
	        cout << "Entrada invalida. Intente nuevamente: ";
	        cin.clear();
	        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    }
	}
	grafoDirigido2.eliminarVertice(eliminarvertice);
	cout << endl << "Grafo despues de eliminar el vertice " << eliminarvertice << ":" << endl;
    grafoDirigido2.imprimirGrafoDirigido();
    
	return 0;
}

