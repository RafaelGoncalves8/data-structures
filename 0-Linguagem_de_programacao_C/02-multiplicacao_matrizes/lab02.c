/* Lab 02 - Multiplicacao de matrizes
 * Rafael Goncalves
 *
 * O objetivo do programa é imprimir os elementos de A*B onde A é a
 * matriz de permutacao criada a partir do vetor dado p e B é a
 * matriz dada como entrada.*/

#include <stdio.h>


/* dimensao maxima das matrizes */
#define N 312


void create_permutation_matrix(int p[], int A[][N], int n) {
    /* cria a matriz de permutacao A a partir do vetor p */
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (p[j] == i)
                A[i][j] = 1;
            else
                A[i][j] = 0;
}


void print_matrix_multiplication (int A[][N], double B[][N],
                                         int n) {
    /* calcula e imprime a matriz A*B */

    int i, j, k;
    double c;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c = 0;
            for (k = 0; k < n; k++)
                c += A[i][k]  * B[k][j];
            printf("%.1f ", c);
        }
        printf("\n");
    }
}


int main(){
    int i, j;
    int n;          /* dimensao das matrizes */
    int p[N];          /* vetor de permutacao */
    int A[N][N];
    double B[N][N];


    /* leitura de variáveis */
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);


    /* criacao da matriz de permutacao */
    create_permutation_matrix(p, A, n);


    /* multiplicacao de A e B */
    print_matrix_multiplication(A, B, n);


    return 0;
}
