#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

    char nome[50];
    int ouro;
    int prata;
    int bronze;

    struct Node* prox;
} Node;

int main() {

    int N;
    scanf("%d", &N);

    Node* paises = NULL;

    for (int i = 0; i < N; i++) {

        char nome[50];
        int ouro, prata, bronze;

        scanf("%s %d %d %d", nome, &ouro, &prata, &bronze);
        inserir(&paises, nome, ouro, prata, bronze);
    }

    insertionSort(&paises);
    imprimir(paises);

    while (paises != NULL) {

        Node* temp = paises;
        paises = paises->prox;
        free(temp);
    }

    return 0;
}


void inserir(Node** head, char nome[], int ouro, int prata, int bronze) {

    Node* pais = (Node*)malloc(sizeof(Node));
    strcpy(pais->nome, nome);

    pais->ouro = ouro;
    pais->prata = prata;
    pais->bronze = bronze;

    pais->prox = NULL;

    if (*head == NULL) {

        *head = pais;
    } 
    else {

        Node* current = *head;
        while (current->prox != NULL) {

            current = current->prox;
        }
        current->prox = pais;
    }
}


void insertionSort(Node** head) {

    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {

        Node* prox = current->prox;

        if (sorted == NULL || (current->ouro > sorted->ouro) ||
            (current->ouro == sorted->ouro && current->prata > sorted->prata) ||
            (current->ouro == sorted->ouro && current->prata == sorted->prata && current->bronze > sorted->bronze) ||
            (current->ouro == sorted->ouro && current->prata == sorted->prata && current->bronze == sorted->bronze &&
             strcmp(current->nome, sorted->nome) < 0)) {

            current->prox = sorted;
            sorted = current;
        } 
        else {

            Node* temp = sorted;

            while (temp->prox != NULL &&
                   (current->ouro < temp->prox->ouro ||
                    (current->ouro == temp->prox->ouro && current->prata < temp->prox->prata) ||
                    (current->ouro == temp->prox->ouro && current->prata == temp->prox->prata && current->bronze < temp->prox->bronze) ||
                    (current->ouro == temp->prox->ouro && current->prata == temp->prox->prata && current->bronze == temp->prox->bronze &&
                     strcmp(current->nome, temp->prox->nome) > 0))) {

                temp = temp->prox;
            }

            current->prox = temp->prox;
            temp->prox = current;
        }

        current = prox;
    }

    *head = sorted;
}


void imprimir(Node* head) {

    while (head != NULL) {

        printf("%s %d %d %d\n", head->nome, head->ouro, head->prata, head->bronze);
        head = head->prox;
    }
}