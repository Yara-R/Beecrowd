#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* prox;
} Node;

Node* newNode(char data);
int isEmpty(Node* stack);
void push(Node** stack, char data);
char pop(Node** stack);
int qntDeDiamantes(char* input);

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char input[1001];
        scanf("%s", input);

        int diamantes = qntDeDiamantes(input);
        
        printf("%d\n", diamantes);
    }

    return 0;
}

Node* newNode(char data) {

    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->prox = NULL;

    return node;
}

int isEmpty(Node* stack) {

    return (stack == NULL);
}

void push(Node** stack, char data) {

    Node* newNodePtr = newNode(data);
    newNodePtr->prox = *stack;
    *stack = newNodePtr;
}

char pop(Node** stack) {

    if (isEmpty(*stack)) {

        return '\0';
    }

    Node* temp = *stack;
    *stack = (*stack)->prox;
    char data = temp->data;

    free(temp);

    return data;
}

int qntDeDiamantes(char* input) {

    Node* stack = NULL;
    int diamantes = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char atual = input[i];

        if (atual == '<') {

            push(&stack, atual);
        } 
        else if (atual == '>' && pop(&stack) == '<') {

            diamantes++;
        }
    }

    while (!isEmpty(stack)) {

        pop(&stack);
    }

    return diamantes;
}
