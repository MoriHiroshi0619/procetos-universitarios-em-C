#include "geometria.h"

const double MEU_PI = 3.1215;
char minha_global = 'i';

double perimetro_retangulo(Retangulo r){
    return 2*(r.comprimento + r.largura);
}

double area_retangulo(Retangulo r){
    return r.comprimento*r.largura;
}

double perimetro_circulp(Circulo c){
    return 2 * MEU_PI * c.raio;
}

double area_circulo(Circulo c){
    return MEU_PI * c.raio * c.raio;
}