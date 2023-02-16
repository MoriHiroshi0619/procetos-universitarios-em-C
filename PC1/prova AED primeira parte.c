//passagem de parametro por valor utilizando registros.

#include <stdio.h>

typedef struct{
    int inscricao, cargo, total_minuto;
    int hora_entra[5], hora_sai[5];
    int minuto_entra[5], minuto_sai[5];
    int horas_totais, minutos_totais;
    float salario;
    char nome[50]; 
}funcionario;

int conversao_minuto(int a, int b){
    return((a*60)+b);
}

int horas_totais(int a){
    return(a/60);
}

int minutos_totais(int a){
    return(a%60);
}

int main(){
    funcionario func[100];
    int i=1,j,hora1,hora2,total,ref1,ref2;
    int keep = 1;
    while(keep){
        printf("\ninforme a inscricao do funcionario\t");
        scanf("%d",&func[i].inscricao);
        printf("\ninforme o nome do funcionario\t");
        scanf("%s", func[i].nome);
        for(j=0;j<5;j++){
            printf("\ndia %d da semana",j+1);
            do{
                printf("\ninforme a hora de entrada\t");
                scanf("%d",&func[i].hora_entra[j]);
            }while(func[i].hora_entra[j]>24);
            do{
                printf("\ninforme o minuto de entrada\t");
                scanf("%d",&func[i].minuto_entra[j]);
            }while(func[i].minuto_entra[j]>60);
            ref1 = func[i].hora_entra[j];
            ref2 = func[i].minuto_entra[j];
            hora1 = conversao_minuto(ref1, ref2);

            do{
                printf("\ninforme a hora de sainda\t");
                scanf("%d",&func[i].hora_sai[j]);
            }while(func[i].hora_sai[j]>24);
            do{
                printf("\ninforme o minuto de saida\t");
                scanf("%d",&func[i].minuto_sai[j]);
            }while(func[i].minuto_sai[j]>60);
            ref1 = func[i].hora_sai[j];
            ref2 = func[i].minuto_sai[j];
            hora2 = conversao_minuto(ref1, ref2);

            func[i].total_minuto += hora2 - hora1;
        }
        ref1 = func[i].total_minuto;
        func[i].horas_totais = horas_totais(ref1);
        ref2 = func[i].total_minuto;
        func[i].minutos_totais = minutos_totais(ref2);

        do{
            printf("\ninforme o cargo do funcionario(1 2 3)\t");
            printf("\ndigite 0 caso queira terminar\t");
            scanf("%d", &func[i].cargo);
        }while(func[i].cargo>3);
        i++;
        if(func[i].cargo == 0){
            keep = 1;
            total = i;
        }
    }                   
    for(i=0;i<total;i++){
        if(func[i].cargo == 1){
            int salario_hora = 300;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
        if(func[i].cargo == 2){
            int salario_hora = 400;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
        if(func[i].cargo == 3){
            int salario_hora = 1000;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
    }
}






/*

#include <stdio.h>

typedef struct{
    int inscricao, cargo, total_minuto;
    int hora_entra[5], hora_sai[5];
    int minuto_entra[5], minuto_sai[5];
    int horas_totais, minutos_totais;
    float salario;
    char nome[50]; 
}funcionario;

int conversao_minuto(funcionario a, funcionario b){
    return((a*60)+b);
}

int horas_totais(funcionario a){
    return(a/60);
}

int minutos_totais(funcionario a){
    return(a%60);
}

int main(){
    funcionario func[100];
    int i=1,j,hora1,hora2,total;
    int keep = 1;
    while(keep){
        printf("\ninforme a inscricao do funcionario\t");
        scanf("%d",&func[i].inscricao);
        printf("\ninforme o nome do funcionario\t");
        scanf("%s", func[i].nome);
        for(j=0;j<5;j++){
            printf("\ndia %d da semana",j+1);
            do{
                printf("\ninforme a hora de entrada\t");
                scanf("%d",&func[i].hora_entra[j]);
            }while(func[i].hora_entra[j]>24);
            do{
                printf("\ninforme o minuto de entrada\t");
                scanf("%d",&func[i].minuto_entra[j]);
            }while(func[i].minuto_entra[j]>60);

            hora1 = conversao_minuto(func[i].hora_entra[j], func[i].minuto_entra[j]);

            do{
                printf("\ninforme a hora de sainda\t");
                scanf("%d",&func[i].hora_sai[j]);
            }while(func[i].hora_sai[j]>24);
            do{
                printf("\ninforme o minuto de saida\t");
                scanf("%d",&func[i].minuto_sai[j]);
            }while(func[i].minuto_sai[j]>60);

            hora2 = conversao_minuto(func[i].hora_sai[j], func[i].minuto_sai[j]);

            func[i].total_minuto += hora2 - hora1;
        }
        func[i].horas_totais = horas_totais(func[i].total_minuto);
        func[i].minutos_totais = minutos_totais(func[i].total_minuto);

        do{
            printf("\ninforme o cargo do funcionario(1 2 3)\t");
            printf("\ndigite 0 caso queira terminar\t");
            scanf("%d",&func[i].cargo);
        }while(func[i].cargo>3);
        i++;
        if(func[i].cargo == 0){
            keep = 0;
            total = i;
        }
    }
    for(i=0;i<total;i++){
        if(func[i].cargo == 1){
            int salario_hora = 300;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
        if(func[i].cargo == 2){
            int salario_hora = 400;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
        if(func[i].cargo == 3){
            int salario_hora = 500;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
    }
}
*/