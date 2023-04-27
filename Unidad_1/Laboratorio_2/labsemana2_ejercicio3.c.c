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
//funcion encargada de agregar un objeto al inventario fusionado de ambos jugadores
void agregar(int arr3[],int varmax, int varmax2, int aux)
{
	printf("a que item le desea agregar?:\n");
	scanf("%d",&aux);
	if(arr3[aux]>=1)
	{
		arr3[aux]+=1;
	}
	if(arr3[aux]==0)
	{
		arr3[aux]=1;
	}
	for(aux=0; aux<max && aux<varmax || aux<varmax2 ;aux++)
	{
	printf("Item[%d]=%d\n",aux,arr3[aux]);
	}
}
//funcion encargada de eliminar un objeto del inventario fusionado de ambos jugadores
void eliminar(int arr3[],int varmax, int varmax2, int aux)
{
	printf("a que item le quiere eliminar la cantidad?:\n");
	scanf("%d",&aux);
	if(arr3[aux]>1)
	{
		arr3[aux]-=1;
	}
	if(arr3[aux]==1)
	{
		arr3[aux]=0;
	}
	for(aux=0; aux<max && aux<varmax || aux<varmax2 ;aux++)
	{
	printf("Item[%d]=%d\n",aux,arr3[aux]);
	}
	
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
	int aux=0;
	int aux2=0;
	int k=0;
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
	
	//menu que se encargara de saber que es lo que quiere hacer el usuario
	while(k!=3)
	{
		printf("si desea ingresar un articulo al inventario final marque 1:\n");
		printf("si desea eliminar un articulo al inventario final marque 2:\n");
		printf("si no desea hacer nada marque 3:\n");
		scanf("%d",&k);
		if(k==1)
		{
			agregar(arr3,varmax,varmax2,aux);
		}
		if(k==2)
		{
			eliminar(arr3,varmax,varmax2,aux);
		}
		if(k==3)
		{
			exit(-1);
		}
	}
	
	return 0;
}
