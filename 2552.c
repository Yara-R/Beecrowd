#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {

        int **board = (int **) malloc(N * sizeof(int *));
        int **new_board = (int **) malloc(N * sizeof(int *));

        for (int i = 0; i < N; i++) {
            board[i] = (int *) malloc(M * sizeof(int));
            new_board[i] = (int *) malloc(M * sizeof(int));
        }


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &board[i][j]);
            }
        }


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 1) {
                    new_board[i][j] = 9;
                } else {
                    int pao_de_queijo = 0;
                    if (i > 0 && board[i - 1][j] == 1) {
                        pao_de_queijo++;
                    }
                    if (i < N - 1 && board[i + 1][j] == 1) {
                        pao_de_queijo++;
                    }
                    if (j > 0 && board[i][j - 1] == 1) {
                        pao_de_queijo++;
                    }
                    if (j < M - 1 && board[i][j + 1] == 1) {
                        pao_de_queijo++;
                    }
                    new_board[i][j] = pao_de_queijo;
                }
                printf("%d", new_board[i][j]);
            }
            printf("\n");
        }


        for (int i = 0; i < N; i++) {
            free(board[i]);
            free(new_board[i]);
        }

        free(board);
        free(new_board);
    }

    return 0;
}
