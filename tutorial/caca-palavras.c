#include <stdio.h>

#define MAX_PALAVRA 15
#define MAX_ALTURA 15
#define MAX_LARGURA 15

void ler_matriz(char matriz[][MAX_ALTURA], int m, int n) {
    int i, j;
    char letra;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %c", &letra);
            matriz[i][j] = letra;
        }
    }
}


void criar_matriz_ponto(char matriz[][MAX_ALTURA], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            matriz[i][j] = '.';
}


void imprimir_matriz(char matriz[][MAX_ALTURA], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%c ", matriz[i][j]);
        printf("\n");
    }
}


int comprimento_str(char palavra[]){
    int i = 0;
    while (palavra[i] != '\0') {
        i++;
    }
    return (i - 1);
}


void copiar_inverso(char palavra[], char inverso[]) {
    int i, j;
    i = comprimento_str(palavra) - 1;
    j = 0;
    while (i >= 0) {
        inverso[j] = palavra[i];
        i = i - 1;
        j = j + 1;
    }
    inverso[j] = '\0';
}


void marcar_ocorrencia_horizontal(char palavra[],
        char A[MAX_ALTURA][MAX_LARGURA],
        char B[MAX_ALTURA][MAX_LARGURA],
        int m, int n, int i, int j)
{
    int k = 0; int ii = i; int jj = j;
    int copiar = 1;
    while (palavra[k] != '\0') {
        if (i > m || j > n || palavra[k] != A[i][j])
            copiar = 0;
        k++; i++;
    }

    if (copiar == 1) {
        k = 0; i = ii; j = jj;
        while (palavra[k] != '\0') {
            B[i][j] = A[i][j];
            k++; i++;
        }
    }
}


void marcar_ocorrencia_vertical(char palavra[],
        char A[MAX_ALTURA][MAX_LARGURA],
        char B[MAX_ALTURA][MAX_LARGURA],
        int m, int n, int i, int j)
{
    int k = 0; int ii = i; int jj = j;
    int copiar = 1;
    while (palavra[k] != '\0') {
        if (i > m || j > n || palavra[k] != A[i][j])
            copiar = 0;
        k++; j++;
    }

    if (copiar == 1) {
        k = 0; i = ii; j = jj;
        while (palavra[k] != '\0') {
            B[i][j] = A[i][j];
            k++; j++;
        }
    }
}


void marcar_ocorrencia_diagonal(char palavra[],
        char A[MAX_ALTURA][MAX_LARGURA],
        char B[MAX_ALTURA][MAX_LARGURA],
        int m, int n, int i, int j)
{
    int k = 0; int ii = i; int jj = j;
    int copiar = 1;
    while (palavra[k] != '\0') {
        if (i > m || j > n || palavra[k] != A[i][j])
            copiar = 0;
        k++; j++; i++;
    }

    if (copiar == 1) {
        k = 0; i = ii; j = jj;
        while (palavra[k] != '\0') {
            B[i][j] = A[i][j];
            k++; j++; i++;
        }
    }
}


void marcar_ocorrencias(char palavra[],
       char A[MAX_ALTURA][MAX_LARGURA],
       char B[MAX_ALTURA][MAX_LARGURA],
       int m, int n){
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            marcar_ocorrencia_horizontal(palavra, A, B, m, n, i, j);
            marcar_ocorrencia_vertical(palavra, A, B, m, n, i, j);
            marcar_ocorrencia_diagonal(palavra, A, B, m, n, i, j);
        }
    }
}


int main(){
    int i;
    int m, n, p;
    char A[MAX_ALTURA][MAX_LARGURA];
    char B[MAX_ALTURA][MAX_LARGURA];
    char palavra[MAX_PALAVRA], inverso[MAX_PALAVRA];

    /* le e cria matrizes */
    scanf("%d %d", &m, &n);
    ler_matriz(A, m, n);
    criar_matriz_ponto(B, m, n);

    /* le e marca cada palavra */
    scanf("%d", &p);
    for (i = 0; i < p; i++){
        scanf("%s", palavra);
        marcar_ocorrencias(palavra, A, B, m, n);
        copiar_inverso(palavra, inverso);
        marcar_ocorrencias(inverso, A, B, m, n);
    }

    /* imprime matriz resultante */
    imprimir_matriz(B, m,n);

    return 0;
}
