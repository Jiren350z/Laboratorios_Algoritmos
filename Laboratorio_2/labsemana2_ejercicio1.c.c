#include<stdio.h>
#define max 100 //esta funcion define el tamaño maximo del inventario

//funcion encargada de imprimir el inventario del jugador 
void imprimir(int arr[], int varmax)
{
	int i;
	for(i=0; i<max && i<varmax;i++ )
	{
		printf("item[%d]=%d\n",i,arr[i]);
	}
	printf("\n");	
	printf("la cantidad de objetos es %d\n",i);
	
}
//funcion encargada de definir la cantidad de cada item del inventario
void definir(int obj, int arr[], int varmax)
{
	int i;
	
	for(i=0;i<varmax;i++)
	{
		printf("defina la cantidad del Item %d:\n",i);
		scanf("%d",&obj);
		arr[i]=obj;
		printf("El Item %d va a tener %d objeto/s\n",i,obj);
	}
	printf("\n");	
		
}

int main()
{
	//definicion de variables
	int arr[max]={0};
	int varmax = 0;
	int obj=0;
	printf("Defina la cantidad de objetos que va a tener \n");
	scanf("%d",&varmax);
	//lamando funciones
	imprimir(arr,varmax);
	definir(obj,arr,varmax);
	imprimir(arr,varmax);
		
	return 0;
}
