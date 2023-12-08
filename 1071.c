#include <stdio.h>
 
int main() {
 
    int X, Y, min, max, sum = 0, i;
    
    scanf("%d", &X);
    scanf("%d", &Y);
    
    if(X < Y){
        min = X;
        max = Y;
    }else{
        max = X;
        min = Y;
    }
    
    for(i = (min + 1); i < max; ++i){
        if(i%2 != 0){
            sum += i;
        }
    }
    
    printf("%d\n", sum);
 
    return 0;
}
