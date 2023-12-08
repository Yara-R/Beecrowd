#include <stdio.h>
#include <math.h>

struct hunter {
    int R1;
    int X1;
    int Y1;
};

struct flower {
    int R2;
    int X2;
    int Y2;

};

int main(){

    struct hunter hunt;
    struct flower flor;

    double d;

    while (scanf("%d %d %d %d %d %d",&hunt.R1, &hunt.X1, &hunt.Y1, &flor.R2, &flor.X2, &flor.Y2) != EOF) {

        d = sqrt(((flor.X2-hunt.X1)*(flor.X2-hunt.X1))+((flor.Y2-hunt.Y1)*(flor.Y2-hunt.Y1)));

        if(hunt.R1 >= d + flor.R2){
            printf("RICO\n");
        }
        else{
            printf("MORTO\n");
        }

    }


    return 0;
}
