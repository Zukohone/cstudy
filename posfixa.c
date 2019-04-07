# include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool end=false;
void checkEnd();

void main()
{
	int a;
	while (!end) //Enquanta nao termina a expressao ler os valores
	{
	printf("\nDigite um numero: \n");
    scanf("%d", &a);
	checkEnd();
	}
}

void checkEnd(){
	int verf=0;
	printf("\nJa terminou a expressao (0 para terminar)? \n");
    scanf("%d", &verf);
	if(verf==0){
		end = true;
	}else{
		end = false;
	}
}