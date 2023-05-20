#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <limits>
#include<queue>
using namespace std;


struct Node { 	//definicion de la estructura nodo
int data; 	   //valor numerico asignado data
Node* left;   //puntero al nodo de la izquierda
Node* right; //puntero al nodo de la derecha
};



Node* createNode(int data)      //funcion para crear un nodo
{ 
	Node* newNode = new Node; //creacion de un nuevo nodo
	newNode->data = data;    //puntero que referencia al valor de la data
	newNode->left = NULL;   //se inicia el nodo izquierdo en null
	newNode->right = NULL; //se inicia el nodo derecho en null
	return newNode;       //se retorna el nodo creado
}

Node* insertNode(Node* root, int data) //metodo para insertar valores en el nodo
{
	if(root == NULL) 				 //si la raiz se encuentra nula se llena con el primer elemento ingresado
	{
		root = createNode(data);
	}
	else 						 //en caso de no ser nula se añadiran elementos a la izquierda en caso de ser menor que
	{    						//el dato de la raiz, caso contrario si eld ato es mayor se añadira a la derecha   
		
		if(data < root->data)
		{
			root->left = insertNode(root->left,data);
		}
		else
		{
			root->right=insertNode(root->right,data);
		}
	}
	
	return root; //se retorna la raiz del arbol
}

//ejercicio_2
void preOrder(Node* root) //funcion para imprimir en preorden
{						 //recibe un puntero a la raiz	
	if (root == NULL)   //si la raiz es nula se retorna a la funcion
	{	
		return;
	}
	cout << root->data << " ";	//se imprimen los valores recorriendo desde la raiz, pasando primero por las ramas izquierdas y despues las derechas 
	preOrder(root->left);	   //impresion de los valores la iquierda
	preOrder(root->right);    //impresion de valores de la derecha
}
//ejercicio_3
void inOrder(Node* root) //funcion para imprimir en orden
{
	if (root == NULL) 
	{	
		return;
	}
	
	inOrder(root->left); 		//impresion de valores de la izquierda	
	cout << root->data << " "; //se imprimen los valores recorriendo desde izquierda a derecha, sin tomar en cuenta el orden en el que se ingresaron o las ramas	
	inOrder(root->right); 	  //impresion de valores de la derecha
}
//ejercicio_4
void postOrder(Node* root) //funcion para imprimir en orden
{
	if (root == NULL) 
	{	
		return;
	}
	inOrder(root->left);         //impresion de valores de la izquierda	pero estos se imprimen en orden	
	postOrder(root->right);     //impresion de valores de la derecha
	cout << root->data << " "; //se imprimen despues para que recorra de izquierda a derecha, pero la cabeza	
}
//ejercicio_6
Node* DFS(Node* root, int val) 				//busqueda por profundidad
{
	if(root == NULL || root->data == val) //se retorna el valor del primer dato de la raiz, en caso de ser nulo o de que elmdato sea igual al del valor a buscar 
	{
		return root;
	}
	Node* left_result = DFS(root->left,val); //se busca el valor ingresador recorriendo toda la rama izquierda
	if(left_result != NULL) 				//posteriormente si el valor no es nulo retorna el valor del elemento buscado solo en caso de estar en la rama izquierda
	{
		return left_result;
	}
	Node* right_result = DFS(root->right, val); //se busca el valor ingresador recorriendo toda la rama derecha
	if(right_result != NULL) 					//posteriormente si el valor no es nulo retorna el valor del elemento buscado solo en caso de estar en la rama derecha
	{
		return right_result;
	}
	return NULL; //nulo si el valor no esta en el arbol
}
//ejercicio_7

Node* BFS(Node* root,int val) 		  //busqueda por profundidad
{
	queue<Node*> q; 				//se crea un nuevo nodo que se incluira en una cola de nodos
    q.push(root); 				   //se inserta la raiz del arbol en la cola
    while(!q.empty())             //si la cola no esta vacia se buscara por las ramas de izquierda a derecha entre ramas 
    {
    	Node* current = q.front(); // se obtiene el nodo actual de la parte frontal de la cola, posteriormente se elimina
    	q.pop();                   
    	if(current->data == val) //si el valor actual coincide con el elemento buscado se retornara el valor del elemento a buscar
    	{                          
    		return current;
		}
		if(current->left != NULL) 	//si el nodo actual tiene un hijo en la izquierda
		{                         
			q.push(current->left); //se añade el hijo izquierdo a la cola para que pueda explorar mas adelante 
		}
		if(current->right != NULL) 	  //si el nodo actual tiene un hijo en la derecha
		{
			q.push(current->right); //se añade el hijo izquierdo a la cola para que pueda explorar mas adelante 
		}
	}
	return NULL; //en caso de que el valor no se encuentre se retorna nulo
}

int main()
{
	//ejercicio_1
	Node* root = NULL; //puntero a la raiz nula
	Node* node1 = new Node(); //creando los valores manualmente
	node1->data = 1;
	Node* node2 = new Node();
	node2->data = 2;
	Node* node3 = new Node();
	node3->data = 3;
	Node* node4 = new Node();
	node4->data = 4;
	Node* node5 = new Node();
	node5->data = 5;
	Node* node6 = new Node();
	node6->data = 6;
	Node* node7 = new Node();
	node7->data = 7;
	
	//apuntando a los valores del arbol manualmente
	node1->left = node2;
	node1->right = node3;
	
	node2->left = node4;
	node2->right = node5;
	
	node3->left = node6;
	node3->right = node7;
	//valores finales del arbol apuntando a nulo
	node4->left = node4->right = node5->left = node5->right = node6->left = node6->right = node7->left = node7->right = NULL;
	
	//ejercicio_2
	cout<<"Ejercicio_2"<<endl;
	cout<<"Imprimir pre-Orden"<<endl;
	preOrder(node1); //funcion para imprimir en preorden de menor a mayor
	cout<<endl;
	//ejercicio_3
	cout<<"Ejercicio_3"<<endl;
	cout<<"Imprimir in-Orden"<<endl; 
	inOrder(node1); //funcion //funcion para imprimir en orden, desde: rama izquierda-raiz-rama derecha
	cout<<endl;
	//ejercicio_4
	cout<<"Ejercicio_4"<<endl;
	cout<<"Imprimir post-Orden"<<endl; 
	postOrder(node1); //funcion para imprimir en orden desde las ramas izquierda-derecha y posteriormente la raiz
	cout<<endl;
	//ejercicio_5
	cout<<"Ejercicio_5"<<endl;
	int Arreglo[10] = {21,18,6,9,10,7,19,15,12,5}; 	 //arreglo predefinido
	Node* arreglo = createNode(Arreglo[0]); 		//se crea un nuevo nodo en el cual se incluye el arreglo creado
	for(int i=1; i<10; i++) 					   //se usa un for para incluir los valores del arreglo en en arbol
	{
		insertNode(arreglo,Arreglo[i]);
	}
	cout<<"Imprimiendo Arreglo insertado en el Arbol"<<endl;
	inOrder(arreglo); 						  //se imprimen los valores del arbol en orden
	cout<<endl;
	//ejercicio_6
	cout<<"Ejercicio_6"<<endl;
	int buscar=0; //variable buscar
	
	//creando arbol binario para busqueda
	Node* Dfs = createNode(10);
    Dfs->left = createNode(12);
    Dfs->right = createNode(11);
    Dfs->left->left = createNode(8);
    Dfs->left->right = createNode(25);
    Dfs->right->left = createNode(54);
    Dfs->right->right = createNode(7);
	
	cout<<"arbol para buscar por profundidad"<<endl;
	preOrder(Dfs); //imprimir valores en preorden
	cout<<endl;
	cout<<"Que valor del arbol desea buscar?"<<endl;
	
    while (!(std::cin >> buscar)) //validar entradas
	{
        cout << "Entrada invalida. Intente nuevamente: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	cout << "Numero valido ingresado: " << buscar << std::endl;
	
	bool BP = DFS(Dfs,buscar); //buscar el valor
	
	if(BP) //mostrar el resultado de la busqueda por profundidad
	{
		cout<<"Valor: " << buscar << " Encontrado en el Arbol"<<endl;
	}
	else
	{
		cout<<"Valor: " <<buscar << " No se encuentra en el Arbol"<<endl;
	}
	
	//ejercicio_7
	cout<<"Ejercicio_7"<<endl;
	
	//creando arbol binario para busqueda
	Node* Bfs = createNode(13);
    Bfs->left = createNode(18);
    Bfs->right = createNode(2);
    Bfs->left->left = createNode(1);
    Bfs->left->right = createNode(33);
    Bfs->right->left = createNode(73);
    Bfs->right->right = createNode(7);
    
    cout<<"arbol para buscar por amplitud"<<endl;
	preOrder(Bfs); //imprimir valores en preorden
	cout<<endl;
	cout<<"Que valor del arbol desea buscar?"<<endl;
	
    while (!(std::cin >> buscar)) //validar entradas
	{
        cout << "Entrada invalida. Intente nuevamente: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	cout << "Numero valido ingresado: " << buscar << std::endl;
	
	bool BA = BFS(Bfs,buscar); //buscar el valor
	
	if(BA) //mostrar el resultado de la busqueda por profundidad
	{
		cout<<"Valor: " << buscar << " Encontrado en el Arbol"<<endl;
	}
	else
	{
		cout<<"Valor: " <<buscar << " No se encuentra en el Arbol"<<endl;
	}
	
	return 0;
}
