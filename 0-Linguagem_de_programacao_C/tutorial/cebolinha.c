#include <stdio.h>

#define MAX 15

void copiar_cebolinha(char palavra[MAX],
                      char palavra_modificada[MAX]) {
    int i = 0;
    int j = 0;
    int ultima_eh_erre = 0;
    char letra;

    while (palavra[i] != '\0') {
        letra = palavra[i++];
        if (letra == 'R') {
            if (!ultima_eh_erre)
                palavra_modificada[j++] = 'L';
            ultima_eh_erre = 1;
        } else {
            palavra_modificada[j++] = letra;
            ultima_eh_erre = 0;
        }
    }
    palavra_modificada[j] = '\0';
}


int main(){
    char palavra[MAX];
    char palavra_modificada[MAX];
    int i = 0;

    scanf("%s", palavra);

    copiar_cebolinha(palavra, palavra_modificada);

    while(palavra_modificada[i] != '\0') {
        printf("%c", palavra_modificada[i]);
        i++;
    }
    printf("\n");

    return 0;
}
