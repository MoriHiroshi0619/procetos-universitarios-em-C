

#include <stdio.h>
void imprime_vetor(int v[], int n){
   int i;
   for (i = 0; i < n; i++)
      printf("%d ", v[i]);
   printf("\n");
}
void imprime_vetor2(int *p, int n){
   int i;
   for (i = 0; i < n; i++) {
       printf("%d ", *p);
       p++;
   }
   printf("\n");
}
int main() {
   int v[] = {10, 20, 30, 40, 50};
   imprime_vetor(v, 5);
   imprime_vetor2(v, 5);
   imprime_vetor(&v[1], 4);
   imprime_vetor2(&v[1], 4);
}



#include <stdio.h>
#define MAX 5
int main() {
   int v[] = {10, 20, 30, 40, 50}, i,*p,s=0;
   p=v;
   for (i=0;i<MAX; ++i)
      s+=p[i];
   printf ("Soma1=%d\n",s);
   for (s=i=0; i<MAX;++i)
      s+=*(v+i);
   printf ("Soma2=%d\n",s);
   for (s=0,p=v;p<&v[MAX];++p)
      s+=*p;
   printf ("Soma3=%d\n",s);
}



#include <stdio.h>
#define MAX 5
/*prof uma vez a senhora disse que atribuir o & indicaria endereco.
p = v diz que o conteudo de p = v....
porem p e v tem enderecos diferentes?
*/
int main() {
   int v[] = {10, 20, 30, 40, 50}, i,*p,s=0;
   p=v;
   printf ("Endereco de p %d\n", &p);
   printf ("Conteudo de p %d\n", p);
   printf ("Endereco do vetor v %d\n",v );
   printf ("Endereco do elemento v[0] %d\n",&v[0]);
   printf ("Conteudo do elemento v[0] %d\n",v[0]);
   printf ("Endereco do elemento v[1] %d\n",&v[1]);
   printf ("Conteudo do elemento v[1] %d\n",v[1]);
   printf ("Endereco do elemento v[2] %d\n",&v[2]);
   printf ("Conteudo do elemento v[2] %d\n",v[2]);
   printf ("Endereco do elemento v[3] %d\n",&v[3]);
   printf ("Conteudo do elemento v[3] %d\n",v[3]);
   printf ("Endereco do elemento v[3] %d\n",&v[4]);
   printf ("Conteudo do elemento v[3] %d\n",v[4]);

   for (i=0;i<MAX; ++i)
      s+=p[i];
   printf ("Soma1=%d\n",s);
   for (s=i=0; i<MAX;++i)
      s+=*(v+i);
   printf ("Soma2=%d\n",s);
   for (s=0,p=v;p<&v[MAX];++p)
      s+=*p;
   printf ("Soma3=%d\n",s);
}




#include <stdio.h>
int main() {
   int r,*s, p;
   float q;
    p =10;
    q =40.5;
    s =&p;
    printf("valor de s = 0x%x\n", s);
    printf("endereço de s = 0x%x\n", &s);
    printf("valor de p = %d\n", p);
    printf("endereço de p = 0x%x\n", &p);
}



#include <stdio.h>
int main() {
   int x,y,*p,*q;
   x=15;
   printf("valor de x = %d\n", x);
   p=&x;
   q=&x;
   *q=2967;
   printf("valor de x = %d\n", x);
   *p=642362;
   printf("valor de x = %d\n", x);


}

