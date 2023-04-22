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

Guardian* createCharacter(char*nombre,char*tipo,int vida, int ataque, int defensa)
{
	Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	strcpy(newGuardian->nombre, nombre);
	strcpy(newGuardian->tipo, tipo);
	newGuardian->vida = vida;
	newGuardian->ataque = ataque;
	newGuardian->defensa = defensa; 		
	newGuardian->next = NULL;
	return newGuardian;	
}

void addGuardian(Guardian **headRef,Guardian *newGuardian)
{
    if (*headRef == NULL)
	{
        *headRef = newGuardian;
    }
    else 
	{
        Guardian *current = *headRef;
        while ( current->next != NULL )
		{
            current = current->next;
        }
        current->next = newGuardian;
    }
}
void addplayer(Guardian **headRef,Guardian *player)
{
    if (*headRef == NULL)
	{
        *headRef = player;
    }
    else 
	{
        Guardian *current = *headRef;
        while ( current->next != NULL )
		{
            current = current->next;
        }
        current->next = player;
    }
}
void lista_Rival(Guardian **headRef,Guardian *newGuardian)
{
	if (*headRef == NULL)
	{
        *headRef = newGuardian;
    }
    else 
	{
        Guardian *current = *headRef;
        while ( current->next != NULL )
		{
            current = current->next;
        }
        current->next = newGuardian;
    }
}

void enqueue(Guardian **headRef, Guardian **tailRef, Guardian *newGuardian) 
{
    if (*headRef == NULL) 
	{
        *headRef = newGuardian;
    } 
	else 
	{
        (*tailRef)->next = newGuardian;
    }
    *tailRef = newGuardian;
}

Guardian* dequeue(Guardian **headRef, Guardian **tailRef)
{
	if (*headRef == NULL) 
	{
        printf("No hay ningun guardian ingresado.");
        exit(1);
    }
    Guardian* dequeuedGuardian = *headRef;
    *headRef = (*headRef)->next;
    if (*headRef == NULL) 
	{
        *tailRef = NULL;
    }
    dequeuedGuardian->next = NULL;
    return dequeuedGuardian;
}

void sacar_personaje(Guardian **headRef,char*nombre)
{
	Guardian *current=*headRef;
	Guardian *prev = NULL;
	//strcmp(current->nombre, nombre)==0
	while(current != NULL && strcmp(current->nombre, nombre)!= 0)
	{
		prev = current;
		current = current->next;
	}
	if(current == NULL)
	{
		printf("no hay guardian ingresado con el nombre: %s\n",nombre);
		printf("\n");
		return;
	}
	if(prev == NULL)
	{
		*headRef = current->next;
	}
	else
	{
		prev->next=current->next;
	}
	printf("Guardian:%s\n",current->nombre);
	printf("guardian seleccionado y sacado de la lista\n");
	printf("\n");
	free(current);
}

 
void printCharacterStatus(Guardian *headRef)
{
    Guardian *current = headRef;
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

Guardian* selectCharacter(Guardian* headRef,char*nombre)
{
		Guardian* current = headRef;
		while(current != NULL)
		{
			if(strcmp(current->nombre, nombre)==0)
			{
				return current;
			}
			current = current->next;
		}
		return NULL; 
}

int getRollResult()
{
	//srand(time(NULL));
	int dado=rand() % 6 + 1;
	return dado;
}
//sacar el tamaño de la lista
int getSize(Guardian *headRef)
{
    int size = 0;
    Guardian *current = headRef;
    while (current != NULL)
	{
        size++;
        current = current->next;
    }
    return size;
}
//funcion de atacar
void Ataque(Guardian* atacante, Guardian* rival,int dado)
{
	if(dado == 1 || dado == 3 || dado == 5)
	{
		if(dado==1)
		{
			atacante->ataque = atacante->ataque *0.8;
			printf("factor ataque 0.8\n");
			printf("ataque actual: %d\n",atacante->ataque);
		}
		else if(dado==3)
		{
			atacante->ataque = atacante->ataque *1;
			printf("factor ataque 1\n");
			printf("ataque actual: %d\n",atacante->ataque);
		}
		else if(dado==5)
		{
			atacante->ataque = atacante->ataque *1.3;
			printf("factor ataque 1.3\n");
			printf("ataque actual: %d\n",atacante->ataque);
		}
		rival->vida=rival->vida-atacante->ataque;
		printf("Vida restante de %s: %d\n",rival->nombre, rival->vida);
	}
	else if(dado == 2 || dado == 4 || dado == 6)
	{
		printf("ataque bloqueado por el rival\n");
		printf("Vida restante de %s: %d\n",rival->nombre, rival->vida);	
	}	
}
//funcion de defender
void Defensa(Guardian* defender, int dado)
{
	if(dado == 2 || dado == 4 || dado == 6)
	{
		if(dado == 2)
		{
			defender->defensa=defender->defensa*0.5;
			printf("factor defensa 0.5\n");
			printf("defensa actual: %d\n",defender->defensa);
		}
		else if(dado == 4)
		{
			defender->defensa=defender->defensa*1;
			printf("factor defensa 1\n");
			printf("defensa actual: %d\n",defender->defensa);
		}
		else if(dado == 6)
		{
			defender->defensa=defender->defensa*1.2;
			printf("factor defensa 1.2\n");
			printf("defensa actual: %d\n",defender->defensa);
		}
		defender->vida = defender->vida + defender->defensa;
		printf("vida restante de %s: %d\n",defender->nombre,defender->vida);
	}
	else if(dado == 1 || dado == 3 || dado == 5)
	{
		printf("defensa incompleta\n");
		defender->defensa = defender->defensa-(defender->defensa*5/100);
		printf("desgaste en puntos de defensa\n");
		printf("defensa restante de %s: %d\n",defender->nombre,defender->defensa);				
	}			
}
int selectTournament(int dif,int riv)
{
	printf("Seleccione el nivel de dificulta del troneo\n");
	printf("1: Principiante: Derrotar a tres guardianes\n");
	printf("2: Intermedio: Derrotar a cinco guardianes\n");
	printf("3: Experto: Derrotar a siete guardianes\n");
	scanf("%d",&dif);
	return dif;		
}
Guardian *llamar_Azar(Guardian *headRef) {
    int count = 0;
    int i=0;
    Guardian *current = headRef;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    int num = rand() % count + 1;
    current = headRef;
    for ( i = 1; i < num; i++) {
        current = current->next;
    }
    return current;
}

Guardian *llamar_jugador_al_azar(Guardian *headRef,int *total_jugadores_seleccionados,int *jugadores_seleccionados) {
    int total_jugadores = 0;
    int i=0;
    Guardian* jugador_actual = headRef;
    while (jugador_actual != NULL) 
	{
        total_jugadores++;
        jugador_actual = jugador_actual->next;
    }
    int numero_aleatorio = rand() % total_jugadores + 1;
    int jugador_seleccionado = -1;
    jugador_actual = headRef;
    for ( i = 1; i <= total_jugadores; i++) 
	{
        if (jugadores_seleccionados[i] == 0) 
		{
            jugador_seleccionado++;
            if (jugador_seleccionado == numero_aleatorio - 1) 
			{
                jugadores_seleccionados[i] = 1;
                total_jugadores_seleccionados++;
                return jugador_actual;
            }
        }
        jugador_actual = jugador_actual->next;
    }
    return NULL;
}

void startFight(Guardian* headRef,Guardian* seleccionado,Guardian* newGuardian,Guardian* player,Guardian* oponente,Guardian* tail,int op,int riv,int dif)
{
	char nombre_riv[50];
	//int op=0;
	int dado=0;
	//
	int dado_rival=0;
	//variables del jugador seleccionado
	char nombresel[50];
	int vidasel=0;
	int ataquesel=0;
	int defensasel=0;
	//variables del rival
	char nombrerival[50];
	int vidarival=0;
	int ataquerival=0;
	int defensarival=0;
	//
	int contador = 0;
	//
	int turno = 0;
	//
	int opcion=0;
	int i=0;
	int count=0;
	int c=0;
	//int *total;
	//int *disponibles;
	int *seleccion;
	
	//codigo para verificacion y agregacion de personajes
	//printf("rivales: %d\n",riv);
	//while(c<riv)
	//{
	//	c++;
	//	printf("rival: %d\n",c);
	//}
	if(headRef == NULL)
	{
		printf("No hay ningun guardian ingresado\n");
	}
	else
	{
		//cargar lista rival
		//lista_Rival(&headRef,newGuardian);
		//contador=getSize(headRef);
		//printf("Cantidad de rivales a derrotar: %d\n",contador);	
			if(seleccionado!= NULL)
			{
				//seleccion de guardian
				printf("Guardian seleccionado:\n");
				printf("Nombre: %s\n",seleccionado->nombre);
				printf("Tipo: %s\n",seleccionado->tipo);
				printf("Vida: %d\n",seleccionado->vida);
				printf("Ataque: %d\n",seleccionado->ataque);
				printf("Defensa: %d\n",seleccionado->defensa);
			}
			if(player != NULL)
			{
				printf("Jugador creado:\n");
				printf("Nombre: %s\n",player->nombre);
				printf("Tipo: %s\n",player->tipo);
				printf("Vida: %d\n",player->vida);
				printf("Ataque: %d\n",player->ataque);
				printf("Defensa: %d\n",player->defensa);
			}
		
		oponente=headRef;
		printf("----------------lista rival----------------\n");
		while(oponente!=NULL)
		{
			printf("nombre del rival: %s\n",oponente->nombre);
			printf("tipo del rival: %s\n",oponente->tipo);
			printf("vida del rival: %d\n",oponente->vida);
			printf("ataque del rival: %d\n",oponente->ataque);
			printf("defensa del rival: %d\n",oponente->defensa);
			count++;
			oponente = oponente->next;
			printf("count: %d\n",count);	
			printf("-------------------------------------------\n");
		}
		if(riv==0)
		{
			printf("no hay dificultad seleccionada, seleccione una para continuar\n");
		}
		else
		{
			printf("Rivales a Enfrentar: %d\n",riv);
			printf("------------------------------\n");
			while(c<riv)
			{		
					int num = rand()%count+1;
					Guardian *rival = oponente;
					rival = headRef;
					for(i=1;i<num;i++)
					{
						rival=rival->next;
					}
					printf("rival al azar es: %s\n",rival->nombre);
					printf("Tipo: %s\n",rival->tipo);
					printf("Vida: %d\n",rival->vida);
					printf("Ataque: %d\n",rival->ataque);
					printf("Defensa: %d\n",rival->defensa);	
					printf("------------------------------\n");
					printf("QUE COMIENCE EL COMBATE\n");
				while(rival->vida>0)
				{
					
					if(seleccionado->vida>0 || player->vida>0)
					{
						printf("------------------------------\n");
						printf("Turno del Usuario\n");
						printf("Que quieres hacer?\n");
						printf("opcion 1: atacar\n");
						printf("opcion 2: defender\n");
						scanf("%d",&op);
						//ataque
						if(op==1)
						{
							printf("Opcion elegida por el usuario: Atacar\n");
							if(player!=NULL)
							{
								dado = getRollResult();
								printf("Resultado del lanzamiento de dados: %d\n",dado);
								Ataque(player,rival,dado);
								
							}
							if(seleccionado!=NULL)
							{
								dado = getRollResult();
								printf("Resultado del lanzamiento de dados: %d\n",dado);
								Ataque(seleccionado,rival,dado);
					
							}
			
						}
						//defensa
						if(op==2)
						{
							printf("Opcion elegida por el usuario: Defender\n");
							if(player!=NULL)
							{
								dado = getRollResult();
								printf("Resultado del lanzamiento de dados: %d\n",dado);
								Defensa(player,dado);
									
							}
							if(seleccionado!=NULL)
							{
								dado = getRollResult();
								printf("Resultado del lanzamiento de dados: %d\n",dado);
								Defensa(seleccionado,dado);	
								
							}		
						}
					}
					else
					{
						printf("HAS PERDIDO\n");
							
						//return;
					}
					if(rival->vida>0)
					{
						printf("------------------------------\n");
						printf("Turno del rival\n");
						printf("Rival: %s\n",rival->nombre);
						printf("1: atacar\n");
						printf("2: defender\n");
						//srand(time(NULL));
						int randop=0;
						randop=rand()%2+1;
						printf("Seleccion del rival: %d\n",randop);
						if(randop==1)
						{
							printf("Opcion elegida por el rival: Atacar\n");
							if(player!=NULL)
							{
							dado_rival = getRollResult();
							printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
							Ataque(rival,player,dado_rival);
							
							}
							if(seleccionado!=NULL)
							{
							dado_rival = getRollResult();
							printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
							Ataque(rival,seleccionado,dado_rival);
							
							}
						}
						if(randop==2)
						{
							printf("Opcion elegida por el rival: Defender\n");
							dado_rival = getRollResult();
							printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
							Defensa(rival,dado_rival);
							
						}
					}
					else
					{
						printf("RIVAL DERROTADO\n");
						sacar_personaje(&headRef,rival->nombre);
						c++;
						printf("rivales derrotados: %d\n",c);
					}
				}
			}
			printf("Torneo Terminado\n");	
		}
	}
		
}

void menuOptions()
{
		Guardian *headRef=NULL;
    	Guardian *tail = NULL;
    	Guardian *seleccion=NULL;
    	Guardian *jugador=NULL;
		Guardian *newGuardian; 
		Guardian *oponente;
		int k=0;
		//variable para limitar la seleccion de guardianes a 1
		int sle=0;
		//variables de la estructura guardian
		char nombre[50];
		char tipo[50];
 		int vida=0;
 		int ataque=0;
 		int defensa=0;
 		//variable para seleccionar un jugador
 		char sel[50];
 		//dificultad
 		int dificultad=0;
 		//rivales
 		int rivales=0;
 		//opcion para elegir
 		int op=0;
 		int dado=0;
 		int eleccion=0;
		printf("Bienvenido a The Guardians Tournament\n");
 		while(k!=9)
 		{
		printf("----------------Menu de Opciones---------------------\n");
		printf("Seleccione la opcion para continuar\n");
		printf("1: Seleccionar un personaje\n");
		printf("2: Crear un Personaje\n");
		printf("3: Seleccionar nivel de dificultad\n");
		printf("4: Ver el Estado de los Personajes\n");
		printf("5: Comenzar Pelea\n");
		printf("6: Saber el resultado del lanzamiento de dados\n");
		printf("7: Conocer el historial del jugador\n");
		printf("8: Cargar Datos Externos de los Personajes\n");
		printf("9: Salir\n");
		scanf("%d",&k);
		if(k==1)
		{
			if(headRef == NULL)
			{
				printf("No hay ningun guardian ingresado\n");
			}
			else
			{
				while(sle!=1)
				{
					printf("Elige a tu guardian\n");
					scanf("%s",&sel);
					seleccion = selectCharacter(headRef,sel);
					if(seleccion != NULL)
					{
						printf("jugador %s seleccionado esta en la lista:\n", seleccion->nombre);
						printf("\n");
						printf("Nombre: %s\n",seleccion->nombre);
						printf("Tipo: %s\n",seleccion->tipo);
						printf("Vida: %d\n",seleccion->vida);
						printf("Ataque: %d\n",seleccion->ataque);
						printf("Defensa: %d\n",seleccion->defensa);
						sacar_personaje(&headRef,sel);
						sle=sle+1;
						//eleccion=1;
						//printf("has seleccionado un jugador de la lista por ende no puedes crearlo\n");
					}
					else
					{
						printf("%s no encontrado\n",sel);
						sle=0;
					}	
				}
				if(sle==1)
				{
					printf("Solo puedes seleccionar a un guardian\n");
				}
			}
		}
		else if(k==2)
		{
			printf("Introduce el nombre de tu guardian:\n");
			scanf("%s",&nombre);
			printf("Define tu tipo de guardian\n");
			scanf("%s",&tipo);
			vida = rand()%(600-400+1)+400;
			ataque = rand()%(200-115+1)+115;
			defensa = rand()%(100-30 +1)+30; 
			jugador = createCharacter(nombre,tipo,vida,ataque,defensa);
			
			//addplayer(&headRef,jugador);
			//addGuardian(&headRef,jugador);
			//eleccion=1;
			//printf("has creado a tu jugador por ende no puedes seleccionar a un jugador de la lista\n");
			//addGuardian(&headRef,jugador);
			//enqueue(&headRef,&tail,newGuardian);		
		}
		else if(k==3)
		{
			dificultad=selectTournament(dificultad,rivales);
			if(dificultad==1)
			{
				printf("has escogido el nivel principiante\n");
				rivales=3;
				printf("cantidad de guardianes a enfrentar: %d\n",rivales);
			}
			if(dificultad==2)
			{
				printf("has escogido el nivel intermedio\n");
				rivales=5;
				printf("cantidad de guardianes a enfrentar: %d\n",rivales);
			}
			if(dificultad==3)
			{
				printf("has escogido el nivel experto\n");
				rivales=7;
				printf("cantidad de guardianes a enfrentar: %d\n",rivales);
			}
		}
		else if(k==4)
		{
			printf("----------------GUARDIANES---------------------\n");
			printCharacterStatus(headRef);
		}
		else if(k==5)
		{
			startFight(headRef,seleccion,newGuardian,jugador,oponente,tail,op,rivales,dificultad);	
		}
		else if(k==6)
		{
			dado = getRollResult();
			printf("resultado del dado: %d\n",dado);
		}
		else if(k==7)
		{
			
		}
		else if(k==8)
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
	        	addGuardian(&headRef,newGuardian);
	        	//enqueue(&headRef,&tail,newGuardian);	
	        
	        //CODIGO PARA ENCOLAR AL GUARDIAN
	       // if(tail==NULL)
			//{
			//	headRef=newGuardian;
			//}
			//else
			//{
			//	tail->next=newGuardian;
			//}
			//tail = newGuardian;
	        
	    }
		printf("Datos cargados exitosamente\n");
		printf("\n");
	    fclose(fp);
		}
		else if(k==9)
		{
		exit(-1);
		}
	}
		
}

int main()
{
	int k=0;
	srand(time(NULL));
	menuOptions();
	return 0;
}





/*
switch(k)
{
	case 1:
	
	break;
}
*/



