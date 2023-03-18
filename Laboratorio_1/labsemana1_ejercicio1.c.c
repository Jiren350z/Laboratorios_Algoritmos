#include <stdio.h>
#include <stdlib.h>
//programa encargado de evidenciar todos los tipos de datos basicos en c
int main()
{
//variable que define el tamaño del arreglo	
int c=40;
int i;	
//dato de tipo entero	
int n=12;
//dato de tipo decimal	
float f = 3.14 ;
//dato de tipo double
double d = 2.1313131889;
//dato de tipo caracter	
char a[] = "Saquenme de la UTAL xfavor";
	
	printf("Dato de Tipo CHAR(caracter):\n");
	for(i=0; i<c; i++)
	{
		printf("%c",a[i]);
	}
printf("\n");
printf("Dato de Tipo INT(entero):%i\n",n);
printf("Dato de Tipo FLOAT(decimal):%f\n",f);
printf("Dato de Tipo DOUBLE(decimal grande):%.10f",d);
return 0;	
}
