
#include <stdio.h> /*printf()*/
#include "expressaoHeader.h" /*empilhar(), inicializar_pilha(), desempilhar(), desempilhar_simbolo(), percorrer_expressao()
                            verifica_pilha_vazia(), verifica_caracter_valido(), verificar_prox_simbolo(), verificar_prox_num()
                            expressao_sem_espaco(), resultado()*/



void percorrer_expressao (PILHA *pilha_simbolos, char expressao[], int *bem_formado, PILHA *pilha_operadores, PILHA *pilha_operandos)
{
    int i; /*i para percorrer o for*/
    

    for( i = 0 ; expressao[i] != '\0' ; i++) /*percorrer cada caracter ate o fim da string*/
    {
        
        
        /*se for um abrimento de simbolo, entra no if*/
        if(expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[')
        {
            empilhar(pilha_simbolos, expressao[i]); /*empilha o simbolo na pilha de simbolos*/

            /*se o proximo caracter for um fechamento de simbolo que dizer que nao tem conteudo dentro dos simbolos*/
            if(verificar_prox_simbolo(expressao[i+1], expressao[i]))
            {
                *bem_formado = 0; /*torna falso a variavel logica*/
                
            }
            
        }

        /*se for um fechamento de simbolo, entra no if */
        if(expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']')
        {
            desempilhar_simbolo(pilha_simbolos, expressao[i]); /*desempilha da pilha de simbolos*/

            /*se o proximo caracter for um numero, ta errado pois deveria vir antes um operando por exemplo*/
            if(verificar_prox_simbolo_fecha(expressao[i+1]))
            {
                *bem_formado = 0; /*torna falso a variavel logica*/
                
            }
        }

        /*verifica se eh um operador*/
        if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '/' || expressao[i] == '*')
        {
            empilhar(pilha_operadores, expressao[i]); /*empilha na pilha dos operandos*/
        }

        /*verifica se eh um numero*/
        if(expressao[i] >= '0' && expressao[i] <= '9')
        {

            /*verifica se o procimo caracter tambem eh um numero, se for eh porque eh um numero com mais de um digito ou mais*/
            if(expressao[i + 1] >= '0' && expressao[i + 1] <= '9')
            {
                continue; /*pula para o proximo caracter pois todo o resto das verificoes eh inutil se nao estiver no ultimo caracter de um numero de mais de um digito*/
            }

            /*se logo apos o ultimo digito for um abrimento de simbolo, esta errado*/
            if(verificar_prox_num(expressao[i+1]))
            {
                *bem_formado = 0; /*torna falso a variavel logica*/
                
            }

            /*verifica se o caracter atual eh um numero, simbolo ou operador*/
            if(!verifica_caracter_valido(expressao[i])) 
            {
                *bem_formado = 0; /*torna falso a variavel logica*/
                
            }

            /*se a pilha dos operadores estiver fazia eh porque esse numero esta na parte esquerda do operador*/
            if(!verifica_pilha_vazia(*pilha_operadores))
            {
                /*empilhar o numero na pilha dos operandos*/
                empilhar(pilha_operandos, expressao[i]);
            }
            else /*se nao tiver que dizer que o numero esta do lado direito do operador, o que conclui uma sub-expressao*/
            {
                do
                {
                    desempilhar(pilha_operandos); /*desempilha o topo da pilha*/
                }while(pilha_operandos->vetor[pilha_operandos->topo] != ' '); /*vai desempilhar ate esvazear a pilha*/
              

                desempilhar(pilha_operadores); /*desempilha o topo da pilha*/

            }
        }

        /*verifica se algo nao esta sendo dividido por 0, se estiver esta errado*/
        if(expressao[i] == '/')
        {
            if(expressao[ i + 1 ] == '0')
            {
                *bem_formado = 0; /*torna falso a variavel logica*/
                
            }
        }



    }

    /*verifica se a pilha dos simbolos esta vazia, se nao estiver eh porque sobrou algo que nao deveria*/
    if(verifica_pilha_vazia(*pilha_simbolos))
    {
        *bem_formado = 0; /*torna falso a variavel logica*/
    }

    /*verifica se a pilha dos operadores esta vazia, se nao estiver eh porque sobrou algo que nao deveria*/
    if(verifica_pilha_vazia(*pilha_operadores))
    {
        *bem_formado = 0; /*torna falso a variavel logica*/
    }

    /*verifica se a pilha dos operandos esta vazia, se nao estiver eh porque sobrou algo que nao deveria*/
    if(verifica_pilha_vazia(*pilha_operandos))
    {
        *bem_formado = 0; /*torna falso a variavel logica*/
    }

    /*verifica se o primeiro caracter nao eh uma divisao ou multiplicacao*/
    if(expressao[0] == '/' || expressao[0] == '*')
    {
        *bem_formado = 0; /*torna falso a variavel logica*/
    }
    
}

int verificar_prox_num (char elemento)
{
    int a = 0; /*variavel logica*/

    /*verificao dos elementos, se for igual torna verdadeiro a variavel logica*/
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


    return a;/*retorna variavel logica*/
}

int verifica_caracter_valido(char elemento)
{
    int a = 0; /*variavel logica*/

    /*verificao dos elementos, se for igual torna verdadeiro a variavel logica*/
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
        case '(':
            a = 1;
            break;
        case '{':
            a = 1;
            break;
        case '[':
            a = 1;
            break;
        case ')':
            a = 1;
            break;
        case '}':
            a = 1;
            break;
        case ']':
            a = 1;
            break;
        case '+':
            a = 1;
            break;
        case '-':
            a = 1;
            break;
        case '*':
            a = 1;
            break;
        case '/':
            a = 1;
            break;
        default:
            break;
    }

    return a; /*retorna variavel logica*/
}

int verificar_prox_simbolo_fecha(char elemento)
{
    int a = 0; /*variavel logica*/

    /*verificao dos elementos, se for igual torna verdadeiro a variavel logica*/
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

    return a; /*retorna variavel logica*/
}

int verificar_prox_simbolo(char elemento, char elemento_atual)
{
    int a = 0; /*variavel logica*/

    /*verificao dos elementos, se for igual torna verdadeiro a variavel logica*/
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

    /*verifica se nao esta havendo duas aberturas do mesmo simbolo*/
    if(elemento == elemento_atual)
    {
        a = 1;
    }

    return a; /*retorna variavel logica*/
}

MSG empilhar (PILHA *pilha, char elemento)
{
    /*verifica se a pilha esta cheia ou nao*/
    if(pilha->topo == TAMANHO_EXPRESSAO)
    {
        return FALHA;
    }
    else /*se nao tiver cheia empilha o elemento*/
    {
        pilha->vetor[pilha->topo] = elemento; /*empilhando o elemnto no topo*/
        pilha->topo++; /*atualizando o topo*/
        return SUCESSO;
    }
       
}

void inicializar_pilha (PILHA *pilha)
{
    int i; /*i de for */

    pilha->topo = 0; /*inicializando topo*/

    /*preenchendo o vetor com ' '*/
    for( i = 0 ; i < TAMANHO_EXPRESSAO ; i++)
    {
        pilha->vetor[i] = ' ';
    }
}

MSG desempilhar (PILHA *pilha)
{
    /*verifica se a pilha nao esta vazia*/
    if(pilha->topo == 0)
    {
        return FALHA;
    }
    else /*se nao estiver, desempilhar*/
    {
        pilha->topo--; /*retorna pro topo aonde tem um elemento diferente de ' '*/
        pilha->vetor[pilha->topo] = ' '; /*volta a preencher com ' '*/
        return SUCESSO;
    }
   
}


void desempilhar_simbolo (PILHA *pilha, char elemento)
{

    
    /*vericando se o simbolo que esta fechando eh da mesma categoria que abril anteriormente*/
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
            }else /*caso nao seja da mesma categoria, em vez de desempilhar vamos empilhar ele, desse modo a pilha vai sempre ter um elemento, o que ira acusar
                    um erro na hr da vericacao da verifica_pilha_vazia()*/
            {
                empilhar(pilha, elemento); /*empilha o elemento no topo*/
            }


}


int verifica_pilha_vazia (PILHA pilha)
{
    int a = 0; /*variavel logica*/
    int i; /*i de for*/

    for( i = 0 ; i < TAMANHO_EXPRESSAO ; i++)
    {
        /*verifica se algum elemento do vetor eh diferente de ' ', se for eh porque ela tem algum elemento*/
        if (pilha.vetor[i] != ' ')
        {
            a = 1; /*torna falso a variavel logica*/
            
        }
    }

    return a;
    
}

void expressao_sem_espaco (char expressao_aux[], char expressao[])
{
    int contador = 0; /*ira percorrer a string principal*/
    int i; /*i de for*/
    
    for( i = 0 ; expressao_aux[i] != '\0' ; i++) /*percorrera toda a string auxiliar*/
    {
        /*enquanto o elemento da auxiliar for diferente de espaco em branco vai ir copiando para a principal*/
        if(expressao_aux[i] != ' ') 
        {
            expressao[contador] = expressao_aux[i]; /*copia*/
            contador++; /*atualiza posicao da principal*/
        }
    }

}


void resultado(int bem_formado)
{
    /*imprime a mensagem final*/
    if(bem_formado)
    {
        printf("\nexpressao bem formado.");
    }
    else
    {
        printf("\nexpressao mal formada.");
    }
}



