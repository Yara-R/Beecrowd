#include <stdio.h>
 
int main() {
 
    int N, i, menor, posicao;
    int X[1000];
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++){
        scanf("%d", &X[i]);
    }
    
    menor = X[0];
    
    for(i=0; i<N; i++){
        if(X[i] < menor){
            menor = X[i];
            posicao = i;
        }
    }
 
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}
