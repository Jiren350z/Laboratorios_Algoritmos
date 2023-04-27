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
	int id;
	struct patient *next;
}Patient;
//funcion que crea al paciente haciendo referencia a la estructura paciente 
Patient* createPatient()
{
	int i=0;
	Patient *newPatient = (Patient*)malloc(sizeof(Patient));
	printf("introduzca el numero id del paciente\n");
	scanf("%d",&newPatient->id);
	printf("introduzca el nombre del paciente:\n");
	scanf("%s",&newPatient->name);
	printf("introduzca la edad del paciente: \n");
	scanf("%d",&newPatient->age);
	printf("introduzca el numero de habitacion del paciente:\n");
	scanf("%d",&newPatient->room);
	//for que inicia la temperatura en 0 para que la funcion imprimir no imprima basura
	for(i=0;i<tempmax;i++)
	{
		newPatient->temperature[i]=0;
	}
	newPatient->next=NULL;
	return newPatient;	
}
//funcion que va añadiendo pacientes y que toma la funcion create patient en el main para añadir
void addPatient(Patient **head, Patient *newPatient) 
{
	if (*head == NULL) 
	{
		*head = newPatient;
	} 
	else 
	{
		Patient *current = *head;
		while (current->next != NULL) 
		{
			current = current->next;
		}
		current->next = newPatient;
	}
}
//funcion encargada de imprimir los datos del paciente
void recordTemperature(Patient *head,char*nombre)
{
	int i=0;
	Patient* current= head;
	while(current!=NULL)
	{
		if (strcmp(current->name,nombre) == 0) 
		{
			for(i=0;i<tempmax;i++)
			{	
				printf("agregue la temperatura del dia %d del paciente\n",i+1);
				scanf("%f",&current->temperature[i]);
			}
			printf("Temperatura de %s agregada exitosamente\n",nombre);
			printf("\n");
    		return;
        }
        current = current->next;
	}
	printf("No se encontro al paciente %s.\n", nombre);
	printf("\n");
}
//funcion que imprime los datos de los pacientes
void printPatients(Patient *head)
{
	
	printf("----------------PACIENTES---------------------\n");
	Patient *current = head;
	while (current != NULL) 
	{
	int i=0;
	printf("Numero id del paciente:%d\n",current->id);
	printf("Nombre del paciente:%s\n",current->name);
	printf("Edad del paciente:%d\n",current->age);
	printf("Numero de habitacion:%d\n",current->room);
	for(i=0;i<tempmax;i++)
	{
		printf("Temperatura del dia %d del paciente:%.2f\n",i+1,current->temperature[i]);	
	}
	current = current->next;
	printf("---------------------------------------------\n");
	}
	printf("\n");
}
//funcion encargada de dar de alta a un paciente en especifico
void dischargePatient(Patient **head,int id)
{
	Patient *current=*head;
	Patient *prev = NULL;
	while(current != NULL && current->id != id)
	{
		prev = current;
		current = current->next;
	}
	if(current == NULL)
	{
		printf("no hay paciente ingresado con el id: %d\n",id);
		printf("\n");
		return;
	}
	if(prev == NULL)
	{
		*head = current->next;
	}
	else
	{
		prev->next=current->next;
	}
	printf("numero de id del paciente:%d\n",current->id);
	printf("paciente dado de alta exitosamente\n");
	printf("\n");
	free(current);
}
//funcion encargada de liberar espacio de memoria
void freePatients(Patient *head) 
{
	Patient *current = head;
	while (current != NULL) 
	{
	Patient *next = current->next;
	free(current);
	current = next;
	}
}

int main()
{
	int numPatient=0;
	int i=0;
	int k=0;
	int alt=0;
	int p=0;
	float t=0;
	float temp=0;
	char n[50];
	Patient *head = NULL;
	Patient *newPatient;
	printf("La cantidad maxima de pacientes es de 30\n");
	printf("la temperatura de cada paciente se debe monitorear durante 7 dias\n");
	printf("\n");	
	while(k!=5)
	{
		printf("Si desea ingresar un paciente marque 1\n");
		printf("Si desea saber la lista de pacientes marque 2\n");
		printf("Si desea ingresar la temperatura de un paciente marque 3\n");
		printf("Si desea dar el alta a un paciente marque 4\n");
		printf("Si desea salir del programa marque 5\n");
		scanf("%d",&k);
		if(k==1)
		{
			newPatient = createPatient();
			addPatient(&head, newPatient);		
		}
		else if(k==2)
		{
			printPatients(head);
		}
		else if(k==3)
		{
			printf("ingrese el nombre del paciente al que le desea agregar temperatura:\n");
			scanf("%s",&n);
			recordTemperature(head,n);
		}
		else if(k==4)
		{
			printf("ingrese el id del paciente al que quiere dar de alta\n");
			scanf("%d",&alt);
			dischargePatient(&head,alt);
		}
		else if(k==5)
		{
			exit(-1);
		}
		
	}
	freePatients(head);
	
	return 0;
}


