#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria {
    int codigo;
    char nome[50];
};

struct Produto {
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria;
    int preco;
};

// ============ QUESTÃO 1 ============
void cadastrarCategoria(struct Categoria v[], int *qtd) {
    // ERRO COMUM: Não dar feedback ao usuário quando não pode cadastrar
    if (*qtd >= TAM) {
        printf("ERRO: Vetor cheio! Não é possível cadastrar mais categorias.\n");
        return;
    }
    
    int codigo;
    printf("Digite o código da categoria: ");
    scanf("%d", &codigo);
    
    // ERRO COMUM: Não validar se o código é válido (positivo)
    if (codigo <= 0) {
        printf("ERRO: Código inválido! Digite um código positivo.\n");
        return;
    }
    
    // Verificar duplicidade - VOCÊ PROVAVELMENTE FEZ ISSO CORRETO
    for (int i = 0; i < *qtd; i++) {
        if (v[i].codigo == codigo) {
            // MELHORIA: Dar feedback claro ao usuário
            printf("ERRO: Código %d já existe! Categoria não cadastrada.\n", codigo);
            return;
        }
    }
    
    // Cadastrar a nova categoria
    v[*qtd].codigo = codigo;
    printf("Digite o nome da categoria: ");
    scanf(" %[^\n]", v[*qtd].nome); // Usar %[^\n] para ler string com espaços
    
    (*qtd)++;
    printf("Categoria cadastrada com sucesso!\n");
}

// ============ QUESTÃO 2 ============
void imprimirCategorias(struct Categoria v[], int qtd) {
    // MELHORIA: Tratar caso de vetor vazio
    if (qtd == 0) {
        printf("Nenhuma categoria cadastrada.\n");
        return;
    }
    
    printf("\n=== CATEGORIAS CADASTRADAS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d - Nome: %s\n", v[i].codigo, v[i].nome);
    }
    printf("==============================\n\n");
}

// ============ QUESTÃO 3 ============
void imprimirProdutos(struct Produto vp[], int qtdProdutos, 
                      struct Categoria vc[], int qtdCategorias) {
    
    // MELHORIA: Tratar caso de vetor vazio
    if (qtdProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    printf("\n=== PRODUTOS CADASTRADOS ===\n");
    
    for (int i = 0; i < qtdProdutos; i++) {
        printf("Código: %d\n", vp[i].codigo);
        printf("Título: %s\n", vp[i].titulo);
        printf("Descrição: %s\n", vp[i].descricao);
        
        // ERRO COMUM: Não tratar quando a categoria não existe
        // Buscar o nome da categoria
        int categoriaEncontrada = 0;
        for (int j = 0; j < qtdCategorias; j++) {
            if (vc[j].codigo == vp[i].categoria) {
                printf("Categoria: %s\n", vc[j].nome);
                categoriaEncontrada = 1;
                break;
            }
        }
        
        // MELHORIA: Se a categoria não foi encontrada, avisar
        if (!categoriaEncontrada) {
            printf("Categoria: [CATEGORIA NÃO ENCONTRADA - Código: %d]\n", vp[i].categoria);
        }
        
        // VOCÊ PROVAVELMENTE FEZ CORRETO: Conversão de inteiro para double
        // Dividir por 100.0 (não 100) para garantir divisão em ponto flutuante
        double preco = vp[i].preco / 100.0;
        printf("Preço: R$ %.2f\n", preco);
        printf("----------------------------\n");
    }
    printf("============================\n\n");
}

// ============ QUESTÃO 4 ============
void selectionSortPorDescricao(struct Produto v[], int qtd) {
    // VOCÊ PROVAVELMENTE FEZ CORRETO!
    // Selection Sort clássico adaptado para structs
    
    for (int i = 0; i < qtd - 1; i++) {
        int indiceMenor = i;
        
        // Encontrar o menor elemento (ordem alfabética)
        for (int j = i + 1; j < qtd; j++) {
            // IMPORTANTE: strcmp retorna negativo se v[j] vem antes alfabeticamente
            if (strcmp(v[j].descricao, v[indiceMenor].descricao) < 0) {
                indiceMenor = j;
            }
        }
        
        // Trocar se encontrou um menor
        if (indiceMenor != i) {
            // CRÍTICO: Trocar o STRUCT INTEIRO, não apenas um campo
            struct Produto temp = v[i];
            v[i] = v[indiceMenor];
            v[indiceMenor] = temp;
        }
    }
}

// ============ QUESTÃO 5 ============
// ERRO PRINCIPAL: Função void não retorna nem imprime resultado!
// CORREÇÃO 1: Retornar o índice encontrado (ou -1 se não encontrar)
int buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) {
    int inicio = 0;
    int fim = qtd - 1;
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int comparacao = strcmp(x, v[meio].descricao);
        
        if (comparacao == 0) {
            // MELHORIA: Retornar o índice onde encontrou
            return meio;
        } else if (comparacao < 0) {
            // x vem antes alfabeticamente
            fim = meio - 1;
        } else {
            // x vem depois alfabeticamente
            inicio = meio + 1;
        }
    }
    
    // MELHORIA: Retornar -1 se não encontrou
    return -1;
}

// CORREÇÃO 2 (Alternativa): Manter void mas imprimir o resultado
void buscaBinariaPorDescricaoComImpressao(struct Produto v[], int qtd, char *x) {
    int inicio = 0;
    int fim = qtd - 1;
    int encontrado = 0;
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int comparacao = strcmp(x, v[meio].descricao);
        
        if (comparacao == 0) {
            // MELHORIA: Imprimir que encontrou e mostrar o produto
            printf("\nProduto encontrado!\n");
            printf("Código: %d\n", v[meio].codigo);
            printf("Título: %s\n", v[meio].titulo);
            printf("Descrição: %s\n", v[meio].descricao);
            encontrado = 1;
            break;
        } else if (comparacao < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    
    // MELHORIA: Informar se não encontrou
    if (!encontrado) {
        printf("\nProduto com descrição '%s' não encontrado.\n", x);
    }
}

// ============ FUNÇÃO MAIN PARA TESTE ============
int main() {
    struct Categoria categorias[TAM];
    struct Produto produtos[TAM];
    int qtdCategorias = 0;
    int qtdProdutos = 0;
    
    // Exemplo de uso das funções
    printf("=== TESTE DAS FUNÇÕES ===\n\n");
    
    // Teste Q1 e Q2
    printf("--- Testando cadastro de categorias ---\n");
    cadastrarCategoria(categorias, &qtdCategorias);
    imprimirCategorias(categorias, qtdCategorias);
    
    // Teste Q3 (você precisaria adicionar produtos antes)
    // imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);
    
    // Teste Q4 e Q5 (você precisaria adicionar e ordenar produtos antes)
    // selectionSortPorDescricao(produtos, qtdProdutos);
    // int indice = buscaBinariaPorDescricao(produtos, qtdProdutos, "Descrição buscada");
    
    return 0;
}

/* 
=== RESUMO DOS PRINCIPAIS ERROS E CORREÇÕES ===

QUESTÃO 1:
❌ Faltou: Feedback ao usuário quando vetor cheio ou código duplicado
❌ Faltou: Validação de código (deve ser positivo)
✅ Correção: Mensagens claras de erro e validação de entrada

QUESTÃO 2:
❌ Faltou: Tratar caso de vetor vazio
✅ Correção: Verificar qtd == 0 e dar mensagem apropriada

QUESTÃO 3:
❌ ERRO CRÍTICO: Não tratar categoria inexistente (pode imprimir lixo)
❌ Faltou: Usar 100.0 em vez de 100 na divisão (garantir ponto flutuante)
✅ Correção: Verificar se categoria foi encontrada antes de imprimir

QUESTÃO 4:
✅ Provavelmente estava CORRETO!
⚠️ Atenção: Trocar o struct INTEIRO, não apenas campos individuais

QUESTÃO 5:
❌ ERRO CRÍTICO: Função void sem retorno nem impressão é INÚTIL!
✅ Correção Opção 1: Retornar int (-1 se não encontrar, índice se encontrar)
✅ Correção Opção 2: Manter void mas IMPRIMIR o resultado da busca
⚠️ IMPORTANTE: Busca binária SÓ FUNCIONA em vetor ORDENADO!
