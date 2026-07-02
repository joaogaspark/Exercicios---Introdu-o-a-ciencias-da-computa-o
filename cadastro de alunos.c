#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5
#define NUM_NOTAS 3

typedef struct {
    char nome[50];
    float notas[NUM_NOTAS];
    float media;
    char situacao[15];
} Aluno;

float calcularMedia(float notas[NUM_NOTAS]) {
    float soma = 0;
    for (int i = 0; i < NUM_NOTAS; i++) {
        soma += notas[i];
    }
    return soma / NUM_NOTAS;
}

int main() {
    Aluno turma[MAX_ALUNOS];
    int totalAlunos;

    printf("=== CADASTRO DE ALUNOS ===\n");
    printf("Quantos alunos deseja cadastrar (1 a %d)? ", MAX_ALUNOS);
    scanf("%d", &totalAlunos);

    if (totalAlunos < 1 || totalAlunos > MAX_ALUNOS) {
        printf("Quantidade invalida! Encerrando o programa.\n");
        return 1;
    }

    for (int i = 0; i < totalAlunos; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", turma[i].nome);

        for (int j = 0; j < NUM_NOTAS; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &turma[i].notas[j]);
        }

        turma[i].media = calcularMedia(turma[i].notas);

        if (turma[i].media >= 7.0) {
            strcpy(turma[i].situacao, "Aprovado");
        } else {
            strcpy(turma[i].situacao, "Reprovado");
        }
    }

    printf("\n=================== RESULTADOS ===================\n");
    printf("%-15s %-8s %-8s %-8s %-8s %-10s\n",
           "Nome", "Nota1", "Nota2", "Nota3", "Media", "Situacao");
    printf("----------------------------------------------------\n");

    int indiceMaior = 0;
    for (int i = 0; i < totalAlunos; i++) {
        printf("%-15s %-8.1f %-8.1f %-8.1f %-8.2f %-10s\n",
               turma[i].nome,
               turma[i].notas[0],
               turma[i].notas[1],
               turma[i].notas[2],
               turma[i].media,
               turma[i].situacao);

        if (turma[i].media > turma[indiceMaior].media) {
            indiceMaior = i;
        }
    }

    printf("\nAluno com a maior media da turma: %s (Media: %.2f)\n",
           turma[indiceMaior].nome, turma[indiceMaior].media);

    return 0;
}
