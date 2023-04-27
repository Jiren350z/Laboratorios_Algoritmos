#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct guardian{
	char nombre[50];
	char tipo[50];
	int vida;
	int ataque;
	int defensa;
	struct guardian *next;
	struct guardian *prev;
}Guardian;

//definicion del frente y el final de la cola del personaje
Guardian *front=NULL;
Guardian *rear=NULL;


//funcion que permite crear un personaje por parte del jugador 
void createCharacter(char*nombre,char*tipo,int vida, int ataque, int defensa)
{
	srand(time(NULL));
	Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	printf("Introduce el nombre de tu guardian:\n");
	scanf("%s",&newGuardian->nombre);
	printf("Define tu tipo de guardian\n");
	scanf("%s",&newGuardian->tipo);
	newGuardian->vida = rand()%600+400;
	newGuardian->ataque = rand()%200+115;
	newGuardian->defensa = rand()%100+30; 		
	newGuardian->next = NULL;	
	printf("Guardian creado exitosamente\n");
	if(front == NULL && rear == NULL)
	{
		front = rear = newGuardian;
	}
	else
	{
		rear->next = newGuardian;
		rear=newGuardian;
	}
	printf("\n");
}

/*void listaRival(char*nombre, char*tipo,int vida, int ataque, int defensa)
{
	//srand(time(NULL));
	Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	strcpy(newGuardian->nombre, nombre);
	strcpy(newGuardian->tipo, tipo);
	newGuardian->vida = vida;
	newGuardian->ataque = ataque;
	newGuardian->defensa = defensa; 
	if(front == NULL && rear == NULL)
	{
		front = rear = newGuardian;
	}
	else
	{
		rear->next = newGuardian;
		rear=newGuardian;
	}
	printf("\n");	
}
*/
//funcion que imprime a los jugadores ingresados por datos externos
//en forma de cola
void printList()
{
    Guardian *temp = front;

    while(temp)
    {
    	printf("Nombre:%s\n",temp->nombre);
    	printf("Tipo:%s\n",temp->tipo);
		printf("Vida:%d\n",temp->vida);
		printf("Ataque:%d\n",temp->ataque);
		printf("Defensa:%d\n",temp->defensa);
        temp = temp->next;
        printf("----------------------------------------------\n");
    }
    printf("NULO\n");
    printf("\n");
}
//menu de opciones
void menuOptions()
{
		char nombre[50];
		char tipo[50];
		int vida;
		int ataque;
		int defensa;
		Guardian *head=NULL;
		Guardian *newGuardian;
 		int k=0;
		printf("Bienvenido a The Guardians Tournament\n");
 		while(k!=8)
 		{
 		
		printf("----------------Menu de Opciones---------------------\n");
		printf("Seleccione la opcion para continuar\n");
		printf("1: Crear un Personaje\n");
		printf("2: Ver el Estado de los Personajes\n");
		printf("7: Cargar Datos Externos de los Personajes\n");
		printf("8: Salir\n");
		scanf("%d",&k);
		if(k==1)
		{
			createCharacter(nombre,tipo,vida,ataque,defensa);	
		}
		else if(k==2)
		{
			printf("----------------GUARDIANES---------------------\n");
			printList();
		}
		else if(k==7)
		{
		//carga de archivo
		FILE *fp;
	    char line[100];
	    fp = fopen("Guardianes.txt","r");
	    if (fp == NULL) 
		{
	        printf("Error: No se puede abrir el archivo\n");
	        //return 1;
	        return;
	    }
	    while (fgets(line, sizeof(line), fp)) 
		{
	        Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	        if (newGuardian == NULL) 
			{
	            printf("Error: No se puede asignar memoria\n");
	            //return 1;
	            return;
	        }
	        char *token;
	        token = strtok(line, ",");
	        strcpy(newGuardian->nombre, token);
	        strcpy(newGuardian->tipo, token);
	        newGuardian->vida = atoi(strtok(NULL, ","));
	        newGuardian->ataque = atoi(strtok(NULL, ","));
	        newGuardian->defensa = atoi(strtok(NULL, ","));
	        newGuardian->next = NULL;
	        newGuardian->prev = NULL;
	        if (front == NULL) 
			{
	            front = newGuardian;
	            rear = newGuardian;
	            
	        } else 
			{
	            rear->next = newGuardian;
	            newGuardian->prev = rear;
	            rear = newGuardian;
	        }
	        
	    }
		printf("Datos cargados exitosamente\n");
		printf("\n");
	    fclose(fp);
		}
		else if(k==4)
		{
			
		}
		else if(k==5)
		{
			
		}
		else if(k==6)
		{
			
		}
		else if(k==8)
		{
		exit(-1);
		}
	}
		
}
int main()
{	
	Guardian *head=NULL;
	Guardian *newGuardian;
	//lista de jugadores ya definidos
	
	
		//menu
		menuOptions();
		return 0;
}


