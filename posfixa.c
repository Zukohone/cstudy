# include <stdio.h>
# include <stdlib.h>
#include <ctype.h>
#include<stdbool.h>

typedef struct _Pilha
{
    char op;
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

void alocaCharNaPilha( Pilha **pilha, Pilha *aux, char op )
{
    aux = ( Pilha *) malloc( sizeof( Pilha ) );
    aux -> op = op;  
    aux -> prox = *pilha;
    *pilha = aux;
}

void leOperacao( Pilha **pPos, Pilha **pTemp )
{
    char op;
    Pilha *aux;
    
    scanf( "%c", &op );

    while( op != '\n' )
    {
		if( !isdigit(op) && op !='+' && op !='-' && op !='*' && op !='/'){
			charInvalido = true;
			printf("Expressao invalida");
		return;
		}

        switch( op )
        {
            case '+':
            case '-':

                while(*pTemp)
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            case '*':
            case '/':

                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-') )
                {        
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            default:
                alocaCharNaPilha( &( *pPos ), aux, op );
                
                break;
        }

        scanf( "%c", &op );
    }

    while( *pTemp )
	{
		transfereTempPos( &( *pPos ), &( *pTemp ), aux );
	}
    
}

void imprime( Pilha *topo )
{
    if( topo )
    {
        imprime( topo -> prox );
        printf( "%c", topo -> op );
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
		imprime( pPos );
		printf( "\n" );
	}

    return 0;
}