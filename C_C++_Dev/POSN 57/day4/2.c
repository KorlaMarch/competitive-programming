#include "stdio.h"
#include "conio.h"
#include "math.h"

int main(){
    int i;
    printf("x\tsin(x)\tcos(x)\n");
    for(i = 0; i <= 60; i += 5){
        printf("%d\t%.3f\t%.3f\n", i, sin(i*M_PI/180.0), cos(i*M_PI/180.0));
    }
    getch();
}
