#include <stdio.h>

int main(){

    int P, N, i, salto, result = 1;

    scanf("%d%d", &P, &N);

    int height[N];

    for(i = 0; i < N; i++){
        scanf("%d",&height[i]);
    }

    for(i = 0; i < N-1; i++){
        salto = height[i+1] - height[i];

        if(salto < 0){
            salto *= -1;
        }

        if(salto > P){
            result = 0;
            break;
        }
    }

    if(result == 0){
        printf("GAME OVER\n");
    }
    else {
        printf("YOU WIN\n");
    }

    return 0;
}
