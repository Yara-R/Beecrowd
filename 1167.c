#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

    char nome[30];
    int valor;

    struct Node* prox;
    struct Node* ant;
} Node;


typedef struct ListaCircular {

    Node* head;
    Node* tail;
} ListaCircular;


ListaCircular* criar_lista();
void inserir(ListaCircular* lista, char nome[30], int valor);
void remover(ListaCircular* lista, Node* no);


int main() {

    int n, i;

    while (scanf("%d", &n) && n) {

        ListaCircular* lista = criar_lista();

        for (i = 0; i < n; i++) {

            char nome[30];
            int valor;

            scanf(" %s %d", nome, &valor);
            inserir(lista, nome, valor);
        }

        Node* atual = lista->head;

        int marcados = 0;
        int comp = atual->valor;

        while (marcados < n - 1) {

            if (comp % 2 != 0) {

                Node* proximo = atual->prox;
                comp %= n;
                remover(lista, atual);
                atual = proximo;
            } 
            else {

                Node* anterior = atual->ant;
                comp %= n;
                remover(lista, atual);
                atual = anterior;
            }

            comp = atual->valor;
            marcados++;
        }

        printf("Vencedor(a): %s\n", lista->head->nome);
        free(lista);
    }

    return 0;
}


ListaCircular* criar_lista() {

    ListaCircular* lista = (ListaCircular*)malloc(sizeof(ListaCircular));

    if (lista != NULL) {

        lista->head = NULL;
        lista->tail = NULL;
    }

    return lista;
}


void inserir(ListaCircular* lista, char nome[30], int valor) {

    Node* novo_no = (Node*)malloc(sizeof(Node));

    if (novo_no != NULL) {

        strcpy(novo_no->nome, nome);

        novo_no->valor = valor;
        novo_no->prox = lista->head;
        novo_no->ant = lista->tail;

        if (lista->head == NULL) {

            lista->head = novo_no;
            lista->tail = novo_no;
        } 
        else {

            lista->tail->prox = novo_no;
            lista->head->ant = novo_no;
            lista->tail = novo_no;
        }
    }
}


void remover(ListaCircular* lista, Node* no) {

    if (no->prox == no) {

        lista->head = NULL;
        lista->tail = NULL;
    } 
    else {

        no->ant->prox = no->prox;
        no->prox->ant = no->ant;

        if (no == lista->head) {

            lista->head = no->prox;
        } 
        else if (no == lista->tail) {

            lista->tail = no->ant;
        }
    }

    free(no);
}