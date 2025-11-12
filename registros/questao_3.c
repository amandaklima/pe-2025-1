#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct {
    int numero;
    char nome[100];
    char cpf[20];
    char telefone[20];
    float saldo;
} Conta;

// (a) Função de busca
int buscarConta(Conta contas[], int qtd, int numero) {
    if (qtd == 0) return -1; // cadastro vazio

    for (int i = 0; i < qtd; i++) {
        if (contas[i].numero == numero)
            return i; // posição encontrada
    }
    return -2; // não encontrada
}

// (b) Procedimento para cadastrar nova conta
void cadastrarConta(Conta contas[], int *qtd, int numero) {
    if (*qtd >= MAX_CONTAS) {
        printf("Limite máximo de contas atingido!\n");
        return;
    }

    int pos = buscarConta(contas, *qtd, numero);

    if (pos >= 0) {
        printf("Número de conta já cadastrado\n");
        return;
    }

    Conta nova;
    nova.numero = numero;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nova.nome);
    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", nova.cpf);
    printf("Digite o telefone de contato: ");
    scanf(" %[^\n]", nova.telefone);
    printf("Digite o saldo inicial: ");
    scanf("%f", &nova.saldo);

    contas[*qtd] = nova;
    (*qtd)++;

    printf("Conta cadastrada com sucesso!\n");
}


// Função principal
int main() {
    Conta corrente[MAX_CONTAS], poupanca[MAX_CONTAS];
    int qtdCorrente = 0, qtdPoupanca = 0;
    int opcao, tipo, numero;

    do {
        printf("\n===== BANCO DINHEIRO CERTO =====\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Listar contas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        printf("Escolha o tipo de conta (1 - Corrente | 2 - Poupança): ");
        scanf("%d", &tipo);

        Conta *cadastro = (tipo == 1) ? corrente : poupanca;
        int *qtd = (tipo == 1) ? &qtdCorrente : &qtdPoupanca;

        switch (opcao) {
            case 1:
                printf("Digite o número da nova conta: ");
                scanf("%d", &numero);
                cadastrarConta(cadastro, qtd, numero);
                break;
            case 2:
                printf("Digite o número da conta: ");
                scanf("%d", &numero);
                consultarSaldo(cadastro, *qtd, numero);
                break;
            case 3:
                printf("Digite o número da conta: ");
                scanf("%d", &numero);
                depositar(cadastro, *qtd, numero);
                break;
            case 4:
                printf("Digite o número da conta: ");
                scanf("%d", &numero);
                sacar(cadastro, *qtd, numero);
                break;
            case 5:
                exibirContas(cadastro, *qtd);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    printf("Encerrando o sistema\n");
    return 0;
}
