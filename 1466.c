#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    
    int data;
    struct Node* esq;
    struct Node* dir;
} Node;

Node* createNode(int valor) {
    
    Node* novo = (Node*)malloc(sizeof(Node));
    
    novo->data = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    
    return novo;
}

Node* inserir(Node* raiz, int valor);
void levelOrderTraversal(Node* raiz);
void funcaofree(Node* raiz);

int main() {
    int T;

    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int N;
        scanf("%d", &N);

        Node* raiz = NULL;

        for (int i = 0; i < N; ++i) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", t);

        levelOrderTraversal(raiz);

        printf("\n\n");

        funcaofree(raiz);
    }

    return 0;
}

Node* inserir(Node* raiz, int valor) {
    
    if (raiz == NULL) {
        
        return createNode(valor);
    }

    if (valor < raiz->data) {
        
        raiz->esq = inserir(raiz->esq, valor);
    } 
    else if (valor > raiz->data) {
        
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

void funcaofree(Node* raiz) {
    
    if (raiz == NULL) {
        return;
    }

    funcaofree(raiz->esq);
    funcaofree(raiz->dir);

    free(raiz);
}

void levelOrderTraversal(Node* raiz) {
    
    if (raiz == NULL) {
        return;
    }

    Node** fila = (Node**)malloc(500 * sizeof(Node*));
    
    int front = 0;
    int rear = 0;

    fila[rear++] = raiz;

    while (front < rear) {
        
        Node* atual = fila[front++];
        printf("%d", atual->data);

        if (atual->esq != NULL) {
            fila[rear++] = atual->esq;
        }
        if (atual->dir != NULL) {
            fila[rear++] = atual->dir;
        }

        if (front < rear) {
            printf(" ");
        }
    }

    free(fila);
}
