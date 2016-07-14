#include "stdio.h"
#include "conio.h"

int fx(int x){
    return x*x+3*x+1;
}

int main(){
    int i;
    printf(" x\tf(x)\n");
    for(i = 0; i <= 20; i++){
        printf("%2d\t%3d\n", i, fx(i));
    }
    getch();
}
