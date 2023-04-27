#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
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

/*Guardian* CreateGuardian(char*nombre,char*tipo,int vida, int ataque, int defensa)
{
	Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	strcpy(newGuardian->nombre, nombre);
	strcpy(newGuardian->tipo, tipo);
	newGuardian->vida = vida;
	newGuardian->ataque = ataque;
	newGuardian->defensa = defensa; 
	return newGuardian;	
} 
*/
//funcion que permite crear un personaje por parte del jugador
Guardian* createCharacter(char*nombre,char*tipo)
{
	
	srand(time(NULL));
	Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	//printf("Introduce el nombre de tu guardian:\n");
	//scanf("%s",&newGuardian->nombre);
	//printf("Define tu tipo de guardian\n");
	//scanf("%s",&newGuardian->tipo);
	strcpy(newGuardian->nombre, nombre);
	strcpy(newGuardian->tipo, tipo);
	newGuardian->vida = rand()%600+400;
	newGuardian->ataque = rand()%200+115;
	newGuardian->defensa = rand()%100+30; 		
	newGuardian->next = NULL;
	return newGuardian;	
}

//funcion que añade a un guardian a una lista
void addGuardian(Guardian **head, Guardian *newGuardian) 
{
	//si el primero de la lista esta vacio el personaje creado pasa a tomar su lugar
	//en caso de que exista alguien se ira añadiendo personajes
	// a medida que se ingresen el actual estara apuntando al siguiente en la lista
	if (*head == NULL) 
	{
		*head = newGuardian;
	} 
	else 
	{
		Guardian *current = *head;
		while (current->next != NULL) 
		{
			current = current->next;
		}
		current->next = newGuardian;
	}
}

//funcion que imprime la lista de personajes
void printCharacterStatus(Guardian *head)
{
    Guardian *current = head;
    while (current != NULL)
	{
        printf("Nombre: %s\n",current->nombre);
        printf("Tipo: %s\n",current->tipo);
        printf("Vida: %d\n",current->vida);
        printf("Ataque: %d\n",current->ataque);
        printf("Defensa: %d\n",current->defensa);
        current = current->next;
        printf("----------------------------------------------\n");
    }
}
void i(Guardian **head)
{
	FILE *fp;
	fp = fopen("Guardianes.txt","r");
	if (fp == NULL) 
		{
	        printf("Error: No se puede abrir el archivo\n");
	        //return 1;
	        return;
	    }
	  //  while(fscanf(fp,"%s" "%s" "%d" "%d" "%d",nombre,tipo,&vida,&ataque,&defensa)==5)
	   // {
	    //	Guardian *g = malloc(sizeof(Guardian));
	    //	strcpy(g->nombre,nombre);
		//}
	    
	
}
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

/*Guardian* listaRival()
{
	Guardian *head=NULL;
	Guardian *newGuardian;
 	newGuardian = CreateGuardian("Mance","vikingo",300,120,90);
	addGuardian(&head,newGuardian);	
	newGuardian = CreateGuardian("Race","vikingo",500,200,100);
	addGuardian(&head,newGuardian);	
	newGuardian = CreateGuardian("Vigo","nigromante",300,130,50);
	addGuardian(&head,newGuardian);	
	newGuardian = CreateGuardian("Ray","mago",150,100,80);
	addGuardian(&head,newGuardian);	
	newGuardian = CreateGuardian("Mayor","Bestia",600,200,100);
	addGuardian(&head,newGuardian);	
	newGuardian = CreateGuardian("Boss","mago",350,195,98);
	addGuardian(&head,newGuardian);	
	newGuardian = CreateGuardian("Aria","vikinga",460,175,75);
	addGuardian(&head,newGuardian);	
	return newGuardian;
}
*/
//menu de opciones
void menuOptions()
{
		Guardian *head=NULL;
		Guardian *newGuardian;
		char nombre[50];
		char tipo[50];
 		int k=0;
 		int vida=0;
 		int ataque=0;
 		int defensa=0;
		printf("Bienvenido a The Guardians Tournament\n");
 		while(k!=8)
 		{
 		
		printf("----------------Menu de Opciones---------------------\n");
		printf("Seleccione la opcion para continuar\n");
		printf("1: Crear un Personaje\n");
		printf("2: Ver el Estado de los Personajes\n");
		printf("3: Crear una lista de personajes predefinidos\n");
		printf("7: Cargar Datos Externos de los Personajes\n");
		printf("8: Salir\n");
		scanf("%d",&k);
		if(k==1)
		{
			printf("Introduce el nombre de tu guardian:\n");
			scanf("%s",&nombre);
			printf("Define tu tipo de guardian\n");
			scanf("%s",&tipo);
			newGuardian = createCharacter(nombre,tipo);
			addGuardian(&head,newGuardian);		
		}
		else if(k==2)
		{
			printf("----------------GUARDIANES---------------------\n");
			printCharacterStatus(head);
			printList();
		}
		else if(k==3)
		{
			
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
	    while (fgets(line, 100, fp)) 
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
	        token = strtok(NULL,",");
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
		else if(k==8)
		{
		exit(-1);
		}
	}
		
}

int main()
{	
	//inicia al primer guardian en nulo
	//posteriormente toma los datos de un guardian creado
	Guardian *head=NULL;
	Guardian *newGuardian;
	printf("Lista creada\n");
		newGuardian = createCharacter("Mance","vikingo");
		addGuardian(&head,newGuardian);		
		newGuardian = createCharacter("Race","vikingo");
		addGuardian(&head,newGuardian);	
		newGuardian = createCharacter("Vigo","nigromante");
		addGuardian(&head,newGuardian);	
		newGuardian = createCharacter("Ray","mago");
		addGuardian(&head,newGuardian);	
		newGuardian = createCharacter("Mayor","Bestia");
		addGuardian(&head,newGuardian);	
		newGuardian = createCharacter("Boss","mago");
		addGuardian(&head,newGuardian);	
		newGuardian = createCharacter("Aria","vikinga");
		addGuardian(&head,newGuardian);	
		printCharacterStatus(head);
		free(head);
	//random para generar los atributos aleatorios de un guardian
	//srand(time(NULL));
	//variable para el funcionamiento del menu de opciones
	int k=0;
	//variable para abrir un archivo
		
		//menu
		menuOptions();
		return 0;
}

/*
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
	    */
