#include <stdio.h>

#define NUM_ALUNOS 30

int main() {
    float nota1[NUM_ALUNOS];
    float nota2[NUM_ALUNOS];
    float media[NUM_ALUNOS];
    float media_turma = 0.0;
    int i;
    
 
    printf("Digite as notas dos 30 alunos:\n");
    for(i = 0; i < NUM_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Primeira nota: ");
        scanf("%f", &nota1[i]);
        printf("Segunda nota: ");
        scanf("%f", &nota2[i]);
        
        
        media[i] = (nota1[i] * 2 + nota2[i] * 3) / 5;
        media_turma += media[i];
    }
    
    
    media_turma /= NUM_ALUNOS;
    
    printf("\nMedia da turma: %.2f\n", media_turma);
    printf("\nAlunos acima da media da turma:\n");
    
    for(i = 0; i < NUM_ALUNOS; i++) {
        if(media[i] > media_turma) {
            printf("Aluno %d: Nota1=%.2f, Nota2=%.2f, Media=%.2f\n", 
                   i + 1, nota1[i], nota2[i], media[i]);
        }
    }
    
    return 0;
}