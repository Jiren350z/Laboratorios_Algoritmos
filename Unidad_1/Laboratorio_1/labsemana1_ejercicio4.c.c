#include<stdio.h>
#include<stdlib.h>
int main()
{
	//matriz de caracteres
	char matriz[3][3];
	int i,j;
	//construyendo la matriz
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			//llenando la matriz de las jugadas
			matriz[i][j]=' ';
			matriz[0][0]='X';
			matriz[1][1]='X';
			matriz[2][2]='X';
			matriz[1][2]='O';
			matriz[2][1]='O';
			matriz[1][0]='O';
			matriz[2][0]='O';
			matriz[0][1]='O';
			matriz[0][2]='O';
			//imprimiendo la matriz
			printf("[%c]",matriz[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
