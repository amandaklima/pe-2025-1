#include <stdio.h>
#include <string.h>

#define ESTADOS 26


typedef struct {
    char nome[50];
    int veiculos;
    int acidentes;
} Estado;

// (a) Procedimento para coletar dados
void coletarDados(Estado estados[]) {
    for (int i = 0; i < ESTADOS; i++) {
        printf("\nDigite o nome do estado %d: ", i + 1);
        scanf(" %[^\n]", estados[i].nome);

        printf("Digite o número de veículos em 2007: ");
        scanf("%d", &estados[i].veiculos);

        printf("Digite o número de acidentes de trânsito em 2007: ");
        scanf("%d", &estados[i].acidentes);
    }
}

// (b) Procedimento para encontrar o maior e menor número de acidentes
void maiorMenorAcidentes(Estado estados[], int *indiceMaior, int *indiceMenor) {
    *indiceMaior = 0;
    *indiceMenor = 0;

    for (int i = 1; i < ESTADOS; i++) {
        if (estados[i].acidentes > estados[*indiceMaior].acidentes)
            *indiceMaior = i;
        if (estados[i].acidentes < estados[*indiceMenor].acidentes)
            *indiceMenor = i;
    }
}

// (c) Função para calcular percentual de veículos envolvidos em acidentes
float percentualAcidentes(Estado e) {
    if (e.veiculos == 0) return 0;
    return ((float)e.acidentes / e.veiculos) * 100;
}

// (d) Função para calcular a média nacional de acidentes
float mediaAcidentes(Estado estados[]) {
    int total = 0;
    for (int i = 0; i < ESTADOS; i++) {
        total += estados[i].acidentes;
    }
    return (float)total / ESTADOS;
}

// (e) Procedimento para mostrar estados acima da média nacional
void estadosAcimaMedia(Estado estados[], float media) {
    printf("\nEstados com número de acidentes acima da média (%.2f):\n", media);
    for (int i = 0; i < ESTADOS; i++) {
        if (estados[i].acidentes > media) {
            printf(" - %s: %d acidentes\n", estados[i].nome, estados[i].acidentes);
        }
    }
}

int main() {
    Estado estados[ESTADOS];
    int indiceMaior, indiceMenor;
    float media;

    printf(" PESQUISA DE ACIDENTES DE TRÂNSITO em 2007\n");

    // (a)
    coletarDados(estados);

    // (b)
    maiorMenorAcidentes(estados, &indiceMaior, &indiceMenor);
    printf("\nEstado com MAIOR número de acidentes: %s (%d)\n", estados[indiceMaior].nome, estados[indiceMaior].acidentes);
    printf("Estado com MENOR número de acidentes: %s (%d)\n", estados[indiceMenor].nome, estados[indiceMenor].acidentes);

    // (c)
    printf("\nPercentual de veículos envolvidos em acidentes:\n");
    for (int i = 0; i < ESTADOS; i++) {
        printf("%s: %.2f%%\n", estados[i].nome, percentualAcidentes(estados[i]));
    }

    // (d)
    media = mediaAcidentes(estados);
    printf("\nMédia nacional de acidentes: %.2f\n", media);

    // (e)
    estadosAcimaMedia(estados, media);

    return 0;
}
