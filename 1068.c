#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct stack{
    int head;
    char data[MAX];
};

void push(struct stack *p, char dado);

char pop(struct stack *p);

int isEmpty(struct stack *p);

int main() {
    
    char EN[MAX];
    struct stack s;

    while(fgets(EN, MAX, stdin) != NULL) {
        
        s.head = -1;
        int len = strlen(EN);
        int veri = 1;

        for (int i = 0; i < len; i++) {

            if (EN[i] == '(') {
                push(&s, '(');
            } 
            else if (EN[i] == ')') {

                if (!isEmpty(&s) && pop(&s) == '(') {
                    continue;
                } 
                else {
                    veri = 0;
                    break;
                }
            }
        }

        if (veri && isEmpty(&s)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}

void push(struct stack *p, char dado) {
    p->head++;
    p->data[p->head] = dado;
}

char pop(struct stack *p) {
    char dado = p->data[p->head];
    p->head--;
    return dado;
}

int isEmpty(struct stack *p) {
    return p->head == -1;
}
