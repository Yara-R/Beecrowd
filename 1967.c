#include <stdio.h>

int main (){

    int G, A, M, C, i, j, k;

    scanf("%d%d%d%d", &G, &A, &M, &C);

    int GA[G][A];

    for (i=0; i < G; i++){
        for(j=0; j < A; j++){
            scanf("%d", &GA[i][j]);
        }
        }

    int AM[A][M];

    for (i=0; i < A; i++){
        for(j=0; j < M; j++){
            scanf("%d", &AM[i][j]);
        }
    }

    int MC[M][C];

    for (i=0; i < M; i++){
        for(j=0; j < C; j++){
            scanf("%d", &MC[i][j]);
        }
    }


    int aux[G][M];

    for (i = 0; i < G; i++){
        for(j=0; j < M; j++) {
            aux[i][j] = 0;
            for (k = 0; k < A; k++) {
                aux[i][j] += GA[i][k] * AM[k][j];
            }
        }
    }

    int GC[G][C];

    for (i = 0; i < G; i++){
        for(j=0; j < C; j++) {
            GC[i][j] = 0;
            for (k = 0; k < M; k++) {
                GC[i][j] += aux[i][k] * MC[k][j];
            }
        }
    }

    int dig[j];

    for(j = 0;j < C; j++){
        dig[j] = 0;
        if (GC[i][j] >= dig[j]){
            GC[i][j] = dig[j];
        }
    }

    for(i = 0;i < G; i++){
        for(j = 0;j < C; j++){
            printf("%*d ", dig[j], GC[i][j]);
        }
        printf("\n");
    }


    return 0;
}
