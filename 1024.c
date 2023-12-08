#include <stdio.h>
#include <string.h>

int main() {
    int N, size;
    char M[1000], ch;

    scanf("%d", &N);

    for(int k=0; k<N; k++){

        scanf(" %[^\n]", M);
        size = strlen(M);

        for(int i=0; i<size; i++){

            if((M[i]>='A' && M[i]<='Z') || (M[i]>='a'&& M[i]<='z')){

                M[i] = M[i] + 3;
            }
        }


        for(int i=0; i<size/2; i++){

            ch = M[i];
            M[i] = M[size-1-i];
            M[size-1-i] = ch;
        }


        for(int i=size/2; i<size; i++){

            if (M[i] >= 32 && M[i] <= 176 ){

                M[i] = M[i]-1;
            }
        }


        printf("%s\n", M);
    }

    return 0;
}
