#include <stdio.h>
#include <stdlib.h>

#define quanti_termos 50
#define bem_formada 1
#define mal_formada 0

typedef struct {
    char elementos[quanti_termos];
    int ultima_posicao;

}pilha;

typedef struct {
    int elementos[quanti_termos];
    int ultima_posicao;

}pilha_num;

typedef struct {
    char elementos[quanti_termos];
    int ultima_posicao;

}pilha_op;

void computar();
void empilha(pilha *, char);
void empilhar_numero(pilha_num *, int);
void empilhar_operadores(pilha_op *, char);
void desempilha(pilha *);
void solicite_expressao(char *);
int  pilha_vazia(pilha);
int converte(char []);

int main (int argc, char *argv[])
{
    argc = argc;
    argv = argv;

    computar();

    return 0;

}

void computar()
{
    int i = 0;
    int contador = 0;
    int numero;
    char string[10];
    char expressao [quanti_termos];
    pilha pilha_especial;
    pilha_num pilha_nume; 
    pilha_op pilha_operando; 
    pilha_especial.ultima_posicao = 0;
    pilha_nume.ultima_posicao = 0;
    pilha_operando.ultima_posicao = 0;
    
    solicite_expressao(expressao);

    while (expressao[i] != '\0')
    {

        

        if(expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[')
        {
            empilha(&pilha_especial , expressao[i]);
            
        }
        if(expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']')
        {
            desempilha(&pilha_especial);
            
        }
        if(expressao[i] == '0' || expressao[i] == '1' || expressao[i] == '2' || expressao[i] == '3' || expressao[i] == '4'
        || expressao[i] == '5' || expressao[i] == '6' || expressao[i] == '7' || expressao[i] == '8' || expressao[i] == '9')
        {
            string[contador] = expressao[i];
            if(expressao[i + 1] == '0' || expressao[i + 1] == '1' || expressao[i + 1] == '2' || expressao[i + 1] == '3' || expressao[i + 1] == '4'
            || expressao[i + 1] == '5' || expressao[i + 1] == '6' || expressao[i + 1] == '7' || expressao[i + 1] == '8' || expressao[i + 1] == '9')
            {
                contador++;
                i++;
                continue;
            }
            else
            {
                numero = converte(string);
                empilhar_numero(&pilha_nume, numero);
            }
        }

        if (expressao[i] == '+' ||expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/' )
        {
            empilhar_operadores(&pilha_operando,expressao[i]);

        }








        i++;
    }

    if(pilha_vazia(pilha_especial) == 0)
    {
        printf("pilha vazia");
    }
    else 
    {
        printf("tem conteudo");
    }


}

int converte(char string[])
{

    int numero;

    numero = atoi(string);

    return numero;
}


void empilhar_operadores(pilha_op *pilha_oper, char elemento)
{
    if(pilha_oper->ultima_posicao == quanti_termos)
    {
        printf("pilha cheia");
    }
    else 
    {
        pilha_oper->elementos[pilha_oper->ultima_posicao] = elemento;
        pilha_oper->ultima_posicao++;    
    }

}
void empilhar_numero(pilha_num *pilha, int numero)
{
    if(pilha->ultima_posicao == quanti_termos)
    {
        printf("pilha cheia");
    }
    else
    {
        pilha->elementos[pilha->ultima_posicao] = numero;
        pilha->ultima_posicao++; 
    }
}

void empilha(pilha *pilha_especial, char elemento) 
{
    if(pilha_especial->ultima_posicao == quanti_termos)
    {
        printf("pilha cheia");
    }
    else 
    {
        pilha_especial->elementos[pilha_especial->ultima_posicao] = elemento;
        pilha_especial->ultima_posicao++;    
    }
}

void desempilha(pilha *pilha_especial)
{
    pilha_especial->ultima_posicao--;
    

}

void solicite_expressao(char expressao[])
{

    printf("digite uma expressao:");
    scanf("%s", expressao);

}

int pilha_vazia(pilha pilhasvazia)
{
    if (pilhasvazia.ultima_posicao == 0)
    {
        return  0;
    }
    else
    {
        return  1;

    }

}

/*gcc bemformada.c -o bemformada.exe -Wall -Werror -pedantic -Wextra*/