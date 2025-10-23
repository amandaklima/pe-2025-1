#include <stdio.h>
#include <string.h>

#define TAM 256

void lerStr(char str[], int tam);
void inserirFinalArquivo(char nomeArq[]);
void listarArquivo(char nomeArq[]);
void lerPosicaoEspecifica(char nomeArq[]);
void buscarNumero(char nomeArq[]);
void substituirNumero(char nomeArq[]);
void excluirNumero(char nomeArq[]);

int main() {
    char nomeArq[TAM];
    int opcao;
    printf("Digite o nome do arquivo: ");
    lerStr(nomeArq, TAM);

    while (strlen(nomeArq) == 0) {
        printf("Nome vazio é inválido!\n");
        printf("Digite o nome do arquivo: ");
        lerStr(nomeArq, TAM);
    }

    do {
        printf("\n\nMENU\n");
        printf("1 - Gravar um número no final do arquivo\n");
        printf("2 - Listar o conteúdo do arquivo\n");
        printf("3 - Imprimir valor específico\n");
        printf("4 - Buscar um número no arquivo\n");
        printf("5 - Substituir um número no arquivo\n");
        printf("6 - Excluir um número do arquivo\n");
        printf("Digite a sua opção (0 p/ finalizar): ");
        scanf("%d", &opcao);
        getchar(); // limpa o \n do buffer

        switch (opcao) {
            case 1:
                inserirFinalArquivo(nomeArq);
                break;
            case 2:
                printf("---------------- Listagem ----------------\n");
                listarArquivo(nomeArq);
                printf("------------------------------------------\n");
                break;
            case 3:
                lerPosicaoEspecifica(nomeArq);
                break;
            case 4:
                buscarNumero(nomeArq);
                break;
            case 5:
                substituirNumero(nomeArq);
                break;
            case 6:
                excluirNumero(nomeArq);
                break;
            default:
                if (opcao != 0)
                    printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void lerStr(char str[], int tam) {
    fgets(str, tam, stdin);
    int tamDigitado = strlen(str);
    if (tamDigitado > 0 && str[tamDigitado - 1] == '\n') {
        str[tamDigitado - 1] = '\0';
    }
}

void inserirFinalArquivo(char nomeArq[]) {
    double num;
    FILE *arq = fopen(nomeArq, "ab");
    if (arq == NULL) {
        printf("Não pode abrir o arquivo!\n");
        return;
    }
    printf("Digite um número real: ");
    scanf("%lf", &num);
    if (fwrite(&num, sizeof(double), 1, arq) == 1)
        printf("Valor armazenado com sucesso!\n");
    else
        printf("Erro ao gravar o valor no arquivo!\n");
    fclose(arq);
}

void listarArquivo(char nomeArq[]) {
    double num;
    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        printf("Não pode abrir o arquivo!\n");
        return;
    }
    while (fread(&num, sizeof(double), 1, arq) == 1) {
        printf("%.3f\n", num);
    }
    fclose(arq);
}

void lerPosicaoEspecifica(char nomeArq[]) {
    int pos;
    double num;
    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        printf("Não pode abrir o arquivo!\n");
        return;
    }
    printf("Você quer mover para que posição: ");
    scanf("%d", &pos);
    if (fseek(arq, (pos - 1) * sizeof(double), SEEK_SET) != 0) {
        printf("Essa é uma posição inválida!\n");
        fclose(arq);
        return;
    }
    if (fread(&num, sizeof(double), 1, arq) == 1)
        printf("%.3f\n", num);
    else
        printf("Erro na leitura do registro!\n");
    fclose(arq);
}

void buscarNumero(char nomeArq[]) {
    int encontrado = 0;
    double num, busca;
    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        printf("Não pode abrir o arquivo!\n");
        return;
    }
    printf("Digite o número que deseja buscar: ");
    scanf("%lf", &busca);
    while (fread(&num, sizeof(double), 1, arq) == 1) {
        if (num == busca) {
            encontrado = 1;
            break;
        }
    }
    printf("O número %.3f %s salvo no arquivo!\n", busca, encontrado ? "ESTÁ" : "NÃO está");
    fclose(arq);
}

void substituirNumero(char nomeArq[]) {
    int encontrou = 0;
    double num, antigo, novo;
    long pos;
    FILE *arq = fopen(nomeArq, "r+b");
    if (arq == NULL) {
        printf("Não pode abrir o arquivo!\n");
        return;
    }
    printf("Digite o número que deseja substituir: ");
    scanf("%lf", &antigo);
    printf("Digite o novo número: ");
    scanf("%lf", &novo);
    while (fread(&num, sizeof(double), 1, arq) == 1) {
        if (num == antigo) {
            pos = ftell(arq) - sizeof(double);
            fseek(arq, pos, SEEK_SET);
            fwrite(&novo, sizeof(double), 1, arq);
            encontrou = 1;
        }
    }
    if (encontrou)
        printf("Número %.3f substituído por %.3f!\n", antigo, novo);
    else
        printf("Número %.3f não encontrado!\n", antigo);
    fclose(arq);
}

void excluirNumero(char nomeArq[]) {
    int encontrou = 0;
    double num, excluir;
    char temp[TAM];
    FILE *arq, *tmp;

    arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        printf("Não pode abrir o arquivo!\n");
        return;
    }
    strcpy(temp, nomeArq);
    strcat(temp, ".tmp");
    tmp = fopen(temp, "wb");
    if (tmp == NULL) {
        printf("Não pode criar arquivo temporário!\n");
        fclose(arq);
        return;
    }

    printf("Digite o número que deseja excluir: ");
    scanf("%lf", &excluir);

    while (fread(&num, sizeof(double), 1, arq) == 1) {
        if (num != excluir) {
            fwrite(&num, sizeof(double), 1, tmp);
        } else {
            encontrou = 1;
        }
    }
    fclose(arq);
    fclose(tmp);

    if (encontrou) {
        remove(nomeArq);
        rename(temp, nomeArq);
        printf("Número %.3f excluído com sucesso!\n", excluir);
    } else {
        remove(temp);
        printf("Número %.3f não encontrado!\n", excluir);
    }
}
