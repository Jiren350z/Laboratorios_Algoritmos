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

//funcion para sacar promedio
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
    cout <<"suma del total de numeros y los numeros ingresados:"<<values << endl;
    avg = values/totalNumbers;
    cout<<"Promedio AVG:" << std::setprecision(10)<< avg << endl;
    
}

int main()
{
	//ejercicio_1
	cout<<"Ejercicio_1:"<<endl;
    getIntegerandInformation();	  
	//ejercicio_2
	cout<<"Ejercicio_2:"<<endl;
    AVGCalculator();  
    return 0;
}

