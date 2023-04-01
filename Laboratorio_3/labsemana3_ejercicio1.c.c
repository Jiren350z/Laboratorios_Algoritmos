#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char nombre[20];
	int salud;
	int nivel;
	int puntaje;
}Jugador;

int main()
{
	char nom[20];
	int sal;
	int niv;
	int punt;
	Jugador jugador1 = {"xx_dexsexis_xxx",1800,190,1231312};
	
	//uso de malloc fgets
	Jugador *jugador2=malloc(sizeof(Jugador));
	strcpy(jugador2->nombre,"cazatrolos96");
	jugador2->salud=1900;
	jugador2->nivel=200;
	jugador2->puntaje=1232121;
	//jugador 3 por teclado
	printf("Defina el nombre del jugador 3:\n");
	fgets(nom,sizeof(nom),stdin);
	printf("Defina la salud del jugador 3:\n");
	scanf("%d",&sal);
	printf("Defina el nivel del jugador 3:\n");
	scanf("%d",&niv);
	printf("Defina el puntaje del jugador 3:\n");
	scanf("%d",&punt);	
	Jugador *jugador3=malloc(sizeof(Jugador));
	strcpy(jugador3->nombre,nom);
	jugador3->salud=sal;
	jugador3->nivel=niv;
	jugador3->puntaje=punt;
	
	//struct
	printf("Jugador 1 por estrcuturas ya definidas:\n");
	printf("Nombre:%s\n",jugador1.nombre);
	printf("Salud:%d\n",jugador1.salud);
	printf("Nivel:%d\n",jugador1.nivel);
	printf("Puntaje:%d\n",jugador1.puntaje);
	printf("Jugador 2 por punteros con variables ya definidas:\n");
	printf("Nombre:%s\n",jugador2->nombre);
	printf("Salud:%d\n",jugador2->salud);
	printf("Nivel:%d\n",jugador2->nivel);
	printf("Puntaje:%d\n",jugador2->puntaje);
	printf("Jugador 3 por teclado usando punteros:\n");
	printf("Nombre:%s",jugador3->nombre);
	printf("Salud:%d\n",jugador3->salud);
	printf("Nivel:%d\n",jugador3->nivel);
	printf("Puntaje:%d\n",jugador3->puntaje);
	return 0;
}

