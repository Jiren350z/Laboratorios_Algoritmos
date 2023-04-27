#include<stdio.h>
#define max 100 //esta funcion define el tamaño maximo del inventario

//funcion encargada de imprimir el inventario del jugador 1
void imprimir(int arr[], int varmax)
{
	int i;
	for(i=0; i<max && i<varmax;i++ )
	{
		printf("item[%d]=%d\n",i,arr[i]);
	}
	printf("\n");	
	printf("la cantidad de objetos del jugador 1 es %d\n",i);
	
}
//funcion encargada de imprimir el inventario del jugador 2
void imprimir2(int arr2[], int varmax2)
{
	int i;
	for(i=0; i<max && i<varmax2;i++)
	{
		printf("item[%d]=%d\n",i,arr2[i]);
	}
	printf("\n");
	printf("la cantidad de objetos del jugador 2 es %d\n",i);
}
//funcion encargada de definir la cantidad de cada item del inventario del jugador 1
void definir(int obj, int arr[], int varmax)
{
	int i;
	
	for(i=0;i<varmax;i++)
	{
		printf("defina la cantidad del Item %d que va a tener el jugador 1:\n ",i);
		scanf("%d",&obj);
		arr[i]=obj;
		printf("El Item %d va a tener %d objeto/s\n",i,obj);
	}
	printf("\n");			
}
//funcion encargada de definir la cantidad de cada item del inventario del jugador 2
void definir2(int obj2, int arr2[], int varmax2)
{
	int i;
	for(i=0;i<varmax2;i++)
	{
		printf("defina la cantidad del Item %d que va a tener el jugador 2:\n",i);
		scanf("%d",&obj2);
		arr2[i]=obj2;
		printf("El Item %d va a tener %d objeto/s\n",i,obj2);
	}
	printf("\n");	
}
//funcion encargada de fusionar los items de los 2 jugadores
void fusion(int arr[], int arr2[], int varmax, int varmax2, int arr3[])
{
	int i;
	printf("Inventario Fusionado:\n");
	for(i=0;i<max && i<varmax || i<varmax2 ;i++)
	{        
	if(varmax>varmax2 ||varmax2>varmax || varmax == varmax2)
	{	
		arr3[i]= arr[i]+arr2[i];	
		printf("El Item %d tiene %d cantidad\n",i,arr3[i]); 
	}
	}
	printf("la cantidad de items del inventario fusionado es %d\n",i);
}
int main()
{
	//declaracion de variables
	int arr[max]={0};
	int arr2[max]={0};
	int arr3[max]={0};
	int varmax = 0;
	int varmax2 = 0;
	int obj=0;
	int obj2=0;
	printf("Defina la cantidad de objetos que va a tener el jugador 1 \n");
	scanf("%d",&varmax);
	imprimir(arr,varmax); 
	printf("Defina la cantidad de objetos que va a tener el jugador 2 \n");
	scanf("%d",&varmax2);
	imprimir2(arr2,varmax2);
	printf("Defina la cantidad de objetos de cada item que tendran los 2 jugadores\n");
	definir(obj,arr,varmax);
	definir2(obj2,arr2,varmax2);
	printf("Inventario jugador 1:\n");
	imprimir(arr,varmax);
	printf("Inventario jugador 2:\n");
	imprimir2(arr2,varmax2);
	fusion(arr,arr2,varmax,varmax2,arr3);	
	return 0;
}
