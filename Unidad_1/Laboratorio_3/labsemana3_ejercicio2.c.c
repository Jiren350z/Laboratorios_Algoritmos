#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//estructura general que se usa para todo 
typedef struct
{
	char nombre[20];
	int salud;
	int nivel;
	int puntaje;
	int ataque;
	int defensa;
	int equipo;
}Jugador;
 
int main()
{
	srand(time(NULL));
	char nom[20];
	int sal;
	int niv;
	int punt;
	int atq;
	int def;
	int i;
	int max=0; //variable que determina el maximo de jugadores
	int t1=0; //equipo 1
	int t2=0; //equipo2
	
	//declaracion de la cantidad de jugadores
	Jugador j1,j2,j3,j4,j5,j6,j7,j8,j9,j10;
	//arreglo de 10 jugadores
	Jugador *jugadores[10]= 
	{malloc(sizeof(j1)),
	malloc(sizeof(j2)), 
	malloc(sizeof(j3)),
	malloc(sizeof(j4)),
	malloc(sizeof(j5)),
	malloc(sizeof(j6)),
	malloc(sizeof(j7)),
	malloc(sizeof(j8)),
	malloc(sizeof(j9)),
	malloc(sizeof(j10))
	};
	
	printf("Defina la cantidad de jugadores\n");
	scanf("%d",&max);
	
	for(i=0;i<max;i++)
	{
		//deternimando el nombre por teclado y las estadisticas por randoms, incluyendo a la asignacion de equipos.
		printf("Jugador %d\n",i+1);
		printf("Introduzca su nombre:\n");
		scanf("%s",&jugadores[i]->nombre);
		jugadores[i]->salud=rand()%2100+1;
		jugadores[i]->nivel=rand()%713+1;
		jugadores[i]->puntaje=rand()%8000000+1;
		jugadores[i]->ataque=rand()%16000+1;
		jugadores[i]->defensa=rand()%9000+1;
		jugadores[i]->equipo=(rand()%2)+1;
		//condicional encargada de balancear los equipos de manera equitativa
		//y que ambos equipos tengan la misma cantidad de jugadores
		if(jugadores[i]->equipo == 1 )
		{
			t1++;
		}
		else if(jugadores[i]->equipo == 2)
		{
			t2++;
		}
		if(t1>max/2) 
		{
			jugadores[i]->equipo=2;
		}
		else if(t2>max/2)
		{
			jugadores[i]->equipo=1;
		}
			
	}
	for(i=0;i<max;i++)
	{
		printf("------------JUGADOR:%d------------\n",i+1);
		printf("Nombre:%s\n",jugadores[i]->nombre);
		printf("Salud:%d\n",jugadores[i]->salud);
		printf("Nivel:%d\n",jugadores[i]->nivel);
		printf("Puntaje:%d\n",jugadores[i]->puntaje);
		printf("Ataque:%d\n",jugadores[i]->ataque);
		printf("Defensa:%d\n",jugadores[i]->defensa);
		printf("Pertenece al Equipo %d\n",jugadores[i]->equipo);
	}

	return 0;
}

