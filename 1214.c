#include <stdio.h>

int fmedia(float soma, int N);

int main() {

    int C, N, fg;
    float soma = 0.0, media;

    scanf("%d", &C);

    for (int i=0; i<C; i++){

        scanf("%d", &N);

        int fg[N];

        for(int j=0; j<N; j++){
            scanf("%d", &fg[j]);
            soma += fg[j];
        }

        media = fmedia(soma, N);

        int k = 0;
        for(int j=0; j<N; j++){
            if(fg[j] > media){
                k++;
            }
        }

        printf("%.3f%%\n", (k*100.0)/N);
        k = 0;
        soma = 0;
    }

    return 0;
}

int fmedia (float soma, int N){
    float m;
    m = soma/N;
    return m;
}
