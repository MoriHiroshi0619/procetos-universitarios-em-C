#include <stdio.h>
#include "geometria.h"

int main(){
    Retangulo r1 = {1.5, 3.0}, r2 = {4.0, 5.0};
    Circulo c1, c2;
    double p,a;

    c1.raio = 5.0;
    c2.raio = 1.0/MEU_PI;

    printf("%.4lf",PHI);
    printf("\n%c",minha_global);
    /*
    printf("\ndigite o comprimento do retangulo 1:  ");
    scanf("%lf", &r1.comprimento);
    printf("\ndigite a largura do retangulo 1:  ");
    scanf("%lf", &r1.largura);

    p = perimetro_retangulo(r1);
    a = area_retangulo(r1);
    printf("area retangulo = %.2f, perimetro retangulo = %.2f",a,p);

    printf("\ndigite o comprimento do retangulo 2:  ");
    scanf("%lf", &r2.comprimento);
    printf("\ndigite a largura do retangulo 2:  ");
    scanf("%lf", &r2.largura);

    p = perimetro_retangulo(r2);
    a = area_retangulo(r2);

    printf("area retangulo = %.2f, perimetro retangulo = %.2f",a,p);

    printf("\ndigite o raio circulo 1:  ");
    scanf("%lf",&c1.raio);

    p = perimetro_circulo(c1);
    a = area_circulo(c1);

    printf("area circulo = %.2f, perimetro circulo= %.2f",a,p);
    
    printf("\ndigite o raio circulo 2:  ");
    scanf("%lf",&c2.raio);

    p = perimetro_circulo(c2);
    a = area_circulo(c2);

    printf("area circulo = %.2f, perimetro circulo= %.2f",a,p);
    return 0;
    */

    p = perimetro_retangulo(r1);
    a = area_retangulo(r1);
    printf("R1 - p: %.2lf A: %.2lf\n",p,a);

    p = perimetro_retangulo(r2);
    a = area_retangulo(r2);
    printf("R2 - p: %.2lf A: %.2lf\n",p,a);

    p = perimetro_circulo(c1);
    a = area_circulo(c1);
    printf("c1 - p: %.2lf a: %.2lf\n",p,a);

    p = perimetro_circulo(c2);
    a = area_circulo(c2);
    printf("c2 - p: %.2lf a: %.2lf\n",p,a);

}