#include <stdio.h>

int main() {
    int N=1, i, j, y;

    while(N!=0){

        scanf("%d", &N);

        if(N == 0){
            break;
        }

        int mat[N][N];

        for(i=1; i <= N; i++){
            for(j=1; j<= N; j++){
                 for (y = 0; y <= (N/2); y++){
                    if ((i == N-y)||(i == y+1)||(j == N-y)||(j == y+1)){
                        mat[i-1][j-1] = y + 1;
                        y = N;
                    }
                }
            }
        }

        for(i = 1;i <= N; i++){
            for(j = 1;j <= N; j++){
                if(j == 1){
                    printf("%3d", mat[i-1][j-1]);
                }
                else{
                    printf(" %3d", mat[i-1][j-1]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
