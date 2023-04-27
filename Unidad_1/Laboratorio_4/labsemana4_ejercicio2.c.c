#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
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
void addPatient(Patient arr[],int numPatient)
{
	int i=0;
	
		printf("introduzca nombre del paciente:\n");
		scanf("%s",&arr[numPatient].name);
		printf("introduzca edad del paciente: \n");
		scanf("%d",&arr[numPatient].age);
		printf("introduzca el numero de habitacion del paciente:\n");
		scanf("%d",&arr[numPatient].room);
		printf("introduzca la temperatura del paciente:\n");
		scanf("%f",&arr[numPatient].temperature);
		
}
//funcion encargada de imprimir los datos del paciente
void printPatients(Patient arr[], int numPatient)
{
	int i;
	for(i=0;i<numPatient;i++)
	{
		printf("----------------PACIENTE:%d---------------------\n",i+1);
		printf("Nombre del paciente:%s\n",arr[i].name);
		printf("Edad del paciente:%d\n",arr[i].age);
		printf("Numero de habitacion:%d\n",arr[i].room);
		printf("Temperatura del paciente:%.2f\n",arr[i].temperature);
	}
	printf("\n");
}

int main()
{
	int numPatient=0;
	int i=0;
	int k=0;
	Patient patients[max];
	printf("La cantidad maxima de pacientes es de 30\n");
		
	while(k!=3)
	{
		printf("Si desea ingresar un paciente marque 1\n");
		printf("Si desea saber la lista de pacientes marque 2\n");
		printf("Si desea salir marque 3\n");
		scanf("%d",&k);
		if(k==1)
		{
			if(numPatient<max)
			{
				addPatient(patients,numPatient);
				numPatient++;
			}
			else
			{
				printf("No es posible ingresar mas pacientes\n");
			}
		}
		else if(k==2)
		{
			printPatients(patients,numPatient);
		}
		else if(k==3)
		{
			exit(-1);
		}
	}
	return 0;
}


