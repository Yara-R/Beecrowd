#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int numero;
    int nota;
} Aluno;

typedef struct Node {
    Aluno aluno;
    struct Node* prox;
} Node;


void enqueue(Node** fila, Aluno aluno);
void reordenar(Node** fila);

int main() {
    int N, M, i, j;
    scanf("%d", &N);

    for (i = 0; i < N; i++) {

        scanf("%d", &M);
        Node* fila = NULL;
        Aluno alunos[M];

        for (j = 0; j < M; j++) {

            scanf("%d", &alunos[j].nota);
            alunos[j].numero = j + 1;
            enqueue(&fila, alunos[j]);
        }

        reordenar(&fila);

        int naoTrocam = 0;

        for (j = 0; j < M; j++) {
            if (alunos[j].numero == fila->aluno.numero) {
                naoTrocam++;
            }
            fila = fila->prox;
        }

        printf("%d\n", naoTrocam);
    }

    return 0;
}


void enqueue(Node** fila, Aluno aluno) {
    Node* novo = (Node*)malloc(sizeof(Node));

    novo->aluno = aluno;
    novo->prox = NULL;

    if (*fila == NULL) {

        *fila = novo;
    } 
    else {

        Node* atual = *fila;

        while (atual->prox != NULL) {

            atual = atual->prox;
        }

        atual->prox = novo;
    }
}


void reordenar(Node** fila) {

    if (*fila == NULL) {

        return;
    }

    Node* atual = *fila;
    Node* prox;
    Aluno temp;

    while (atual->prox != NULL) {

        prox = atual->prox;

        while (prox != NULL) {

            if (atual->aluno.nota < prox->aluno.nota) {

                temp = atual->aluno;
                atual->aluno = prox->aluno;
                prox->aluno = temp;
            }

            prox = prox->prox;
        }

        atual = atual->prox;
    }
}