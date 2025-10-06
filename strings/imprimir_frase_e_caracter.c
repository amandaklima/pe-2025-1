#include <stdio.h>
#include <string.h>
/*
int main(){
    char nome [50] = "amanda";
    strcpy(nome, "marcio");
    nome [4] = '-';
    nome [5] = '*';
    strlen(frase)
    printf("nome = '%s'\n\n", nome);
    return 0;
} */


int main(){
    char frase [50] = "olá turma";
    printf("frase = '%s'\n\n", frase);
    imprimirLetraPorLetra(frase);
    printf("\n\n");
    return 0; 
}
void imprimirLetraPorLetra(char str[]){
    int tam =strlen(str);
    for (int i = 0; i < tam; i++){
        printf(" '%c' %3d/n", str[i]);
    }
}

