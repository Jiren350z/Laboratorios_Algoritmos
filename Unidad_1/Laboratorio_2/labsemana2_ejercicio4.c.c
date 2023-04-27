#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100 //tamaño maximo de pacientes
#define umbral 7 //cantidad de dias

//funcion que se dedica a imprimir el numero de habitacion y la edad del paciente
void imprimir(int arr[], int varmax)
{
	int i;
	for(i=0; i<max && i<varmax;i++ )
	{
		printf("Habitacion: %d,Edad del Paciente: %d\n",i,arr[i]);
		
	}
	printf("\n");	
	printf("cantidad de pacientes:%d\n",i);
	
}
//funcion dedicada a imprimir la informacion
//imprime el numero de habitacion, la edad de los pacientes,
//los dias pasados, la temperatura en celsius y farenheit,
//se encarga de determinar si un paciente tuvo fiebre o no,
//cuenta los dias totales en los cuales el paciente tuvo fiebre y 
//el total de los grados celsius del paciente que tuvo fiebre
//ademas de determinar cual paciente tuvo fiebre durante 3 dias o mas,
//el promedio en celsius y farenheit de la temperatura de cada paciente,
//durante 7 dias y la cantidad de pacientes ingresados
void imprimir3(int arr[], float arr2[], int varmax)
{
	srand(time(NULL));
	int i;
	int j;
	float gradosf;
	int v=0;
	float f=0;
	float faren=0;
	float promedioC=0;
	float promedioF=0;
	int dias=0;
	float tempc=0;
	float tempf=0;
	for(i=0; i<max && i<varmax;i++ )
	{
		for(j=0;j<umbral;j++)
		{
		arr2[j]=rand()%10+30;
		printf("Habitacion: %d Edad del Paciente: %d\n",i,arr[i]);
		printf("Dia: %d Temperatura registrada: %f\n",j,arr2[j]);
		printf("Temperatura en Celsius:%f\n",arr2[j]);
		gradosf=(arr2[j]*9/5)+32;
		printf("Temperatura en Farenheit:%f\n",gradosf);
		if(arr2[j]>37.5)
			{
			printf("-ALERTA\n");	
			printf("-El paciente de la habitacion %d de %d anios tiene fiebre\n",i,arr[i]);
			printf("-En el dia %d con una temperatura de %f grados\n",j,arr2[j]);
			printf("Temperatura en Celsius:%f\n",arr2[j]);
			printf("Temperatura en Farenheit:%f\n",gradosf);
			v++;
			f=f+arr2[j];
			faren=faren+gradosf;
			}	
			printf("-----------------------------------------------\n");
			dias++;
			tempc=tempc+arr2[j];
			tempf=tempf+gradosf;
		}
		printf("-Cantidad de dia/s que el paciente de la habitacion %d tuvo fiebre: %d dia/s\n",i,v);
		printf("-Cantidad total de temperatura en celsius del paciente con fiebre de la habitacion %d: %f\n",i,f);
		printf("-Cantidad total de temperatura en farenheit del paciente con fiebre de la habitacion %d: %f\n",i,faren);
		if(v>=3)
		{
			printf("El Paciente de la habitacion %d ha estado teniendo fiebre durante %d dia/s\n",i,v);
		}
		v=0;
		f=0;
		faren=0;
		promedioC=tempc/dias;
		printf("-El Promedio en grados Celsius del paciente de la habitacion %d es: %f\n",i,promedioC);	
		promedioF=tempf/dias;
		printf("-El Promedio en grados Farenheit del paciente de la habitacion %d es: %f\n",i,promedioF);
		printf("-----------------------------------------------\n");
	}
	printf("-Cantidad de Pacientes:%d\n",i); 
}

//funcion que se dedica a definir el numero de habitacion y la edad del paciente
void definir(int obj, int arr[], int varmax)
{
	int i;
	
	for(i=0;i<varmax;i++)
	{
		printf("defina la edad del paciente %d del Internado\n ",i);
		scanf("%d",&obj);
		arr[i]=obj;
		printf("El paciente %d tiene %d anios\n",i,obj);
	}		
}
int main()
{
	//declaracion de variables
	int arr[max]={0};
	float arr2[max]={0};
	int varmax = 0;
	int obj=0;
	printf("Defina la cantidad de pacientes internados\n");
	scanf("%d",&varmax);
	imprimir(arr,varmax);
	definir(obj,arr,varmax);
	printf("-----------------------------------------------\n");
	printf("INFORMACION REGISTRADA\n");
	imprimir(arr,varmax);
	printf("-----------------------------------------------\n");
	printf("INFORMACION ACTUAL\n");
	printf("-----------------------------------------------\n");
	imprimir3(arr,arr2,varmax);
	return 0;
}

