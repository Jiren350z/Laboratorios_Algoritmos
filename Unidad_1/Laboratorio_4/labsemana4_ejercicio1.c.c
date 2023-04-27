#include<stdio.h>
#include<stdlib.h>
#define max 5
//definicion de la estructura paciente
typedef struct patient
{
	char name[50];
	int age;
	int room;
	float temperature;
	struct patient *next;
}Patient;
//funcion encargada de añadir pacientes
void addPatient(Patient arr[])
{
	int i;
	for(i=0;i<max;i++)
	{
		printf("introduzca nombre del paciente %d\n",i+1);
		scanf("%s",&arr[i].name);
		printf("introduzca edad del paciente %d\n",i+1);
		scanf("%d",&arr[i].age);
		printf("introduzca el numero de habitacion del paciente %d\n",i+1);
		scanf("%d",&arr[i].room);
		printf("introduzca la temperatura del paciente %d\n",i+1);
		scanf("%f",&arr[i].temperature);
		
	}
}
//funcion encargada de imprimir los datos del paciente
void printPatients(Patient arr[])
{
	int i;
	for(i=0;i<max;i++)
	{
		printf("----------------PACIENTE:%d---------------------\n",i+1);
		printf("Nombre del paciente:%s\n",arr[i].name);
		printf("Edad del paciente:%d\n",arr[i].age);
		printf("Numero de habitacion:%d\n",arr[i].room);
		printf("Temperatura del paciente:%f\n",arr[i].temperature);
	}
}

int main()
{
	Patient patients[max];
	addPatient(patients);
	printPatients(patients);
	return 0;
}


