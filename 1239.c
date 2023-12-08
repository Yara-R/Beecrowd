#include <stdio.h>
#include <string.h>

int main(){

    char text[51];
    int size, N, I;

    while(fgets(text, 51, stdin) != NULL){

        N = 0;
        I = 0;
        size = strlen(text);

        for(int i = 0; i < size; ++i){

            if(text[i] == '_'){
                printf("%s", I ? "</i>" : "<i>");
                I = 1 - I;
            }
            
            else if(text[i] == '*'){
                printf("%s", N ? "</b>" : "<b>");
                N = 1 - N;
            }

            else{
                printf("%c", text[i]);
            }
        }
    }

    return 0;
}
