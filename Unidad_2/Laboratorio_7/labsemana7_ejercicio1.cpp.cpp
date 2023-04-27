#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

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

int main()
{
	//ejercicio_1
	cout<<"Ejercicio_1:"<<endl;
    getIntegerandInformation();	    
    return 0;
}

