#include <stdio.h>
#include <math.h>

int fmaior (int a, int b);

int main() {

    int p, s, t, maior;

    scanf("%d%d%d", &p, &s, &t);

    maior = fmaior(p, s);
    maior = fmaior(maior, t);

    printf("%d eh o maior\n", maior);

    return 0;
}

int fmaior (int a, int b){

    int maior;

    maior = (a+b+ abs(a-b))/2;

    return(maior);

}
