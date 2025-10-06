#include <stdio.h>
\\ mehorar depois
int main() {
    printf("Tabela ASCII:\n");
    printf("\n");
    for (int i = 0; i < 128; i++) {
        if (i >= 32 && i <= 126) {
            // Caracteres imprimíveis
            printf("%3d   %c\n", i, i);
        } else {
            // Caracteres de controle
            printf("%3d   .\n", i);
        }
    }
    return 0;
}
