#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
    struct Node* ant;
} Node;

Node* createNode(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

int main() {
    int N, k, m;

    while (1) {
        scanf("%d %d %d", &N, &k, &m);

        if (N == 0 && k == 0 && m == 0) {
            break;
        }

        Node* head = createNode(1);
        Node* tail = head;

        for (int i = 2; i <= N; i++) {

            tail->prox = createNode(i);
            tail->prox->ant = tail;
            tail = tail->prox;
        }

        tail->prox = head;
        head->ant = tail;

        Node* sentidoHorario = head;
        Node* sentidoAntiHorario = tail;

        int removedCount = 0;

        while (removedCount < N) {
            for (int i = 1; i < k; i++) {

                sentidoHorario = sentidoHorario->prox;
            }

            for (int i = 1; i < m; i++) {

                sentidoAntiHorario = sentidoAntiHorario->ant;
            }

            if (sentidoHorario == sentidoAntiHorario) {

                printf("%3d", sentidoHorario->valor);
                removedCount++;
            } 
            else {

                printf("%3d%3d", sentidoHorario->valor, sentidoAntiHorario->valor);
                removedCount += 2;
            }

            if (removedCount < N) {
                printf(",");
            }

            Node* tempHorario = sentidoHorario;
            Node* tempAntiHorario = sentidoAntiHorario;

            sentidoHorario = sentidoHorario->prox;
            sentidoAntiHorario = sentidoAntiHorario->ant;

            tempHorario->ant->prox = tempHorario->prox;
            tempHorario->prox->ant = tempHorario->ant;

            free(tempHorario);

            if (tempHorario != tempAntiHorario) {

                tempAntiHorario->ant->prox = tempAntiHorario->prox;
                tempAntiHorario->prox->ant = tempAntiHorario->ant;
                
                free(tempAntiHorario);
            }
        }

        printf("\n");

        Node* current = head;

        do {
            Node* prox = current->prox;

            free(current);
            current = prox;

        } while (current != head);
    }

    return 0;
}
