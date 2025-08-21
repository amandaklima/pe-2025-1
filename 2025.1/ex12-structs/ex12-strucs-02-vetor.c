#include <stdio.h>
#include <string.h>

#define QTD_PESSOAS 10
#define TAM_NOME 30
#define TAM_TEMP 256

struct Pessoa {
  char nome[TAM_NOME];
  int idade;
  double peso, altura;
};

void lerStr(char *str, int count);
void lerPessoa(struct Pessoa *pessoa);
void imprimirPessoa(struct Pessoa pessoa);
double calcularIMC(struct Pessoa pessoa);

// exercícios: implemente as seguintes funções e utilize-as no main
double calcularMediaAltura(struct Pessoa vp[], int tam);
int encontrarPessoaMaisPesada(struct Pessoa vp[], int tam);
double calcularMediaIdadeIMCnormal(struct Pessoa vp[], int tam);

// campo nome
int buscarPeloNome(struct Pessoa v[], int tam, char *x);
int buscaBinariaPorNome(struct Pessoa v[], int tam, char *x);
void insercaoDiretaCampoNome(struct Pessoa v[], int n);

// campo idade
int buscarPelaIdade(struct Pessoa v[], int tam, int x);
int buscaBinariaPorIdade(struct Pessoa v[], int tam, int x);
void insercaoDiretaCampoIdade(struct Pessoa v[], int n);

int main() {
  struct Pessoa pessoas[QTD_PESSOAS];
  char nome[TAM_NOME];
  int pos, idade;

  for (int i = 0; i < QTD_PESSOAS; i += 1)
  {
    printf("----- Digitação dos dados da Pessoa %d -----\n", i + 1);
    lerPessoa(&pessoas[i]);
  }

  printf("\n\n");

  for (int i = 0; i < QTD_PESSOAS; i += 1) {
    printf("----- Impressão dados da Pessoa %d: ", i + 1);
    imprimirPessoa(pessoas[i]);
  }

  insercaoDiretaCampoNome(pessoas, QTD_PESSOAS);

  printf("\n\n----- Impressao apos ordenacao por nome\n");
  for (int i = 0; i < QTD_PESSOAS; i += 1)
  {
    printf("----- Impressão dados da Pessoa %d: ", i + 1);
    imprimirPessoa(pessoas[i]);
  }

  printf("\nA media de altura destas pessoas eh %.2f\n", calcularMediaAltura(pessoas, QTD_PESSOAS));

  int posMaisPesada = encontrarPessoaMaisPesada(pessoas, QTD_PESSOAS);
  printf("\nA pessoa mais pesada eh: ");
  imprimirPessoa(pessoas[posMaisPesada]);

  printf("\nA media de idade das pessoas com IMC normal eh: %.2f\n", calcularMediaIdadeIMCnormal(pessoas, QTD_PESSOAS));

  printf("Digite um nome a ser encontrado: ");
  lerStr(nome, TAM_NOME);
  pos = buscaBinariaPorNome(pessoas, QTD_PESSOAS, nome);
  if (pos != -1) {
    printf("Pessoa encontrada na posicao %d: ", pos + 1);
    imprimirPessoa(pessoas[pos]);
  } else {
    printf("Nao tem nenhuma pessoa com esse nome!\n");
  }

  insercaoDiretaCampoIdade(pessoas, QTD_PESSOAS);

  printf("\n\n----- Impressao apos ordenacao por idade\n");
  for (int i = 0; i < QTD_PESSOAS; i += 1) {
    printf("----- Impressão dados da Pessoa %d: ", i + 1);
    imprimirPessoa(pessoas[i]);
  }

  printf("Digite um nome a ser encontrado: ");
  scanf("%d", &idade);
  pos = buscaBinariaPorIdade(pessoas, QTD_PESSOAS, idade);
  if (pos != -1) {
    printf("Pessoa encontrada na posicao %d: ", pos + 1);
    imprimirPessoa(pessoas[pos]);
  } else {
    printf("Nao tem nenhuma pessoa com essa idade!\n");
  }

  return 0;
}

void lerStr(char *str, int count) {
  fgets(str, count, stdin);
  int tam = strlen(str);
  if (tam > 0 && str[tam - 1] == '\n') {
    str[tam - 1] = '\0';
  }
}

void lerPessoa(struct Pessoa *pessoa) {
  char tempStr[TAM_TEMP];
  printf("Digite o nome: ");
  lerStr(pessoa->nome, TAM_NOME); // lerStr((*pessoa).nome, TAM_NOME);
  printf("Digite a idade: ");
  scanf("%d", &pessoa->idade); // scanf("%d", &(*pessoa).idade);
  printf("Digite o peso: ");
  scanf("%lf", &pessoa->peso); // scanf("%lf", &(*pessoa).peso);
  printf("Digite a altura: ");
  scanf("%lf", &pessoa->altura); // scanf("%lf", &(*pessoa).altura);
  lerStr(tempStr, TAM_TEMP); // realiza a leitura do '\n' do scanf anterior
}

void imprimirPessoa(struct Pessoa pessoa) {
  double imc = calcularIMC(pessoa);
  printf("(%s, %d anos, %.2f kg, %.2f m, IMC %.2f)\n",
    pessoa.nome,
    pessoa.idade,
    pessoa.peso,
    pessoa.altura,
    imc
  );
}

double calcularIMC(struct Pessoa pessoa) {
  return pessoa.peso / (pessoa.altura * pessoa.altura);
}

double calcularMediaAltura(struct Pessoa vp[], int tam) {
  double somaAltura = 0.0, mediaAltura = 0.0;
  for (int i = 0; i < tam; i += 1) {
    somaAltura += vp[i].altura;
  }
  if (tam != 0) {
    mediaAltura = somaAltura / tam;
  }
  return mediaAltura;
}

int encontrarPessoaMaisPesada(struct Pessoa vp[], int tam) {
  int posMaisPesada = 0;
  for (int i = 1; i < tam; i += 1) {
    if (vp[i].peso > vp[posMaisPesada].peso) {
      posMaisPesada = i;
    }
  }
  return posMaisPesada;
}

double calcularMediaIdadeIMCnormal(struct Pessoa vp[], int tam) {
  int somaIdades = 0, qtdIdades = 0;
  double mediaIdades = 0.0, imc;
  for (int i = 0; i < tam; i += 1) {
    imc = calcularIMC(vp[i]);
    if (imc >= 18.5 && imc < 25.0) {
      somaIdades += vp[i].idade;
      qtdIdades += 1;
    }
  }
  if (qtdIdades != 0) {
    mediaIdades = (double) somaIdades / (double) qtdIdades;
  }
  return mediaIdades;
}

// -------- INÍCIO CAMPO NOME --------

int buscarPeloNome(struct Pessoa v[], int tam, char *x) {
  for (int i = 0; i < tam; i += 1) {
    if (strcmp(v[i].nome, x) == 0) {
      return i;
    }
  }
  return -1;
}

// APENAS utilizar se o vetor estiver ORDENADO
int buscaBinariaPorNome(struct Pessoa v[], int tam, char *x) {
  int inicio = 0, fim = tam - 1, meio;
  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (strcmp(v[meio].nome, x) > 0) {
      fim = meio - 1;
    } else if (strcmp(v[meio].nome, x) < 0) {
      inicio = meio + 1;
    } else {
      return meio;
    }
  }
  return -1;
}

void insercaoDiretaCampoNome(struct Pessoa v[], int n) {
  int i, j;
  struct Pessoa chave;
  for (i = 1; i <= n - 1; i++) {
    chave = v[i];
    j = i - 1;
    while (j >= 0 && strcmp(v[j].nome, chave.nome) > 0) {
      v[j+1] = v[j];
      j = j - 1;
    }
    v[j+1] = chave;
  }
}

// -------- FIM CAMPO IDADE --------


// -------- INÍCIO CAMPO IDADE --------

int buscarPelaIdade(struct Pessoa v[], int tam, int x) {
  for (int i = 0; i < tam; i += 1) {
    if (v[i].idade == x) {
      return i;
    }
  }
  return -1;
}

// APENAS utilizar se o vetor estiver ORDENADO
int buscaBinariaPorIdade(struct Pessoa v[], int tam, int x) {
  int inicio = 0, fim = tam - 1, meio;
  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (v[meio].idade > x) {
      fim = meio - 1;
    } else if (v[meio].idade < x) {
      inicio = meio + 1;
    } else {
      return meio;
    }
  }
  return -1;
}

void insercaoDiretaCampoIdade(struct Pessoa v[], int n) {
  int i, j;
  struct Pessoa chave;
  for (i = 1; i <= n - 1; i++) {
    chave = v[i];
    j = i - 1;
    while (j >= 0 && v[j].idade > chave.idade) {
      v[j+1] = v[j];
      j = j - 1;
    }
    v[j+1] = chave;
  }
}

// -------- FIM CAMPO IDADE --------
