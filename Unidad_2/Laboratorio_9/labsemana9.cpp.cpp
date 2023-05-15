#include <iostream>
#include <vector>
using namespace std;

//ejercicio_1
class  Rectangle
{
	private:
		double largo_; //atributos
		double ancho_; //atributos
	public:
		Rectangle(); //constructor por defecto
		Rectangle(double largo, double ancho); //constructor por parametros
		~Rectangle(); //destructor	
		
		 void setLargo(double largo); //metodo set largo
		 void setAncho(double ancho); //metodo set ancho
		 double getLargo(); //metodo get largo
		 double getAncho(); //metodo get ancho
		 double calcularArea(); //declaracion de metodo
};
//ejercicio_1
Rectangle::Rectangle() //constructor por defecto
{
	largo_=0;
	ancho_=0;
	cout<<"constructor por defecto"<<endl;
}
//ejercicio_1
Rectangle::Rectangle(double largo, double ancho) //constructor por parametros
{
	largo_= largo;
	ancho_= ancho;
	cout<<"constructor por parametros"<<endl;
}
//ejercicio_1
Rectangle::~Rectangle() //destructor
{
	cout << "destructor" << endl;
}
//ejercicio_1
void Rectangle::setLargo(double largo) //metodo set para tomar los valores del largo
{
	largo_= largo;	
}
//ejercicio_1
void Rectangle::setAncho(double ancho) //metodo set para tomar los valores del ancho
{
	ancho_= ancho;
}
//ejercicio_1
double Rectangle::getLargo() //get del valor del largo
{
	return largo_;
}
//ejercicio_1
double Rectangle::getAncho() //get del valor del ancho
{
	return ancho_;
}	
//ejercicio_1
double Rectangle::calcularArea()
{
	return largo_*ancho_;
}
//ejercicio_2
class Point
{
	private:
		double x_; //atributos
		double y_; //atributos
	public:
		Point(); //constructor por defecto
		Point(double x, double y); //constructor por parametros
		~Point(); //destructor	
		
		void setCoordenadaX(double x); //metodo set
		void setCoordenadaY(double y); //metodo set
		double getCoordenadaX(); //metodo get
		double getCoordenadaY(); //metodo get
		void mover(double dx, double dy); //declaracion de metodo	
};
//ejercicio_2
Point::Point() //constructor por defecto
{
	x_=0;
	y_=0;
	cout<<"constructor por defecto"<<endl;
}
//ejercicio_2
Point::Point(double x, double y) //constructor por parametros
{
	x_= x;
	y_= y;	
	cout<<"constructor por parametros"<<endl;
}
//ejercicio_2
Point::~Point() //destructor
{
	cout << "destructor" << endl;
}
//ejercicio_2
void Point::setCoordenadaX(double x) //metodo set coordenada x
{
	x_= x;
}
//ejercicio_2
void Point::setCoordenadaY(double y) //metodo set coordenada y
{
	y_= y;
}
//ejercicio_2
double Point::getCoordenadaX() //metodo get coordenada x
{
	return x_;
}
//ejercicio_2
double Point::getCoordenadaY() //metodo get coordenada y
{
	return y_;
}
//ejercicio_2
void Point::mover(double dx, double dy)
{
	x_+= dx;
	y_+= dy;
}
//ejercicio_4
class Node
{
	public:
		int data; //atributo
		Node* next; //puntero al siguiente nodo
		Node(int val); //metodo de asignar un valor a la data
};
class LinkedList
{
	private:
		Node* head; //puntero apuntando a la cabeza
	public:
		LinkedList(); //constructor por defecto			
		LinkedList(int val); //constructor por parametros
		void insertNode(int pos, int val); //metodo para insertar un nodo en una posicion especifica 
 		void addNode(int val); //metodo para añadir un nuevo nodo a la lista
		void PrintNode(); // metodo para imprimir la lista
		void deleteNode(int val); //metodo para eliminar un valor de la lista 
		int searchNode(int val); //metodo para buscar un elemento en la lista 
		void setNode(int pos, int val); //metodo para modificar el valor de un nodo de una ubicacion especifica
		int getNode(int pos); //metodo para obtener el valor de un nodo en una posicion especifica
		 	
};
//ejercicio_4
Node::Node(int val) //constructor por parametros	
{
	data = val;
	next = NULL;
}
//ejercicio_4
LinkedList::LinkedList() //constructor por defecto		
{
	head = NULL;
}
//ejercicio_4
LinkedList::LinkedList(int val) //constructor por parametros
{
	head = new Node(val);
}
//ejercicio_4
void LinkedList::insertNode(int pos, int val) //metodo para insertar un nodo en una posicion especifica
{
	Node* newNode = new Node(val);

    if (pos == 0) 
	{
        newNode->next = head;
        head = newNode;
    } 
	else 
	{
        Node* current = head;
        int currentPos = 0;

        while (current != NULL && currentPos < pos - 1) 
		{
            current = current->next;
            currentPos++;
        }

        if (current != NULL) 
		{
            newNode->next = current->next;
            current->next = newNode;
        } 
		else
		{
            cout << "La posicion especificada no existe" <<endl;
        }
    }
}
//ejercicio_4
void LinkedList::addNode(int val) //metodo para agregar un valor nuevo a la lista
{
	Node* newNode = new Node(val);
	
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		Node* current = head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next = newNode;
	}
}
//ejercicio_4
void LinkedList::PrintNode() // metodo para imprimir la lista
{
	Node* current = head;
    while (current != NULL) 
	{
        cout << current->data << " ";
        current = current->next;
    }
	cout<<endl;	
}
//ejercicio_4
void LinkedList::deleteNode(int val) //metodo para eliminar un valor de la lista
{
	Node* current = head;
    Node* prev = NULL;
	
	while (current != NULL && current->data != val) 
	{
        prev = current;
        current = current->next;
    }
    if (current != NULL) 
	{
        if (prev == NULL) 
		{
            head = current->next;
        } 
		else 
		{
            prev->next = current->next;
        }
         cout<<"valor: "<< current->data <<" eliminado"<<endl;
        delete current;
    } 
	else 
	{
    	cout << "El valor especificado no existe en la lista." <<endl;
    }
}
//ejercicio_4
int LinkedList::searchNode(int val) //metodo para buscar un elemento en la lista 
{
	Node* current = head;
    int pos = 0;
	
	while (current != NULL && current->data != val) 
	{
        current = current->next;
        pos++;
    }
	if (current != NULL) 
	{
        return pos;
    } 
	else
	{
		cout << "La posicion especificada no existe" <<endl;
        return -1; 
    }
}
//ejercicio_4
void LinkedList::setNode(int pos, int val) //metodo para modificar el valor de un nodo de una ubicacion especifica
{
	Node* current = head;
    int currentPos = 0;

    while (current != NULL && currentPos < pos) 
	{
        current = current->next;
        currentPos++;
    }
    if (current != NULL) 
	{
       current->data = val;
    } 
	else 
	{
        cout << "La posicion especificada no existe" <<endl;
    }	
}
//ejercicio_4
int LinkedList::getNode(int pos)//metodo para obtener el valor de un nodo en una posicion especifica
{
	Node* current = head;
    int currentPos = 0;

    while (current != NULL && currentPos < pos) 
	{
        current = current->next;
        currentPos++;
    }
    if (current != NULL) 
	{
        return current->data;
    } 
	else 
	{
        cout << "La posicion especificada no existe" <<endl;
        return -1; 
    }
}
//ejercicio_5
struct TreeNode
{
	int data;
    TreeNode* left;
    TreeNode* right;
	
	// Constructor
    TreeNode(int value): data(value), left(NULL), right(NULL) {}
		
};
//ejercicio_5
class BinaryTree 
{
	private:
	    TreeNode* root;
	
	public:
		
		BinaryTree(); //constructor por defecto
		
		void setRoot(TreeNode* node); // Método para establecer la raíz del árbol
		TreeNode* getRoot(); // Método para obtener la raíz del árbol
		void insert(int value); // Método para insertar un elemento en el árbol
		void printTree(TreeNode* node); // Método para imprimir el árbol en orden
		bool search(TreeNode* node, int value); // Método para buscar un elemento en el árbol
};

//ejercicio_5
BinaryTree::BinaryTree() : root(NULL) {} // Constructor por defecto

//ejercicio_5
void BinaryTree::setRoot(TreeNode* node) // Método para establecer la raíz del árbol
{
	root = node;
}
//ejercicio_5
TreeNode* BinaryTree::getRoot() // Método para obtener la raíz del árbol
{
	return root;
}
//ejercicio_5
void BinaryTree::insert(int value) // Método para insertar un elemento en el árbol
{
	TreeNode* newNode = new TreeNode(value);
	if (root == NULL) 
	{
	    root = newNode;
	} 
	else 
	{
	    TreeNode* current = root;
	    TreeNode* parent;
		while (true) 
		{
	        parent = current;
			if (value < current->data) 
			{
	            current = current->left;
				if (current == NULL) 
				{
	                parent->left = newNode;
	                break;
	            }
	        } 
			else 
			{
	            current = current->right;
				if (current == NULL) 
				{
	                parent->right = newNode;
	                break;
	            }
	        }
	    }
	}
}
//ejercicio_5
void BinaryTree::printTree(TreeNode* node) // Método para imprimir el árbol en orden
{
	if (node != NULL) 
	{
	    cout << node->data << " ";
	    printTree(node->left);
	    printTree(node->right);
	}
}
//ejercicio_5
bool BinaryTree::search(TreeNode* node, int value) // Método para buscar un elemento en el árbol
{
	if (node == NULL) 
	{
	    return false;
	} 
	else if (node->data == value) 
	{
	    return true;
	} 
	else if (value < node->data) 
	{
	    return search(node->left, value);
	} 
	else 
	{
	    return search(node->right, value);
	}
}


int main()
{
	double l;
	double a;
	double area;
	//ejercicio_1
	cout<<"Ejercicio_1"<<endl;
	cout<<"ingrese el largo del rectangulo"<<endl;
	cin>>l;
	cout<<"ingrese el ancho del rectangulo"<<endl;
	cin>>a;
	Rectangle rec1(l,a); 
	cout<<"el largo es:"<<rec1.getLargo() <<endl;
	cout<<"el ancho es:"<<rec1.getAncho() <<endl;
	area = rec1.calcularArea();
	std::cout<<"El Area del Rectangulo es:" << area << "cm^2" <<std::endl;
	//ejercicio_2
	double dx;
	double dy;
	double x;
	double y;
	double coordenadax;
	double coordenaday;
	cout<<"Ejercicio_2"<<endl;
	cout<<"ingrese coordenada x"<<endl;
	cin>>x;
	cout<<"ingrese coordenada y"<<endl;
	cin>>y;
	Point p1(x,y);
	cout<<"la coordenada x es:"<<p1.getCoordenadaX() <<endl;
	cout<<"la coordenada y es:"<<p1.getCoordenadaY() <<endl;
	cout<<"ingrese el dx"<<endl;
	cin>>dx;
	cout<<"ingrese el dy"<<endl; 
	cin>>dy;
	p1.mover(dx,dy);
	cout<<"la nueva coordenada x es:"<<p1.getCoordenadaX() <<endl;
	cout<<"la nueva coordenada y es:"<<p1.getCoordenadaY() <<endl;
	//ejercicio_3
	cout<<"Ejercicio_3"<<endl;
	vector<Point> polygon;
	
	//agregacion de puntos
	polygon.push_back(Point(0.0, 0.0));
	polygon.push_back(Point(0.0, 1.0));
	polygon.push_back(Point(1.0, 1.0));
	polygon.push_back(Point(1.0, 0.0));
	polygon.push_back(Point(1,2));
	polygon.push_back(Point(3,4));
	
	//moviendo los vectores	
	polygon[0].mover(0.5, 0.5);
	polygon[1].mover(0.5, 0.5);
	polygon[2].mover(0.5, 0.5);
	polygon[3].mover(0.5, 0.5);
	polygon[4].mover(1, 0.5);
	polygon[5].mover(0.5, 3);
	
	//imprimir coordenadas 
	for(unsigned int i = 0; i < polygon.size(); i++)
	{
		cout<< "Punto:" << i << "(" << polygon[i].getCoordenadaX() << ", " << polygon[i].getCoordenadaY() << ")" <<endl;
	}
	//ejercicio_4
	cout<<"Ejercicio_4"<<endl;
	int valor;
	int op;
	int pos;
	int val;
	LinkedList list;
	while(op!=7)
	{
		cout<<"1: Ingresar un elemento a la lista enlazada"<<endl;
		cout<<"2: Imprimir la lista enlazada"<<endl;
		cout<<"3: Modificar un valor de una posicion especifica"<<endl;
		cout<<"4: Insertar un nuevo elemento en una posicion especifica"<<endl;
		cout<<"5: Buscar un elemento en la lista"<<endl;
		cout<<"6: Eliminar un elemento en la lista"<<endl;
		cout<<"7: Salir"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"Ingrese el numero que quiera ingresar a la lista de datos enlazada"<<endl;
				cin>>valor;
				list.addNode(valor);
			break;
			
			case 2:
				cout<<"Lista enlazada:"<<endl;
				list.PrintNode();
			break;
			
			case 3:
				
				cout<<"indique la posicion de la lista enlazada que desea modificar"<<endl;
				cin>>pos;
				cout<<"ingrese el valor que se va a cambiar"<<endl;
				cin>>val;
				list.setNode(pos,val);
				cout<<"Valor nuevo en la posicion indicada:" <<list.getNode(pos)<<endl;	
			break;
			
			case 4:
				cout<<"indique la posicion de la lista enlazada en el cual desea insertar un valor"<<endl;
				cin>>pos;
				cout<<"ingrese el valor que se va a insertar"<<endl;
				cin>>val;
				list.insertNode(pos,val);	
			break;
			
			case 5:
				cout<<"Ingrese el valor a buscar"<<endl;
				cin>>val;
				//list.searchNode(val);
				cout<<"el valor: "<< val << "se encuentra en la posicion:" <<list.searchNode(val)<<endl;
			break;
			
			case 6:
				cout<<"Ingrese el valor a eliminar"<<endl;
				cin>>val;
				list.deleteNode(val);
			break;
			
			case 7:
				cout<<"Saliendo..."<<endl;
			break;	
		}
	}
	//ejercicio_5
	cout<<"Ejercicio_5"<<endl;
	int arval;
	int arbuscar;
	BinaryTree Tree;
	while(op!=4)
	{
		cout<<"1: Insertar un elemento al arbol binario"<<endl;
		cout<<"2: Imprimir el arbol binario"<<endl;
		cout<<"3: Buscar un elemento en el arbol"<<endl;
		cout<<"4: Salir"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"Ingrese el numero que quiera insertar al arbol binario"<<endl;
				cin>>arval;
				Tree.insert(arval);
			break;
			
			case 2:
				cout<<"Arbol Binario:";
				Tree.printTree(Tree.getRoot());
				cout<<endl;
			break;
			
			case 3:
				cout<<"Ingrese el valor a buscar en el arbol"<<endl;
				cin>>arbuscar;
				if(Tree.search(Tree.getRoot(), arbuscar))
				{
					cout << "El elemento " << arbuscar << " esta presente en el arbol." << endl;
				}
				else
				{
        			cout << "El elemento " << arbuscar << " no esta presente en el arbol." << endl;
    			}
				
			break;
				
			case 4:
				cout<<"Saliendo..."<<endl;
			break;	
		}
	}
	return 0;
}
