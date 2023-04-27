#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
#define tempmax 7
//definicion de la estructura paciente
typedef struct patient
{
	char name[50];
	int age;
	int room;
	float temperature[tempmax];
	struct patient *next;
}Patient;
//funcion encargada de añadir pacientes
void addPatient(Patient arr[],int numPatient)
{
	int i=0;
	
		printf("introduzca el nombre del paciente:\n");
		scanf("%s",&arr[numPatient].name);
		printf("introduzca la edad del paciente: \n");
		scanf("%d",&arr[numPatient].age);
		printf("introduzca el numero de habitacion del paciente:\n");
		scanf("%d",&arr[numPatient].room);
		//esto inicia la temperatura en 0 para que el programa no imprima basura en
		//la funcion imprimir
		for(i=0;i<tempmax;i++)
		{
			arr[numPatient].temperature[i]=0;
		}
}
//funcion que ingresa una temperatura a la vez de un paciente en especifico
void recordTemperature(Patient arr[],int temp)
{
	int i=0;
	for(i=0;i<tempmax;i++)
	{
		if((int)arr[temp].temperature[i] == 0)
		{
			printf("introduzca la temperatura del paciente:\n");
			scanf("%f",&arr[temp].temperature[i]);
			return;
		}
	}	
	printf("cantidad maxima de dias de temperatura registrada\n");
}
//funcion encargada de imprimir los datos del paciente
void printPatients(Patient arr[], int numPatient)
{
	int i=0,j=0;
	for(i=0;i<numPatient;i++)
	{
		printf("----------------PACIENTE:%d---------------------\n",i+1);
		printf("Nombre del paciente:%s\n",arr[i].name);
		printf("Edad del paciente:%d\n",arr[i].age);
		printf("Numero de habitacion:%d\n",arr[i].room);
		for(j=0;j<tempmax;j++)
		{
			if((int)arr[i].temperature[j] !=0)
			{
				printf("Temperatura del dia %d del paciente:%.2f\n",j+1,arr[i].temperature[j]);	
			}
		}	
		printf("\n");
	}
	
}

int main()
{
	int numPatient=0;
	int i=0;
	int j=0;
	int k=0;
	int p;
	int temp=0;
	Patient patients[max];
	printf("La cantidad maxima de pacientes es de 30\n");
	printf("la temperatura de cada paciente se debe monitorear durante 7 dias\n");
	printf("\n");	
	while(k!=4)
	{
		printf("Si desea ingresar un paciente marque 1\n");
		printf("Si desea saber la lista de pacientes marque 2\n");
		printf("Si desea agregar temperatura a un paciente marque 3\n");
		printf("Si desea salir del programa marque 4\n");
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
			printf("indique el numero del paciente al que le desea agregar temperatura:\n");
			scanf("%d",&p);
			p--;
			recordTemperature(patients,p);
			p=0;
		}
		else if(k==4)
		{
			exit(-1);
		}
	}

	
	return 0;
}


