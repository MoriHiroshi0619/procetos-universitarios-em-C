/**********************************************************************************************************/


/*main*/
/*

#include <stdio.h>
#include "expressaoHeader.h"

int main(int argc, char *argv[])
{
    PILHA pilha_simbolos;
    PILHA pilha_operandos;
    PILHA pilha_operadores;
    int bem_formado = 1;
    char expressao[TAMANHO_EXPRESSAO];
    char expressao_aux[TAMANHO_EXPRESSAO];
    
    argc = argc;
	argv = argv;

    inicializar_pilha(&pilha_simbolos);
    inicializar_pilha(&pilha_operadores);
    inicializar_pilha(&pilha_operandos);

    printf("digite uma expressao matematica: ");
    fgets(expressao_aux, TAMANHO_EXPRESSAO, stdin);
    expressao_sem_espaco(expressao_aux, expressao);

    percorrer_expressao(&pilha_simbolos, expressao, &bem_formado, &pilha_operadores, &pilha_operandos);
    
    if(bem_formado)
    {
        printf("expressao bem formado.");
    }
    else
    {
        printf("expressao mal formada.");
    }

    return 0;
}/*


/**********************************************************************************************************/


/*header C*/
/*

#include <stdio.h>
#include "expressaoHeader.h"



void percorrer_expressao (PILHA *pilha_simbolos, char expressao[], int *bem_formado, PILHA *pilha_operadores, PILHA *pilha_operandos)
{
    int i;
    

    for( i = 0 ; expressao[i] != '\0' ; i++)
    {
        

        if(expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[')
        {
            empilhar(pilha_simbolos, expressao[i]);

            if(verificar_prox_simbolo(expressao[i+1], expressao[i]))
            {
                *bem_formado = 0;
            }
            
        }

        if(expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']')
        {
            desempilhar_simbolo(pilha_simbolos, expressao[i]);

            if(verificar_prox_simbolo_fecha(expressao[i+1]))
            {
                *bem_formado = 0;
            }
        }

        if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '/' || expressao[i] == '*')
        {
            empilhar(pilha_operadores, expressao[i]);
        }

        if(expressao[i] >= '0' && expressao[i] <= '9')
        {
            if(expressao[i + 1] >= '0' && expressao[i + 1] <= '9')
            {
                continue;
            }

            if(verificar_prox_num(expressao[i+1]))
            {
                *bem_formado = 0;
            }

            if(!verifica_pilha_vazia(*pilha_operadores))
            {
                empilhar(pilha_operandos, expressao[i]);

            }
            else
            {
                do
                {
                    desempilhar(pilha_operandos);
        
                }while(pilha_operandos->vetor[pilha_operandos->topo] != ' ');
              

                desempilhar(pilha_operadores);

            }
        }


        if(expressao[i] == '/')
        {
            if(expressao[ i + 1 ] == '0')
            {
                *bem_formado = 0;
            }
        }

    }

    if(verifica_pilha_vazia(*pilha_simbolos))
    {
        *bem_formado = 0;
    }

    if(verifica_pilha_vazia(*pilha_operadores))
    {
        *bem_formado = 0;
    }

    if(verifica_pilha_vazia(*pilha_operandos))
    {
        *bem_formado = 0;
    }

    if(expressao[0] == '/' || expressao[0] == '*')
    {
        *bem_formado = 0;
    }
    
}

int verificar_prox_num (char elemento)
{
    int a = 0;

    switch ( elemento )
    {
        case '(':
            a = 1;
            break;
        case '[':
            a = 1;
            break;
        case '{':
            a = 1;
            break;
        default:
            break;
    }


    return a;
}

int verificar_prox_simbolo_fecha(char elemento)
{
    int a = 0;

    switch ( elemento )
    {
        case '0':
            a = 1;
            break;
        case '1':
            a = 1;
            break;
        case '2':
            a = 1;
            break;
        case '3':
            a = 1;
            break;
        case '4':
            a = 1;
            break;
        case '5':
            a = 1;
            break;
        case '6':
            a = 1;
            break;
        case '7':
            a = 1;
            break;
        case '8':
            a = 1;
            break;
        case '9':
            a = 1;
            break;
        default:
            break;
    }

    return a;
}

int verificar_prox_simbolo(char elemento, char elemento_atual)
{
    int a = 0;

    switch ( elemento )
    {
        case ')':
            a = 1;
            break;
        case ']':
            a = 1;
            break;
        case '}':
            a = 1;
            break;
        default:
            break;
    }

    if(elemento == elemento_atual)
    {
        a = 1;
    }

    return a;
}

void empilhar (PILHA *pilha, char elemento)
{

    pilha->vetor[pilha->topo] = elemento;
    pilha->topo++;
    
    
}

void inicializar_pilha (PILHA *pilha)
{
    int i;

    pilha->topo = 0;

    for( i = 0 ; i < TAMANHO_EXPRESSAO ; i++)
    {
        pilha->vetor[i] = ' ';
    }
}

void desempilhar (PILHA *pilha)
{
    if(pilha->topo == 0)
    {
        printf("pilha esta vazia ja\n");
    }
    else
    {
        pilha->topo--;
        pilha->vetor[pilha->topo] = ' ';
    }
   

}


void desempilhar_simbolo (PILHA *pilha, char elemento)
{

    
    
    if(pilha->vetor[pilha->topo - 1] == '(' && elemento == ')')
    {
        pilha->topo--;
        pilha->vetor[pilha->topo] = ' ';
    }
        else if(pilha->vetor[pilha->topo - 1] == '[' && elemento == ']')
        {
            pilha->topo--;
            pilha->vetor[pilha->topo] = ' ';
        }
            else if(pilha->vetor[pilha->topo - 1] == '{' && elemento == '}')
            {  
                pilha->topo--;
                pilha->vetor[pilha->topo] = ' ';
            }else
            {
                empilhar(pilha, elemento);
            }


}


int verifica_pilha_vazia (PILHA pilha)
{
    int a = 0;
    int i;

    for( i = 0 ; i < TAMANHO_EXPRESSAO ; i++)
    {
        if (pilha.vetor[i] != ' ')
        {
            a = 1;
        }
    }

    return a;
    
}

void expressao_sem_espaco (char expressao_aux[], char expressao[])
{
    int contador = 0;
    int i;
    
    for( i = 0 ; expressao_aux[i] != '\0' ; i++)
    {
        if(expressao_aux[i] != ' ')
        {
            expressao[contador] = expressao_aux[i];
            contador++;
        }
    }

}*/


/**********************************************************************************************************/


/*

#ifndef _EXPRESSAOHEADER_
#define _EXPRESSAOHEADER_


#define TAMANHO_EXPRESSAO 1000

typedef struct
{
    int topo;
    char vetor[TAMANHO_EXPRESSAO];
}PILHA;

void empilhar (PILHA *, char);

void inicializar_pilha (PILHA *);

void desempilhar (PILHA *);

void desempilhar_simbolo (PILHA *, char);

void percorrer_expressao(PILHA *, char[], int *, PILHA *, PILHA *);

int verifica_pilha_vazia (PILHA);

int verificar_prox_simbolo (char, char);

int verificar_prox_simbolo_fecha (char);

int verificar_prox_num (char);

void expressao_sem_espaco(char[], char[]);

#endif

*/