#include <stdio.h>

#define MAX_ALUNOS 100


float ler_media(int m) {
    int i;
    float media, nota;
    media = 0;

    for (i = 0; i < m; i++) {
        scanf("%f", &nota);
        media += nota;
    }

    media = media/m;
    return media;
}


void ler_notas_praticas(float P[MAX_ALUNOS], int n) {
    int i;
    for (i = 0; i < n; i++)
        P[i] = ler_media(3);
}


void ler_notas_teoricas(float T[MAX_ALUNOS], int n) {
    int i;
    for (i = 0; i < n; i++)
        T[i] = ler_media(2);
}


float obter_maximo(float vetor[MAX_ALUNOS], int n) {
    int i;
    float maximo = vetor[0];
    for (i =0; i < n; i++) {
        if (maximo < vetor[i])
            maximo = vetor[i];
    }

    return maximo;
}


void multiplicar_fator(float vetor[MAX_ALUNOS], int n, float fator) {
    int i;
    for (i = 0; i < n; i++)
        vetor[i] = vetor[i] * fator;
}


float obter_media (float vetor[MAX_ALUNOS], int n) {
    int i;
    float media;

    media = 0;
    for (i = 0; i < n; i++)
        media = media + vetor[i];
    media = media/n;

    return media;
}


void imprimir_notas (float P[MAX_ALUNOS], float T[MAX_ALUNOS], int n) {
    int i;
    float F;
    for (i = 0; i < n; i++) {
        F = (T[i] + P[i]) / 2.0;
        printf("%.1f\n", F);
    }
}


int main(){
    int n;
    float P[MAX_ALUNOS];
    float T[MAX_ALUNOS];
    float maximo_pratica;
    float maximo_teorica;
    float media_pratica;
    float media_teorica;

    scanf("%d", &n);

    ler_notas_praticas(P, n);
    ler_notas_teoricas(T, n);

    multiplicar_fator(P, n, 1.1);

    maximo_teorica = obter_maximo(T, n);
    multiplicar_fator(T, n, 10.0/maximo_teorica);

    imprimir_notas(P, T, n);

    maximo_pratica = obter_maximo(P, n);
    maximo_teorica = obter_maximo(T, n);
    media_pratica = obter_media(P, n);
    media_teorica = obter_media(T, n);

    printf("Max P: %.1f\n", maximo_pratica);
    printf("Max T: %.1f\n", maximo_teorica);
    printf("Media P: %.1f\n", media_pratica);
    printf("Media T: %.1f\n", media_teorica);
}
