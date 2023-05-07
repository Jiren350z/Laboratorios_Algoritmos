#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

//ejercicio_1
struct Node {
int data;
Node* left;
Node* right;
};

//ejercicio_1
Node* createNode(int data) 
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
//ejercicio_2
Node* insertNode(Node* root, int data)
{
	if(root == NULL)
	{
		root = createNode(data);
		cout<<root->data<<endl;
	}
	else 
	{
		
		if(data < root->data)
		{
			root->left = insertNode(root->left,data);
		}
		else
		{
			root->right=insertNode(root->right,data);
		}
	}
	
	return root;
}

//ejercicio_3
void printTree(Node* root) 
{
	if (root == NULL) 
	{	
		return;
	}
	cout << root->data << " ";	
	printTree(root->left);	
	printTree(root->right);
}

//ejercicio_4
bool search(Node* root, int data)
{
	if(root == NULL)
	{
		cout<<"No se encontro el numero:"<<data<<endl;
		return false;
	}
	if(root->data == data)
	{
		cout<<"Numero: " <<root->data<< " encontrado"<<endl;
		return true;
	}
	else
	{
		if(data <= root->data)
		{
			return search(root->left,data);
		}
		else
		{
			return search(root->right,data);
		}
	}
	
}

//ejercicio_5
Node* valorminimo(Node* root)
{
	if(root->left == NULL)
	{
		return root;
	}
	valorminimo(root->left);
}

//ejercicio_6
Node* valormaximo(Node* root)
{
	if(root->right == NULL)
	{
		return root;
	}
	valormaximo(root->right);
}

//ejercicio_7
Node* deleteNode(Node* root, int data)
{
	if(root == NULL)
	{
		cout<<"el arbol esta vacio"<<endl;
	}
	if(data < root->data)
	{
		root->left = deleteNode(root->left,data);
		//cout<<"numero izquierdo: " <<data<< " eliminado"<<endl;
	}
	else if(data > root->data)
	{
		root->right = deleteNode(root->right,data);
		//cout<<"numero derecho: " <<data<< " eliminado"<<endl;
	} 
	else
	{
		if(root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* next = root->right;
		while(next->left != NULL)
		{
			next = next->left;
		}
		root->data = next->data;
		root->right = deleteNode(root->right, next->data);
	}
	return root;
}




int main()
{
	Node* root = NULL;
	//ejercicio_1,2
	int number=0;
	int total=0;
	int op=0;
	int num=0;
	cout<<"Defina la cantidad total de elementos que se ingresaran en el arbol"<<endl;
	cin>>total;
	if(total > 100)
	{
		cout<<"El maximo de elementos que se pueden ingresar es 100"<<endl;
		return 0;
	}
	srand(time(0));
	cout<<"Elementos del arbol desde el primer ingresado(raiz) al ultimo"<<endl;
	for(int i = 0; i < total; i++)
	{
		number = 1 + (rand()%100);
		cout<< number << ", ";
		root = insertNode(root,number);
	}
	cout<<endl;
	//ejercicio_3
	cout<<"Impresion en orden desde el primer ingresado(raiz) hasta el ultimo ingresado "<<endl;
	printTree(root);
	//ejercicio_4
	cout<<endl;
	cout<<"Ingrese el numero que quiere buscar"<<endl;
	cin>>number;
	search(root,number);
	//ejercicio_5
	cout<<"Valor Minimo:"<<valorminimo(root)->data<<endl;
	//ejercicio_6
	cout<<"Valor Maximo:"<<valormaximo(root)->data<<endl;
	//ejercicio_7
	cout<<"Eliminar un elemento del arbol"<<endl;
	do
	{
		cout<<"1: Si quiere eliminar un elemento"<<endl;
		cout<<"2: Si no quiere hacer nada"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"ADVERTENCIA:Asegurese de que el primer elemento a eliminar no sea la raiz(primer elemento) del arbol"<<endl;
				cout<<"Indique el numero del elemento del arbol que quiere eliminar"<<endl;
				cin>>num;
				deleteNode(root,num);
				cout<<"Arbol tras la eliminacion"<<endl;
				printTree(root);
				cout<<endl;
				break;
			case 2:
				cout<<"Ha seleccionado salir"<<endl;
				break;
		}
	}while(op!=2);	
	
	return 0;
}
