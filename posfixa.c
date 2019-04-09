# include <stdio.h>
# include <stdlib.h>
#include <ctype.h>
#include<stdbool.h>

typedef struct _Pilha
{
    char digito;
    struct _Pilha *prox;
}Pilha;

bool charInvalido;

void transfereTempPos( Pilha **pPos, Pilha **pTemp, Pilha *aux )
{
    aux = ( *pTemp ) -> prox;
    ( *pTemp ) -> prox = *pPos;
    *pPos = *pTemp;
    *pTemp = aux;
}

void addCharNaPilha( Pilha **pilha, Pilha *aux, char digito )
{
    aux = ( Pilha *) malloc( sizeof( Pilha ) );
    aux -> digito = digito;  
    aux -> prox = *pilha;
    *pilha = aux;
}

void leOperacao( Pilha **pPos, Pilha **pTemp )
{
    char digito;
    Pilha *aux;
    
    scanf( "%c", &digito );

    while( digito != '\n' )
    {
		if( !isdigit(digito) && digito !='+' && digito !='-' && digito !='*' && digito !='/'){
			charInvalido = true;
			printf("Expressao invalida");
		return;
		}

        switch( digito )
        {
            case '+':
            case '-':

                while(*pTemp)
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                addCharNaPilha( &( *pTemp ), aux, digito );
                
                break;

            case '*':
            case '/':

                while( ( *pTemp ) && ( (*pTemp) -> digito != '+' && (*pTemp) -> digito != '-') )
                {        
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                addCharNaPilha( &( *pTemp ), aux, digito );
                
                break;

            default:
                addCharNaPilha( &( *pPos ), aux, digito );
                
                break;
        }

        scanf( "%c", &digito );
    }

    while( *pTemp )
	{
		transfereTempPos( &( *pPos ), &( *pTemp ), aux );
	}
    
}

void mostraPilha( Pilha *topo )
{
    if( topo )
    {
        mostraPilha( topo -> prox );
        printf( "%c", topo -> digito );
    }   
}

int main()
{
    Pilha *pPos = NULL;
    Pilha *pTemp = NULL;

    printf( "Operacao Infixa: " );
    leOperacao( &pPos, &pTemp );
	if(!charInvalido){
		printf( "Operacao Posfixa: " );
		mostraPilha( pPos );
		printf( "\n" );
	}

    return 0;
}
