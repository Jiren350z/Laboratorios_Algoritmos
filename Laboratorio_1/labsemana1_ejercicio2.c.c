#include<stdio.h>
#include<stdlib.h>
//operaciones aritmeticas 
//funcion sumar
int sumar(int a, int b)
{
	int resultadosuma;
	
	resultadosuma= a+b;
	return resultadosuma;
}
//funcion restar
int restar(int a, int b)
{
	int resultadoresta;
	
	resultadoresta=a-b;
	return resultadoresta;
	
}
//funcion multiplicacion
int multiplicar(int a, int b)
{
	int resultadomultiplicacion;
	
	resultadomultiplicacion=a*b;
	return resultadomultiplicacion;
}
//funcion divir
float dividir(int a, int b)
{
	float resultadodivision;
	
	resultadodivision=(float)a/b;
	return resultadodivision;
	
}
//con este menu el usuario define si quiere sumar restar o dividir los numeros a y b que desee
int main()
{
	int resultadosuma, resultadoresta,resultadomultiplicacion,a,b,op;
	float resultadodivision;
	printf("ingrese numero a:\n");
	printf("ingrese numero b:\n");
	scanf("%d %d",&a,&b);
	printf("marque 1 para sumar:\n");
	printf("marque 2 para restar:\n");
	printf("marque 3 para multiplicar:\n");
	printf("marque 4 para dividir:\n");
	scanf("%d",&op);
	//dependiendo de la opcion elegida se llamara a la funcion destinada a sumar, dividir o restar 
	if(op==1)
	{	                
		resultadosuma=sumar(a,b);	
		printf("el resultado de la suma es: %d\n",resultadosuma);
	}
	if(op==2)
	{
		resultadoresta=restar(a,b);
		printf("el resultado de la resta es: %d\n",resultadoresta);
	}
	if(op==3)
	{
		resultadomultiplicacion=multiplicar(a,b);
		printf("el resultado de la multiplicacion es: %d\n",resultadomultiplicacion);
	}
	if(op==4)
	{
		resultadodivision=dividir(a,b);
		printf("el resultado de la division es: %f\n",resultadodivision);
	}
	
	
}


