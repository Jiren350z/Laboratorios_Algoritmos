#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

//declaracion de estructura
struct Node {
int data;
Node* next;
};

//a�adiendo un nuevo elemento a la lista
void addNewNode(int value, Node** head)
{
    //lista
    Node* newNode = new Node;
    newNode->data=value;
    newNode->next=*head;
    *head=newNode;
}

//funcion para imprimir un numero y un string ingresado por teclado
void getIntegerandInformation()
{
    int number=0;
    string data;
    cout<<"que numero desea ingresar?:";
    cin >> number;
    cout<<"que string desea ingresar?:";
    cin >>data;
    cout<<"el numero es: "<<number << " y el String es: "<<data << endl;
}
//funcion para calcular el promedio
void AVGCalculator()
{
    int values=0;
    double totalNumbers;
    int count=0;
    int tempValues;
    double avg;
    cout<<"Cuantos numeros desea ingresar:?";
    cin>>totalNumbers;
    for(count = 0; count<totalNumbers;count++)
    {
        cout<<"ingrese un numero:";
        cin>> tempValues;
        values = values + tempValues;
    }
    cout <<"suma del total de numeros ingresados:"<<values << endl;
    avg = values/totalNumbers;
    cout<<"Promedio Total:" << std::setprecision(10)<< avg << endl;
    
}
//funcion para sacar el tama�o de un string
int myStrLenFunction(string value)
{
    return(int)value.length();
}
//funcion calculadora de una lista de numeros
void Calculator(Node* node,double contador)
{
	int suma=0;
	int producto=1;
	double promedio;
	while(node != NULL)
	{
		suma = suma + node->data;
		producto = producto*node->data;
		node=node->next;
	}
	cout<<"Cantidad de numeros ingresados por el usuario:" <<contador<<endl;
	promedio=suma/contador;
	std::cout<<"Resultado Suma:"<<suma<<std::endl;
	std::cout<<"Resultado Producto:"<<producto<<std::endl;
	std::cout<<"Promedio:"<<std::setprecision(10)<<promedio<<std::endl;
}
//funcion para imprimir la lista de numeros
 void printlist(Node* node)
 {
 	while(node!=NULL)
 	{
 		std::cout<<node->data<<" ";
 		node = node->next;
	}
	std::cout<<std::endl;
 }
//funcion para el calculo de numeros factoriales
int factorial(int n)
{
	if(n==0)
	{
		return 1;	
	}
	else
	{
		return n*factorial(n-1);
	}	
} 

int main()
{
	//Node* node;
	Node* head=NULL;
	//variable para ingresar valores;
	int value=0;
	//variable para seleccionar opciones
	int k=0;
	//variable para decidir la cantidad de numeros a usar en la calculadora
	double cont=0;
	//indice del arreglo
	int i=0;
	//numero factorial
	int num=0,resultado=0;
	//ejercicio_1
	cout<<"Ejercicio_1:"<<endl;
    getIntegerandInformation();
    //ejercicio_2
    cout<<"Ejercicio_2:"<<endl;
    AVGCalculator();
    //ejercicio_3
    cout<<"Ejercicio_3:"<<endl;
    string val;
    cout<<"ingresa un string:";
    cin>>val;
    cout<< "longitud del string ingresado:" << myStrLenFunction(val) << endl;
	//ejercicio_4
	cout<<"Ejercicio_4:"<<endl;
	cout<<"Calculadora:"<<endl;
	cout<<"Cuantos numeros quiere ingresar:?"<<endl;
	cin>>cont;
	for(i=0;i<cont;i++)
	{
		std::cout<<"Ingrese el numero:"<<i+1<<":"<<endl;
		std::cin>>value;
		addNewNode(value,&head);
	}
	cout<<"Numeros ingresados"<<endl;
	printlist(head);
	Calculator(head,cont);
	//ejercicio_5
	cout<<"Ejercicio_5:"<<endl;
	cout<<"Ingrese un numero:"<<endl;
	cin>>num;
	resultado=factorial(num);
	std::cout<<"El Resultado del numero factorial "<<num<<" es: "<<resultado<<endl;	
    return 0;
}

