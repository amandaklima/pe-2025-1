#include <stdio.h>
#include <string.h>

# define MAX_PRODUTOS 100 

struct Produto {
    char descricao[50];
    int codigo;
    double preco;
    int qtdEstoque;
};

void cadastrarProduto(struct Produto *p);
void alterarValor(struct Produto *p);
void consultarPreco(struct Produto p);
void consultarEstoque(struct Produto p);
void venderProduto(struct Produto *p);
void atualizarEstoque(struct Produto *p);
void listarProdutos(struct Produto p);
void listarEstoqueZero(struct Produto p);

int main (){
    struct Produto p;
    char opcao;

    printf("\n=== MENU ===\n");
    printf("a - Cadastrar Produto\n");
    printf("b - Alterar valor\n");
    printf("c - Consultar preço\n");
    printf("d - Consultar quantidade em estoque\n");
    printf("e - Realizar venda\n");
    printf("f - Atualizar estoque\n");
    printf("g - Ver todos os produtos\n");
    printf("h - Ver produtos com estoque zero\n");
    printf("Digite a opção: ");
    scanf(" %c", &opcao);

    switch (opcao) {
        case 'a':
            cadastrarProduto(&p);
            break;
        case 'b':
            alterarValor(&p);
            break;
        case 'c':
            consultarPreco(p);
            break;
        case 'd':
            consultarEstoque(p);
            break;
        case 'e':
            venderProduto(&p);
            break;
        case 'f':
            atualizarEstoque(&p);
            break;
        case 'g':
            listarProdutos(p);
            break;
        case 'h':
            listarEstoqueZero(p);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}

void cadastrarNovoProduto(struct Produto *p) {
    printf("Digite o nome do produto: ");
    getchar();
    fgets(p->descricao, 50, stdin);
    p->descricao[strcspn(p->descricao, "\n")] = '\0'; 

    printf("Digite o código do produto: ");
    scanf("%d", &p->codigo);

    printf("Digite o preço do produto: ");
    scanf("%f", &p->preco);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &p->qtdEstoque);
}
