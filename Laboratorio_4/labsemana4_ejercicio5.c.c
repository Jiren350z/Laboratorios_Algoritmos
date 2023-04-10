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
	struct patient *next;
	struct patient *prev;
}Patient;

//definicion del frente y el final de la cola del paciente
Patient *front=NULL;
Patient *rear=NULL;

//el enqueue ingresa al primer paciente 
//los demas que se ingresen quedan en cola
void enqueue(char*name,int age)
{
	Patient *newPatient = (Patient*)malloc(sizeof(Patient));
	printf("agregue el nombre del paciente\n");
	scanf("%s",&newPatient->name);
	printf("agregue la edad del paciente:\n");
	scanf("%d",&newPatient->age);
		
	newPatient->next=NULL;
	printf("paciente agregado exitosamente\n");
	if(front == NULL && rear == NULL)
	{
		front = rear = newPatient;
	}
	else
	{
		rear->next = newPatient;
		rear=newPatient;
	}
	printf("\n");
}

//el dequeue sirve para sacar solamente al primero de la cola
//el primero en entrar y el primero en salir
void dequeue()
{
	Patient *temp;
	if(front==NULL)
	{
		printf("La cola esta vacia No se puede realizar la eliminacion de la cola\n");
	}
	else
	{
		
		temp = front;
		
		front = front->next;
		if(front==NULL)
		{
			rear=NULL;
		}
		free(temp);
		printf("paciente sacado de cola exitosamente\n");
	}
	printf("\n");
}
//funcion que imprime la cola
void printList()
{
    Patient *temp = front;

    while(temp)
    {
    	printf("Nombre del paciente:%s\n",temp->name);
		printf("Edad del paciente:%d\n",temp->age);
        temp = temp->next;
        printf("----------------------------------------------\n");
    }
    printf("NULO\n");
    printf("\n");
}
//funcion que se encarga de saber los datos del paciente
//que esta despues del primero
void getNextPatient(Patient* front)
{
	if(front == NULL)
	{
		printf("La cola esta vacia\n");
	}
	else
	{
		Patient* next = front->next;
		if(next == NULL)
		{
			printf("No hay pacientes ingresados en la cola\n");
		}
		else
		{
			printf("Paciente:\n");
			printf("Nombre:%s\n",next->name);
			printf("Edad:%d\n",next->age);			
		}
	}
	printf("\n");
}
//funcion que se encarga de saber cuantos pacientes hay que atender
int getQueueSize()
{
	Patient *aux = front;
	int count = 0;
	while(aux!=NULL)
	{
		aux = aux->next;
		count++;
		
	}
	printf("Quedan:%d paciente/s por atender\n",count);
	printf("\n");
	return count;
}
//funcion que determina cuanto falta para que un paciente en especifico sea atendido
void getLeftPatients(Patient* front,char* name)
{
	if(front == NULL)
	{
		printf("La cola esta vacia\n");
	}
	else
	{
		int contpatient=0;
		Patient* current = front;
		while(current!=NULL && strcmp(current->name,name)!=0)
		{
			current = current->next;
			contpatient++;
		}
		if(current == NULL)
		{
			printf("Paciente %s no encontrado en la cola\n",name);
		}
		else
		{
			printf("al paciente %s le falta/n %d paciente/s para ser atendido/a\n",name,contpatient);
		}
	}
	printf("\n");
}
int main()
{
	int numPatient=0;
	int i=0;
	int k=0;
	int alt=0;
	
	//variables para la cola
	char name[50];
	int age=0;
	Patient *head = NULL;
	Patient *newPatient;
	while(k!=8)
	{
		printf("Si desea ingresar un paciente marque 1\n");
		printf("Si desea saber la lista de pacientes marque 2\n");
		printf("Si desea sacar de una cola al primer paciente marque 3\n");
		printf("Si desea conocer los datos del siguiente paciente de la cola marque 4\n");
		printf("Si desea conocer cuantos pacientes faltan por atender marque 5\n");
		printf("Si desea conocer cuantos pacientes faltan para el turno de un paciente marque 6\n");
		printf("Para cargar una lista de pacientes desde un arhivo marque 7\n");
		printf("Si desea salir del programa marque 8\n");
		scanf("%d",&k);
		if(k==1)
		{
			enqueue(name,age);
		}
		else if(k==2)
		{
			printf("----------------PACIENTES---------------------\n");
			printList();
		}
		else if(k==3)
		{
			dequeue();
		}
		else if(k==4)
		{
			getNextPatient(front);
		}
		else if(k==5)
		{
			getQueueSize();
		}
		else if(k==6)
		{
			printf("ingrese el nombre del paciente para saber cuanto falta para que lo atiendan\n");
			scanf("%s",&name);
			getLeftPatients(front,name);
		}
		else if(k==7)
		{
		//carga de archivo
		FILE *fp;
	    char line[100];
	    fp = fopen("paciente.txt","r");
	    if (fp == NULL) 
		{
	        printf("Error: No se puede abrir el archivo\n");
	        return 1;
	    }
	    while (fgets(line, sizeof(line), fp)) 
		{
	        Patient *newPatient = malloc(sizeof(Patient));
	        if (newPatient == NULL) 
			{
	            printf("Error: No se puede asignar memoria\n");
	            return 1;
	        }
	        char *token;
	        token = strtok(line, ",");
	        strcpy(newPatient->name, token);
	        newPatient->age = atoi(strtok(NULL, ","));
	        
	        newPatient->next = NULL;
	        newPatient->prev = NULL;
	        if (front == NULL) 
			{
	            front = newPatient;
	            rear = newPatient;
	            
	        } else 
			{
	            rear->next = newPatient;
	            newPatient->prev = rear;
	            rear = newPatient;
	        }
	        
	    }
		printf("Datos cargados exitosamente\n");
		printf("\n");
	    fclose(fp);
		}
		else if(k==8)
		{
			exit(-1);
		}
		
	}
	
	return 0;
}


