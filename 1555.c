#include <stdio.h>

int r (int x, int y);
int b (int x, int y);
int c (int x, int y);

int main() {

    int N, x, y, R, B, C;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d%d", &x, &y);

        R = r(x, y);
        B = b(x, y);
        C = c(x, y);

        if (R > B && R > C ){
            printf("Rafael ganhou\n");
        } else if (B > R && B > C){
            printf("Beto ganhou\n");
        } else {
            printf("Carlos ganhou\n");
        }

    }
   return 0;
}

int r (int x, int y){
    int r;
    r = 9*x*x + y*y;
    return r;
}

int b (int x, int y){
    int b;
    b = 2*x*x + 25*y*y;
    return b;
}

int c (int x, int y){
    int c;
    c = (-100)*x + y*y*y;
    return c;
}
