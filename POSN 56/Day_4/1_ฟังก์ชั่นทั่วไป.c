#include <stdio.h>
#include <conio.h>

float f(float x){
    return x*x + 3*x + 1;
}

int main(){
    float n;
    printf("  x\t  f(x)\n");
    printf("==============\n");
    for(n = 0; n <= 10; n += 0.5){
        printf("%4.1f\t%5.2f\n", n, f(n));
    }
    getch();
}
