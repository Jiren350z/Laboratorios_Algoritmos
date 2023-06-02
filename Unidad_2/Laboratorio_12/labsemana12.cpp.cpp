#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
const int INF = numeric_limits<int>::max();

//Ejercicio_1
void addEdge(map<int, vector<int>>& graph, const map<string, int>& myMap, const string& inicio, const string& destino) //codigo para añadir aristas entre vertices
{
    graph[myMap.at(inicio)].push_back(myMap.at(destino));
    graph[myMap.at(destino)].push_back(myMap.at(inicio));
}

//Ejercicio_1
void printGraph(const map<int, vector<int>>& graph, const map<string, int>& myMap) //funcion para imprimir el grafo
{
    int V = myMap.size(); 								//obtener el número de vertices en el grafo

    vector<vector<int>> matriz(V, vector<int>(V, 0)); // crear una matriz de adyacencia inicializada con ceros

    for (const auto& pair : graph)   				// recorrer todos los nodos y sus vecinos en el grafo
    {
        int recordIndex = pair.first; 

        for (int vecino : pair.second) 			// marcar la conexion entre cada vertice y sus vecinos en la matriz de adyacencia
        {
            int vecinoIndex = vecino;
            matriz[recordIndex][vecinoIndex] = 1;
            matriz[vecinoIndex][recordIndex] = 1;
        }
    }

    for (const auto& row : matriz) 		 // Imprimir la matriz
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << '\n';
    }
}

//Ejercicio_2
string getKeyByValue(const map<string, int>& myMap, int value) // Función auxiliar para obtener la clave a partir de un valor en el mapa
{
    for (const auto& pair : myMap)
    {
        if (pair.second == value)
        {
            return pair.first;
        }
    }
    return ""; // Si no se encuentra el valor retorna una cadena vacía
}

//Ejercicio_2
vector<string> existeCamino(const map<int, vector<int>>& graph, const map<string, int>& myMap, const string& inicio, const string& destino)
{

    set<int> visitado; 					// conjunto para mantener registro de los vertices visitados
    map<int, int> previo; 			   // mapa para almacenar el vertice previo en el camino más corto
    queue<int> q; 					  //cola para realizar el recorrido en amplitud

    q.push(myMap.at(inicio)); 		//inicializar el recorrido desde el vertice de inicio
    visitado.insert(myMap.at(inicio));

    while (!q.empty())
    {
        int record = q.front();
        q.pop();

        if (record == myMap.at(destino)) // si se llega al vertice de destino, se construye el camino y se retorna
        {
            vector<string> camino;
            while (record != myMap.at(inicio))
            {
                camino.push_back(getKeyByValue(myMap, record));
                record = previo[record];
            }
            camino.push_back(inicio);
            reverse(camino.begin(), camino.end());
            return camino;
        }

        for (int vecino : graph.at(record)) //explorando los vecinos del nodo actual
        {
            if (visitado.find(vecino) == visitado.end())
            {
                visitado.insert(vecino);
                previo[vecino] = record;
                q.push(vecino);
            }
        }
    }

    return vector<string>(); //si no se encuentra un camino se retorna un vector vacío
}

//Ejercicio_3
void Dijkstra(const map<int, vector<int>>& graph, const map<string, int>& myMap, const string& origen) //despliega la ruta mas corta entre el origen y los demas vertices
{
	int V = myMap.size();
    vector<int> dist(V, INF); 				 // distancias iniciales a todos los vértices desde el origen
    set<int> visitado; 				   		// conjunto de vertices visitados
    
    
    dist[myMap.at(origen)] = 0; 	 	 // Configurar la distancia del origen a sí mismo como 0
    
    while (visitado.size() < V)    	   // iterar hasta que se hayan visitado todos los nodos
    {
    	int u = -1;
        
        for (int i = 0; i < V; i++)// encontrar el vertice con la distancia mínima que aún no ha sido visitado
		{
            if (visitado.find(i) == visitado.end() && (u == -1 || dist[i] < dist[u])) 
			{
                u = i;
            }
        }
        visitado.insert(u); // Marcar el vertice actual como visitado

        
        for (int v : graph.at(u))  // actualizar las distancias de los vertices no visitados
		{
            int peso = 1; 
            if (dist[u] + peso < dist[v]) 
			{
                dist[v] = dist[u] + peso;
            }
        }
	}
	
    cout << "Distancias minimas desde el vertice " << origen << ":" << endl; // imprimir las distancias minimas desde el origen a todos los demas vertices
    for (const auto& pair : myMap) 
	{
        const string& key = pair.first;
        int value = pair.second;
        cout << "Vertice " << key << ": " << dist[value] << endl;
    }
	
}

//Ejercicio_4
void floydWarshall(const map<int, vector<int>>& graph, const map<string, int>& myMap) // función para aplicar el algoritmo de floyd-warshall y mostrar la matriz de distancias
{
	int V = myMap.size();
    vector<vector<int>> dist(V, vector<int>(V, INF));
    
    for (int i = 0; i < V; i++) //inicializando la matriz de distancias con los valores conocidos
	{
        dist[i][i] = 0;
        for (int vecino : graph.at(i)) 
		{
            dist[i][vecino] = 1;
        }
    }
    
    for (int k = 0; k < V; k++) //aplicando el algoritmo de floyd-warshall
	{
        for (int i = 0; i < V; i++) 
		{
            for (int j = 0; j < V; j++) 
			{
                if (dist[i][k] != INF && dist[k][j] != INF) 
				{
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    cout << "matriz de distancias:" << endl;
    for (int i = 0; i < V; i++) // imprimir la matriz de distancias
	{
        for (int j = 0; j < V; j++) 
		{
            if (dist[i][j] == INF) 
			{
                cout << "INF ";
            } 
			else 
			{
                cout << dist[i][j] << " ";
            }
        }
        cout << '\n';
    }
}

int main()
{
	
	int V=10;
	
	//Ejercicio_1
	//usando la libreria map para ordenar automaticamente los elementos segun sus claves
	cout<<"Ejercicio_1"<<endl;
	
	map<string,int> myMapStringInt;	
	myMapStringInt["A"] = 0;
	myMapStringInt["B"] = 1;
	myMapStringInt["C"] = 2;
	myMapStringInt["D"] = 3;
	myMapStringInt["E"] = 4;
	myMapStringInt["F"] = 5;
	myMapStringInt["G"] = 6;
	myMapStringInt["H"] = 7;
	myMapStringInt["I"] = 8;
	myMapStringInt["J"] = 9;

	// Range-based for loop
	for (const auto& pair : myMapStringInt) 
	{
		const string& key = pair.first;
		int value = pair.second;
		cout << "Letra: " << key << ", Valor: " << value << endl;
	}
	
	
	//se agregan las conexiones entre vertices
	map<int, vector<int>> graph;
	addEdge(graph, myMapStringInt, "A", "B");
	addEdge(graph, myMapStringInt, "A", "C");
	//B
	addEdge(graph, myMapStringInt, "B", "A");
	addEdge(graph, myMapStringInt, "B", "D");
	addEdge(graph, myMapStringInt, "B", "E");
	//C
	addEdge(graph, myMapStringInt, "C", "A");
	addEdge(graph, myMapStringInt, "C", "F");
	addEdge(graph, myMapStringInt, "C", "G");
	//D
	addEdge(graph, myMapStringInt, "D", "B");
	addEdge(graph, myMapStringInt, "D", "E");
	addEdge(graph, myMapStringInt, "D", "F");
	//E
	addEdge(graph, myMapStringInt, "E", "B");
	addEdge(graph, myMapStringInt, "E", "D");
	addEdge(graph, myMapStringInt, "E", "F");
	addEdge(graph, myMapStringInt, "E", "H");
	//F
	addEdge(graph, myMapStringInt, "F", "D");
	addEdge(graph, myMapStringInt, "F", "E");
	addEdge(graph, myMapStringInt, "F", "G");
	addEdge(graph, myMapStringInt, "F", "H");
	//G
	addEdge(graph, myMapStringInt, "G", "D");
	addEdge(graph, myMapStringInt, "G", "F");
	addEdge(graph, myMapStringInt, "G", "I");
	addEdge(graph, myMapStringInt, "G", "J");
	//H
	addEdge(graph, myMapStringInt, "H", "E");
	addEdge(graph, myMapStringInt, "H", "F");
	addEdge(graph, myMapStringInt, "H", "J");
	//I
	addEdge(graph, myMapStringInt, "I", "G");
	addEdge(graph, myMapStringInt, "I", "J");
	//J
	addEdge(graph, myMapStringInt, "J", "G");
	addEdge(graph, myMapStringInt, "J", "H");
	addEdge(graph, myMapStringInt, "J", "I");
	
	
	//imprimiendo la matriz con las conexiones
	printGraph(graph, myMapStringInt);
	
	cout<<endl;
	
	//Ejercicio_2
	cout<<"Ejercicio_2"<<endl;
	string vi;
	string vf;
	cout<<"indique el vertice de inicio y destino(la letra)"<<endl;
	
	// Bucle para validar las entradas
    bool entradasValidas = false;
	do
	{
		cout<<"indique el vertice de inicio(letras A-J): "<<endl;
		cin>>vi;
		cout<<"indique el vertice de final(letras A-J): "<<endl;
		cin>>vf;
		
		if (vi.length() == 1 && vf.length() == 1 && isupper(vi[0]) && isupper(vf[0]) && vi[0] >= 'A' && vi[0] <= 'J' && vf[0] >= 'A' && vf[0] <= 'J') 
		{
            entradasValidas = true;
        } 
		else 
		{
            cout << "Entradas invalidas deben ser letras mayusculas desde la 'A' hasta la 'J'" <<endl;
        }
		
	}while(!entradasValidas);
	
	vector<string> camino = existeCamino(graph, myMapStringInt,vi,vf);
	if(!camino.empty())
	{
		cout<<"Camino encontrado"<<endl;
		for(const string& record:camino)
		{
			cout<<record<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"No se encontro un camino entre vertices"<<endl;
	}
	
	cout<<endl;
	
	//Ejercicio_3
	cout<<"Ejercicio_3"<<endl;
	cout<<"Algoritmo de Dijkstra"<<endl;
	string origen;
	bool entradaval=false ;
	//validacion de entradas
	do
	{
		cout<<"indique el vertice de origen(letra)"<<endl;
		cin>>origen;
		if(!origen.empty() && !cin.fail())
		{
			entradaval = true;	
		}
		else
		{
			cout<<"Entrada Invalida, debe ser una cadena de texto no vacia"<<endl;
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while(!entradaval);
	
	cout<<"Implementando el Algoritmo de Dijkstra"<<endl;
	Dijkstra(graph,myMapStringInt,origen);

	cout<<endl;
	
	//Ejercicio_4
	cout<<"Ejercicio_4"<<endl;
	cout<<"Algoritmo de Floyd-Warshall"<<endl;	
	floydWarshall(graph, myMapStringInt); 
	
	return 0;
}
