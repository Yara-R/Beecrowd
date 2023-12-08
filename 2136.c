#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[51];
    char escolha[4];
    struct Node* prox;
    struct Node* ant;
} Node;

Node* criar(char nome[], char escolha[]);
void inserirNaOrdem(Node** head, Node* novo);
int repetido(Node* head, char nome[]);
void imprimir(Node* head);

int main() {
    Node* lista = NULL;
    char nome[51], escolha[4];
    char amigoDoHabay[51] = "";
    int letras = 0;

    while (1) {
        scanf("%s", nome);

        if (strcmp(nome, "FIM") == 0) {
            break;
        }

        scanf("%s", escolha);

        if (!repetido(lista, nome)) {

            Node* novo = criar(nome, escolha);
            inserirNaOrdem(&lista, novo);

           
            int letrasNome = strlen(nome);

            if (strcmp(escolha, "YES") == 0 && letrasNome > letras) {

                strcpy(amigoDoHabay, nome);
                letras = letrasNome;
            }
        }
    }

    imprimir(lista);

    printf("\nAmigo do Habay:\n");

    printf("%s\n", amigoDoHabay);

    return 0;
}

Node* criar(char nome[], char escolha[]) {

    Node* novo = (Node*)malloc(sizeof(Node));

    strcpy(novo->nome, nome);
    strcpy(novo->escolha, escolha);

    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

void inserirNaOrdem(Node** head, Node* novo) {

    if (*head == NULL) {

        *head = novo;
        return;
    }

    Node* aux = *head;
    Node* ant = NULL;

    while (aux != NULL && (strcmp(novo->escolha, aux->escolha) < 0 ||
                           (strcmp(novo->escolha, aux->escolha) == 0 &&
                            strcmp(novo->nome, aux->nome) > 0))) {
        ant = aux;
        aux = aux->prox;
    }

    if (ant != NULL) {

        ant->prox = novo;
        novo->ant = ant;
    } 
    else {

        *head = novo;
    }

    if (aux != NULL) {

        novo->prox = aux;
        aux->ant = novo;
    }
}

int repetido(Node* head, char nome[]) {

    Node* aux = head;

    while (aux != NULL) {

        if (strcmp(aux->nome, nome) == 0) {

            return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

void imprimir(Node* head) {

    Node* aux = head;

    while (aux != NULL) {
        
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
}
