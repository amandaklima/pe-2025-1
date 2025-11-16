#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct {
    int numero;
    char nome[100];
    char cpf[15];
    char telefone[20];
    float saldo;
} Conta;


int total_corrente = 0;
int total_poupanca = 0;

// (a) 
int buscar(Conta cadastro[], int total, int numero_conta) {
    if (total == 0) {
        return -1;
    }
    
    for (int i = 0; i < total; i++) {
        if (cadastro[i].numero == numero_conta) {
            return i; 
        }
    }
    
    return -2;
} 

// (b) 
void cadastrar(Conta cadastro[], int *total, int numero_conta) {
    if (*total >= MAX_CONTAS) {
        printf("Erro: Cadastro cheio! Não é possível adicionar mais contas.\n");
        return;
    }
    
    int pos = buscar(cadastro, *total, numero_conta);
    
    if (pos >= 0) {
        printf("Erro: Número de conta já cadastrado!\n");
        return;
    }
    
    // Cadastrar nova conta
    cadastro[*total].numero = numero_conta;
    
    printf("Nome do titular: ");
    getchar(); // Limpa o buffer
    fgets(cadastro[*total].nome, 100, stdin);
    cadastro[*total].nome[strcspn(cadastro[*total].nome, "\n")] = '\0';
    
    printf("CPF: ");
    fgets(cadastro[*total].cpf, 15, stdin);
    cadastro[*total].cpf[strcspn(cadastro[*total].cpf, "\n")] = '\0';
    
    printf("Telefone: ");
    fgets(cadastro[*total].telefone, 20, stdin);
    cadastro[*total].telefone[strcspn(cadastro[*total].telefone, "\n")] = '\0';
    
    printf("Saldo inicial: ");
    scanf("%f", &cadastro[*total].saldo);
    
    (*total)++;
    printf("Conta cadastrada com sucesso!\n");
}

// (c) 
void consultar_saldo(Conta cadastro[], int total, int numero_conta) {
    int pos = buscar(cadastro, total, numero_conta);
    
    if (pos == -1) {
        printf("Cadastro vazio!\n");
    } else if (pos == -2) {
        printf("Conta não cadastrada!\n");
    } else {
        printf("Saldo da conta %d: R$ %.2f\n", numero_conta, cadastro[pos].saldo);
    }
}

// (d)
void depositar(Conta cadastro[], int total, int numero_conta) {
    int pos = buscar(cadastro, total, numero_conta);
    
    if (pos == -1) {
        printf("Cadastro vazio!\n");
    } else if (pos == -2) {
        printf("Conta não cadastrada!\n");
    } else {
        float valor;
        printf("Valor do depósito: ");
        scanf("%f", &valor);
        
        if (valor > 0) {
            cadastro[pos].saldo += valor;
            printf("Depósito realizado com sucesso! Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
        } else {
            printf("Valor inválido!\n");
        }
    }
}

// (e) 
void sacar(Conta cadastro[], int total, int numero_conta) {
    int pos = buscar(cadastro, total, numero_conta);
    
    if (pos == -1) {
        printf("Cadastro vazio!\n");
    } else if (pos == -2) {
        printf("Conta não cadastrada!\n");
    } else {
        float valor;
        printf("Valor do saque: ");
        scanf("%f", &valor);
        
        if (valor > 0) {
            if (cadastro[pos].saldo >= valor) {
                cadastro[pos].saldo -= valor;
                printf("Saque realizado com sucesso! Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
            } else {
                printf("Saldo insuficiente! Saldo atual: R$ %.2f\n", cadastro[pos].saldo);
            }
        } else {
            printf("Valor inválido!\n");
        }
    }
}

// (f)
void exibir_contas(Conta cadastro[], int total) {
    if (total == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }
    
    printf("\nLISTA DE CONTAS\n");
    for (int i = 0; i < total; i++) {
        printf("Conta: %d | Titular: %s | Telefone: %s\n", 
               cadastro[i].numero, cadastro[i].nome, cadastro[i].telefone);
    }
}

int main() {
    Conta corrente[MAX_CONTAS];
    Conta poupanca[MAX_CONTAS];
    
    int opcao, tipo_conta, numero_conta;
    
    do {
        printf("\nBANCO DINHEIRO CERTO\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Fazer depósito\n");
        printf("4 - Fazer saque\n");
        printf("5 - Exibir todas as contas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) break;
        
        if (opcao >= 1 && opcao <= 5) {
            printf("\nTipo de conta:\n");
            printf("1 - Conta Corrente\n");
            printf("2 - Conta Poupança\n");
            printf("Escolha: ");
            scanf("%d", &tipo_conta);
            
            if (tipo_conta != 1 && tipo_conta != 2) {
                printf("Tipo de conta inválido!\n");
                continue;
            }
        }
        
        switch(opcao) {
            case 1:
                printf("Número da nova conta: ");
                scanf("%d", &numero_conta);
                if (tipo_conta == 1) {
                    cadastrar(corrente, &total_corrente, numero_conta);
                } else {
                    cadastrar(poupanca, &total_poupanca, numero_conta);
                }
                break;
                
            case 2:
                printf("Número da conta: ");
                scanf("%d", &numero_conta);
                if (tipo_conta == 1) {
                    consultar_saldo(corrente, total_corrente, numero_conta);
                } else {
                    consultar_saldo(poupanca, total_poupanca, numero_conta);
                }
                break;
                
            case 3:
                printf("Número da conta: ");
                scanf("%d", &numero_conta);
                if (tipo_conta == 1) {
                    depositar(corrente, total_corrente, numero_conta);
                } else {
                    depositar(poupanca, total_poupanca, numero_conta);
                }
                break;
                
            case 4:
                printf("Número da conta: ");
                scanf("%d", &numero_conta);
                if (tipo_conta == 1) {
                    sacar(corrente, total_corrente, numero_conta);
                } else {
                    sacar(poupanca, total_poupanca, numero_conta);
                }
                break;
                
            case 5:
                if (tipo_conta == 1) {
                    printf("\nCONTAS CORRENTES\n");
                    exibir_contas(corrente, total_corrente);
                } else {
                    printf("\nCONTAS POUPANÇA\n");
                    exibir_contas(poupanca, total_poupanca);
                }
                break;
                
            default:
                printf("Opção inválida!\n");
        }
        
    } while (opcao != 0);
    
    printf("\nFim\n");
    return 0;
}
