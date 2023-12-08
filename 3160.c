#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(){

    char L[MAX][MAX], N[MAX], S[MAX];
    int i, num_friends = 0, S_location = -1;
    char *token;

    fgets(S, MAX, stdin);
    S[strcspn(S, "\n")] = '\0';
    token = strtok(S, " ");

    while (token != NULL && num_friends < MAX) {
        strcpy(L[num_friends], token);
        num_friends++;
        token = strtok(NULL, " ");
    }

    fgets(N, MAX, stdin);
    N[strcspn(N, "\n")] = '\0';

    fgets(S, MAX, stdin);
    S[strcspn(S, "\n")] = '\0';

    if (strcmp(S, "nao") != 0){
        for (i = 0; i < num_friends; i++) {
            if (strcmp(L[i], S) == 0) {

                S_location = i;
                break;
            }
        }
    }

    if (num_friends == 0 || S_location == -1) {

        strcpy(L[num_friends], N);
        num_friends++;
    }
    else {
        for (i = num_friends-1; i >= S_location; i--) {

            strcpy(L[i+1], L[i]);
        }

        strcpy(L[S_location], N);
        num_friends++;
    }

    for (i = 0; i < num_friends; i++) {

        printf("%s", L[i]);

        if (i < num_friends-1) {

            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
