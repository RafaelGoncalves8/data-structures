/* Lab 01 - Diferenca simetrica
 * Rafael Goncalves
 *
 * O objetivo do programa é imprimir os elementos de A e de B que nao se interseccionam (diferenca simetrica)
 * O programa le os dois vetores A (de tamanho m) e B (de tamanho n), compara seus elementos entre si marcando
 * o i-esimo elemento de A que tambem esta contido em B no elemento i do vetor INTERSEC_A 
 * e marcando o j-esimo elemento de B no elemento j do vetor INTERSEC_B  */


#include <stdio.h>

/* Tamanho maximo dos vetores */
#define N 40

int main(){
    /* Declaracao de variaveis */
    int i, j;       /* variaveis de controle nos lacos */
    int A[N], B[N]; /* conjuntos de numeros A e B */
    int m, n;       /* tamanho dos conjuntos A e B */
    int INTERSEC_A[N], INTERSEC_B[N]; /* mascara indicando se elemento em A
                                         esta tambem e B e vice e versa */

    /* Leitura */
    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &B[i]);

    /* Inicializacao de mascaras com zeros */
    for (i = 0; i < N; i++){
        INTERSEC_A[i] = 0;
        INTERSEC_B[i] = 0;
    }

    /* Indicacao de numeros repetidos atraves do uso das mascaras */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                INTERSEC_A[i] = 1;
                INTERSEC_B[j] = 1;
            }
        }
    }

    /* Impressao dos numeros em A e nao em B */
    for (i = 0; i < m; i++)
        if (INTERSEC_A[i] == 0) 
            printf("%d ", A[i]);

    /* Impressao dos numeros em B e nao em A */
    for (i = 0; i < n; i++)
        if (INTERSEC_B[i] == 0)
            printf("%d ", B[i]);

    printf("\n");

    return 0;
}
