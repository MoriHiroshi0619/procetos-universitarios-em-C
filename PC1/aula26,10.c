 /*#include <stdio.h>
void push(int );
int pop(void);
int stack[50], *tos,*pl;
void main(void){
    int value;
    tos = stack;
//Faz tos conter o topo da pilha 
    pl = stack;	//inicializa pl 
    do {
       printf("Entre com o valor: (0) Pop, (-1) Sair, Caso contrario Push : ");
       scanf("%d",&value);
       if(value!=0)
          push(value);
       else
          printf("Valor do topo = %d\n",pop());
     }while(value != -1);
}
void push(int i){
	pl++;
	if(pl==(tos+50)){
	    printf("Estouro da pilha");
	    exit(1);
	}
	*pl = i;
}
int pop(void){
	if(pl==tos){
	    printf("Pilha vazia");
	    exit(1);
	}
	pl--;
	return *(pl+1);
}
*/

/*
#include <stdio.h>
void push(int );
int pop(void);
int stack[50], *tos,*pl;
void main(void){
    int value;
    tos = stack;
//Faz tos conter o topo da pilha 
    pl = stack;	//inicializa pl 
    do {
       printf("\nEntre com o valor: (0) Pop, (-1) Sair, Caso contrario Push : ");
       scanf("%d",&value);
       if(value!=0)
          push(value);
       else
          printf("\nTirando valor do topo = %d\n",pop());
     }while(value != -1);
}
void push(int i){
    int *p=tos;
	pl++;
	if(pl==(tos+50)){
	    printf("Estouro da pilha");
	    exit(1);
	}
	*pl = i;
	for ( ;p<=pl ; p++)
        printf ("%d\t", *p);
}
int pop(void){
    int *p=tos;
	if(pl==tos){
	    printf("Pilha vazia");  
	    exit(1);
	}
	pl--;
	for ( ;p<=pl ; p++)
        printf ("%d\t", *p);

	return *(pl+1);

}
*/



/*void lePonto3D(ponto3d *f);: lê dados de uma ponto no espaço tridimensional com coordenadas (x,y,z) passada como ponteiro. (Por quê como ponteiro?)
void imprimePonto3D(ponto3d f); Imprime coordenadas de um ponto.
O programa principal que requeira a leitura de 5 pontos no espaço tridimensional
*/
/*
#include <stdio.h>
typedef struct {
   float x;
   float y;
   float z;
} ponto3d;

void lePonto3D(ponto3d *);
void imprimePonto3D(ponto3d );

int main(){
    int i;
//    O programa principal que requeira a leitura de 5 pontos no espaço tridimensional
    ponto3d p[5];
    for (i=0;i<5; i++){
        lePonto3D(&p[i]);
        imprimePonto3D(p[i]);
    }
}
void lePonto3D(ponto3d *f){
   printf ("\nInforme as coordenadas (x,y,z) do ponto: ");
   scanf ("%f %f %f", &(f->x), &(f->y), &(f->z));
}
void imprimePonto3D(ponto3d f){
  printf ("%f %f %f", f.x, f.y, f.z);

}
*/

/*
#include <stdio.h>

typedef struct {
   float x;
   float y;
   float z;
} ponto3d;

void lePonto3D(ponto3d *);
void imprimePonto3D(ponto3d );
float ProdutoEscalar(ponto3d,ponto3d);

int main(){
    int i;
//    O programa principal que requeira a leitura de 5 pontos no espaço tridimensional
    ponto3d p[5];
    for (i=0;i<5; i++){
        lePonto3D(&p[i]);
        imprimePonto3D(p[i]);
    }
    for (i=0; i<4 ; i++)
       printf ("\nProduto escalar entre p[%d] e p[%d] = %f", i, i+1, ProdutoEscalar(p[i],p[i+1]));
}
void lePonto3D(ponto3d *f){
   printf ("\nInforme as coordenadas (x,y,z) do ponto: ");
   scanf ("%f %f %f", &(f->x), &(f->y), &(f->z));
}
void imprimePonto3D(ponto3d f){
  printf ("%f %f %f", f.x, f.y, f.z);
}
float ProdutoEscalar(ponto3d f1,ponto3d f2){
     float pe;
     pe=f1.x*f2.x + f1.y*f2.y + f1.z*f2.z;
     return (pe);
}

*/





#include <stdio.h>
#include <stdlib.h>

struct lista{ // definicao da estrutura Lista, a qual eh uma lista simplesmente encadeada com um valor inteiro
    int info;
    struct lista *prox;
};

typedef struct lista Lista; // estrutura "lista" passa a ser o tipo de dados "Lista"
    int tam;
// Prototipos de funcoes e procedimentos
int menu(void);
void inicia(Lista*PILHA);
void opcao(Lista*PILHA, int op);
void exibe(Lista *PILHA);
void libera(Lista *PILHA);
void push(Lista *PILHA);
Lista *pop(Lista *PILHA);
//Programa Principal


int main(void) {
    int opt;
    Lista *PILHA = (Lista *) malloc(sizeof(Lista)); // Alocacao de memoria do primeiro elemento da lista
    if(!PILHA){
        printf("Sem memoria disponivel!\n"); exit(1);
    }else{ // Se a alocacao tiver sucesso entraremos em um menu do qual sairemos so quando a opcao for 0
        inicia(PILHA);
    do{
        opt=menu();
        opcao(PILHA,opt);
    }while(opt);
    free(PILHA);
    }
}

void inicia(Lista *PILHA) {
    PILHA->prox = NULL; tam=0;
}

int menu(void) {
    int opt;
    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar PILHA\n");
    printf("2. Exibir PILHA\n");
    printf("3. PUSH\n");
    printf("4. POP\n");
    printf("Opcao: ");
    scanf("%d", &opt);
    return opt;
}


void opcao(Lista *PILHA, int op) {
    Lista *tmp;
    switch(op){
        case 0:
        libera(PILHA);
        break;
        case 1:
        libera(PILHA);
        inicia(PILHA);
        break;
        case 2:
        exibe(PILHA);
        break;
        case 3:
        push(PILHA);
        break;
        case 4:
        tmp= pop(PILHA);
        if(tmp != NULL) printf("Retirado: %3d\n\n", tmp->info);
        break;
        default:
        printf("Comando invalido\n\n");
    }
}


int vazia(Lista *PILHA) {
    if(PILHA->prox == NULL)
    return 1;
    else return 0;
}


Lista *aloca() {
    Lista *novo=(Lista *) malloc(sizeof(Lista));
    if(!novo){
        printf("Sem memoria disponivel!\n"); exit(1);
    }
    else{
        printf("Novo elemento: "); scanf("%d", &novo->info);
        return novo; 
    }
}


void exibe(Lista *PILHA) {
    if(vazia(PILHA)){ 
        printf("PILHA vazia!\n\n"); return ; 
    }
    Lista *tmp;
    tmp = PILHA->prox;
    printf("PILHA:");
    while( tmp != NULL){
        printf("%5d", tmp->info);
        tmp = tmp->prox;
    }
    printf("\n ");
    int count;
    for(count=0 ; count < tam ; count++)
        printf(" ^ ");
        printf("\nOrdem:");
    for(count=0 ; count < tam ; count++)
        printf("%5d", count+1);
        printf("\n\n");
}


void libera(Lista *PILHA) {
    if(!vazia(PILHA)){
        Lista *proxNo, *atual;
        atual = PILHA->prox;
        while(atual != NULL){
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
    }
}


void push(Lista *PILHA) {
    Lista *novo=aloca();
    novo->prox = NULL;
    if(vazia(PILHA)) 
        PILHA->prox=novo;
    else{ 
        Lista *tmp = PILHA->prox;
        while(tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
    }
    tam++;
}


Lista *pop(Lista *PILHA) {
    if(PILHA->prox == NULL){
        printf("PILHA ja vazia\n\n");
        return NULL; 
    }else{
        Lista *ultimo = PILHA->prox, *penultimo = PILHA;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL; tam--;
        return ultimo;
    }
}
