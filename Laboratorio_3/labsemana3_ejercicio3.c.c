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
	int k=0;
	int max=0; //variable que determina el maximo de jugadores
	int t1=0; //equipo 1
	int t2=0; //equipo2
	int es=0; //variable usada para mostrar las estadisticas
	int act=0; //variable usada para actualizar
	int pt1=0; //puntaje total del equipo 1
	int pt2=0; //púntaje total del equipo 2
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
	//arreglo que se encarga de detrminar todo
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
		//condicionales que suma los puntajes de cada equipo
		if(jugadores[i]->equipo==1)
		{
			pt1=pt1+jugadores[i]->puntaje;
		}
		else if(jugadores[i]->equipo==2)
		{
			pt2=pt2+jugadores[i]->puntaje;
		}
	}
	//arreglo que imprime todo lo establecido
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
	printf("---------------------------------------------\n");
	//se imprime el puntaje total de cada equipo
	printf("Cantida de Puntaje Total por Equipos:\n");
	printf("Cantidad total de puntos de experiencia del equipo 1:%d\n",pt1);
	printf("Cantidad total de puntos de experiencia del equipo 2:%d\n",pt2);
	//Condicional que define al equipo ganador
	if(pt1>pt2)
	{
		printf("El Equipo 1 es el ganador\n");
	}
	if(pt2>pt1)
	{
		printf("El Equipo 2 es el ganador\n");
	}
	printf("---------------------------------------------\n");
	//menu que se encargara de saber que es lo que quiere hacer el usuario
	while(k!=3)
	{
		printf("si desea mostrar las estadisticas de un jugador marque 1:\n");
		printf("si desea actualizar las estadisticas de un jugador marque 2:\n");
		printf("si no desea hacer nada marque 3:\n");
		scanf("%d",&k);
		if(k==1)
		{
			//mostrar estadisticas de un jugador seleccionado
			printf("De que jugador desea ver las estadistcas?:\n");
			scanf("%d",&es);
			printf("Estadisticas del Jugador %d\n",es);
			printf("Nombre:%s\n",jugadores[es-1]->nombre);
			printf("Salud:%d\n",jugadores[es-1]->salud);
			printf("Nivel:%d\n",jugadores[es-1]->nivel);
			printf("Puntaje:%d\n",jugadores[es-1]->puntaje);
			printf("Ataque:%d\n",jugadores[es-1]->ataque);
			printf("Defensa:%d\n",jugadores[es-1]->defensa);
			printf("Pertenece al Equipo %d\n",jugadores[es-1]->equipo);
			printf("---------------------------------------------\n");
		}
		if(k==2)
		{
			//actualizar estadisticas de un jugador seleccionado
			printf("A que jugador quiere cambiarle las estadisticas?\n");
			scanf("%d",&act);
			printf("Jugador %d Seleccionado para cambiar estadisticas\n",act);
			printf("Introduzca su nuevo nombre o mantenga el que ya tiene:\n");
			scanf("%s",&jugadores[act]->nombre);
			jugadores[act]->salud=rand()%2100+1;
			jugadores[act]->nivel=rand()%713+1;
			jugadores[act]->puntaje=rand()%8000000+1;
			jugadores[act]->ataque=rand()%16000+1;
			jugadores[act]->defensa=rand()%9000+1;
			printf("---------------------------------------------\n");
			printf("Estadisticas actualizadas:\n");
			printf("Nombre:%s\n",jugadores[act]->nombre);
			printf("Salud:%d\n",jugadores[act]->salud);
			printf("Nivel:%d\n",jugadores[act]->nivel);
			printf("Puntaje:%d\n",jugadores[act]->puntaje);
			printf("Ataque:%d\n",jugadores[act]->ataque);
			printf("Defensa:%d\n",jugadores[act]->defensa);
			printf("Pertenece al Equipo %d\n",jugadores[act-1]->equipo);
			printf("---------------------------------------------\n");
		}
		if(k==3)
		{
			exit(-1);
		}
	}
	
	return 0;
}

