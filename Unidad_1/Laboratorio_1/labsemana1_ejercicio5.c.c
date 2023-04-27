#include<stdio.h>
#include<stdlib.h>

int main()
{
	//declaracon de variables
	int N=7,pos, aux, aux2, j;
	//variable random
	srand(time(NULL));
	int arreglo[N];
	//codigo encargado de recorrer el arreglo
	//ademas de llenarlo de numeros aleatorios
	//que a su vez representan a las piezas del tetris
	//y a la vez verifica que si hay un numero repetido este se randomiza
	for(pos=0;pos<N;pos++)
	{
		arreglo[pos]= rand()%7;
		if(pos >=0)  
		{
		for(j=0; j< pos; j++)  
		{  
		while(arreglo[pos]==arreglo[j]) 
			{
				if(arreglo[pos]==arreglo[j]) 
				{ 
				arreglo[pos]= rand()%7+1;
				}
			}
		}
	}
}
			

	printf("\t\tSIMULADOR DE PIEZAS DE TETRIS\n\n");
	for(pos=0; pos<N; pos++)
	{		
		printf("TURNO[%d]=Pieza %d\n",pos,arreglo[pos]);		
	}	


return 0;
}
	

