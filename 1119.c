#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node* prev;
    struct Node* next;
    int removido;
} Node;

void inicializar_lista(Node** head, Node** tail, int n);
void marcar_como_removido(Node** head, Node** tail, Node* node);
Node* proximo_nao_removido(Node* node, int direcao);
int tamanho_nao_removido(Node* head, Node* tail);

int main(int argc, char** argv) {

    int n, k, m;

    while (scanf("%d %d %d", &n, &k, &m), n) {

        Node* head = NULL;
        Node* tail = NULL;

        inicializar_lista(&head, &tail, n);

        Node* K = head;
        Node* M = tail;

        while (tamanho_nao_removido(head, tail) > 2) {
            
            K = proximo_nao_removido(K, 1);
            M = proximo_nao_removido(M, 0);

            for (int i = 1; i < k; ++i) {
                K = proximo_nao_removido(K, 1);
            }

            for (int i = 1; i < m; ++i) {
                M = proximo_nao_removido(M, 0);
            }

            if (K == M) {
                printf("%3d,", K->id);
                marcar_como_removido(&head, &tail, K);
            } else {
                printf("%3d%3d,", K->id, M->id);
                marcar_como_removido(&head, &tail, K);
                marcar_como_removido(&head, &tail, M);
            }
        }

        if (tamanho_nao_removido(head, tail) == 2) {
            K = proximo_nao_removido(K, 1);
            M = proximo_nao_removido(M, 0);

            if (K == M) {
                printf("%3d,%3d\n", K->id, K->next->id);
            } else {
                printf("%3d%3d\n", K->id, M->id);
            }
        } else {
            printf("%3d\n", head->id);
        }

        free(head);
    }

    return 0;
}

void inicializar_lista(Node** head, Node** tail, int n) {

    *head = (Node*)malloc(sizeof(Node));

    *tail = *head;
    (*head)->id = 1;

    (*head)->prev = NULL;
    (*head)->next = NULL;

    (*head)->removido = 0;

    for (int i = 2; i <= n; ++i) {

        Node* novo_no = (Node*)malloc(sizeof(Node));

        novo_no->id = i;
        novo_no->prev = *tail;
        novo_no->next = NULL;
        novo_no->removido = 0;

        (*tail)->next = novo_no;
        *tail = novo_no;
    }

    (*head)->prev = *tail;
    (*tail)->next = *head;
}

void marcar_como_removido(Node** head, Node** tail, Node* node) {
    node->removido = 1;

    while ((*head)->removido) {
        *head = (*head)->next;
    }

    while ((*tail)->removido) {
        *tail = (*tail)->prev;
    }
}

Node* proximo_nao_removido(Node* node, int direcao) {

    if (direcao == 0) {
        node = node->prev;

        while (node->removido) {
            node = node->prev;
        }
    } else {
        node = node->next;

        while (node->removido) {
            node = node->next;
        }
    }

    return node;
}

int tamanho_nao_removido(Node* head, Node* tail) {

    int count = 0;
    Node* current = head;

    do {
        if (!current->removido) {
            count++;
        }

        current = current->next;
    } while (current != head);

    return count;
}
