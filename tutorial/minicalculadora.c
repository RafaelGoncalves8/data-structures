#include <stdio.h>

int main(){
    float operando1, operando2;
    float resultado;
    char operador;

    while(1) {

        scanf("%f %c %f", &operando1, &operador, &operando2);

        if (operador == '/') {
            resultado = operando1 / operando2;
            printf("%f\n", resultado);
        } else if (operador == '*') {
            resultado = operando1 * operando2;
            printf("%f\n", resultado);
        } else if (operador == '+') {
            resultado = operando1 + operando2;
            printf("%f\n", resultado);
        } else if (operador == '-') {
            resultado = operando1 - operando2;
            printf("%f\n", resultado);
        } else {
            printf("Erro: operador não reconhecido\n");
        } 
    }

    return 0;

}
