#include <stdio.h>

int num_calls, result;

int fib(X);

int main(){

    int N, X;

    scanf("%d", &N);

    for (int i=0; i<N; i++){

        scanf("%d", &X);

        num_calls = 0;

        printf("fib(%d) = %d calls = %d\n", X, num_calls-1, fib(X));
    }

    return 0;
}

int fib(int X){

    num_calls++;

    if (X == 0){
        return 0;
    }
    else if (X == 1){
        return 1;
    }
    else {
        return fib(X - 1) + fib(X - 2);
    }

}
