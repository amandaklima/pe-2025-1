#include <stdio.h>
#include <string.h>

#define TAM_NOME 50

struct Aluno{
    char nome[TAM_NOME];
    double nota1;
    double nota2;
}

int main (){
    struct Aluno a;
    double media;

    printf("digite o nome da pessoa:");
    lerStr(a.nome , TAM_NOME);
    printf("digite a primeira nota:");
    scanf("%lf, %p.nota1");
    printf("digite a segunda nota:");
    scanf("%lf, %p.nota2");

    media = a.nota1 + a.nota2 / 2.0;

    printf ("o aluno $s tem media %2f \n", a.nome, media);
    return 0;

}