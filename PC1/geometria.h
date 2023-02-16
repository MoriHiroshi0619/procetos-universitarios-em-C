#ifndef _GEOMETRIA_H
#define _GEOMETRIA_H

#define PHI 1.61803399
extern const double MEU_PI;
extern char minha_global;

typedef struct {
    double largura, comprimento;
}Retangulo;

typedef struct{
    double raio;
}Circulo;

double perimetro_retangulo(Retangulo r);
double area_retangulo(Retangulo r);
double perimetro_circulo(Circulo c);
double area_circulo(Circulo c);

#endif