#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int matricula;
    char nome[100];
    float nota;
} Aluno;

int main() {
    int N, L;
    float media = 0.0;

    // Entrada do número de alunos e do índice de referência
    scanf("%d %d", &N, &L);

    Aluno alunos[MAX];

    // Leitura dos dados dos alunos
    for (int i = 0; i < N; i++) {
        scanf("%d", &alunos[i].matricula);
        scanf(" %[^\n]", alunos[i].nome);  // Leitura do nome com espaços
        scanf("%f", &alunos[i].nota);
        media += alunos[i].nota;
    }

    // Cálculo da média da turma
    media /= N;

    // Determinando a posição do aluno de referência (L-1 porque o índice do array começa em 0)
    Aluno *aluno_ref = &alunos[L - 1];

    // Saída das informações do aluno de referência
    printf("Matricula: %d\n", aluno_ref->matricula);
    printf("Nome: %s\n", aluno_ref->nome);
    printf("Nota Final: %.2f\n", aluno_ref->nota);

    // Verificação da posição do aluno em relação à média
    if (aluno_ref->nota > media) {
        printf("ACIMA DA MEDIA\n");
    } else if (aluno_ref->nota < media) {
        printf("ABAIXO DA MEDIA\n");
    } else {
        printf("NA MEDIA\n");
    }

    return 0;
}
