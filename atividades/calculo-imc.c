#include <stdio.h>
#include <math.h>

int main() {
    float peso, altura, imc;
    
    printf("Digite o peso (kg): ");
    scanf("%f", &peso);
    
    printf("Digite a altura (m): ");
    scanf("%f", &altura);
    
    if (peso <= 0 || altura <= 0) {
        printf("Erro: Peso e altura devem ser maiores que zero.\n");
        return 1;
    }
    
    imc = peso / (altura * altura);
    
    printf("\n=== RESULTADO ===\n");
    printf("IMC: %.2f\n", imc);
    printf("Classificação: ");
    
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    }
    else if (imc < 25) {
        printf("Peso normal\n");
    }
    else if (imc < 30) {
        printf("Sobrepeso\n");
    }
    else if (imc < 35) {
        printf("Obesidade Grau I\n");
    }
    else if (imc < 40) {
        printf("Obesidade Grau II\n");
    }
    else {
        printf("Obesidade Grau III (Obesidade Mórbida)\n");
    }
    
    return 0;
}