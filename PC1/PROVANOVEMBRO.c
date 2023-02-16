/*#include "stdio.h"
void main(void){
    int x = 5 , y = 6;
    int *px,*py;
    px = &x;
    py=&y;
    if(px<py)
        printf("py-px = %u\n",py-px);
    else
        printf("px-py = %u\n",px-py);
        printf("px = %u, *px = %d, &px = %u\n",px,*px,&px);
        printf("py = %u, *py = %d, &py = %u\n",py,*py,&py);
        px++;
        printf("px = %u, *px = %d, &px = %u\n",px,*px,&px);
        py=px+3;
        printf("py = %u, *py = %d, &py = %u\n",py,*py,&py);
        printf("py-px = %u\n",py-px);
}
*/
void teste(int *px, int *py) {
    px = py;
    *py = (*py) * (*px);
    
    *px = *px + 2;
    }
int main(void) {
    int x, y;                   // 3      4
    scanf("%d",&x);
    scanf("%d",&y);
    teste(&x,&y);
    printf("x = %d, y = %d", x, y);
}