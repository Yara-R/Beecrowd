#include <stdio.h>
#include <string.h>

int main(){

    char idioma[100], id[100];
    int N, K, igual;

    scanf("%d", &N);

    for(int caso=0; caso<N; caso++){

        scanf("%d", &K);

        igual = 0;

        scanf("%s", &id);

        for(int pessoa=1; pessoa<K; pessoa++){

            scanf("%s", &idioma);

            if (strcmp(id, idioma) != 0){
                igual = 1;
            }

        }

        if(igual != 0){
            printf("ingles\n");
        }
        else{
            printf("%s\n", id);
        }

    }

    return 0;
}
