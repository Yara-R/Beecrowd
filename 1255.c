#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char letra[201];
    int N, l, most, freq[201];

    scanf("%d", &N);

    for(int k=0; k<N; k++){

        scanf(" %[^\n]", &letra);

        int j = 97;
        while(j <= 122){
            freq[j] = 0;
            j++;
        }

        int i = 0;
        most = 0;
        while(letra[i] != '\0'){

            if(letra[i] >= 65 && letra[i] <= 90){
                letra[i] += 32;
            }

            if(letra[i] >= 97 && letra[i] <= 122){

                l = letra[i];
                freq[l]++;

                if(freq[l] > most){
                    most = freq[l];
                }

            }

            i++;
        }

        for(char j = 'a'; j <= 'z'; j++){

            if(freq[j] == most){
                printf("%c", j);
            }

        }

        printf("\n");
    }

    return 0;
}
