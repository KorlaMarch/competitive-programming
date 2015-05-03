#include "stdio.h"
#include "conio.h"
#include "math.h"

int main(){
    int r,h;
    printf("Radius:");
    scanf("%d", &r);
    printf("Hight:");
    scanf("%d", &h);
    printf("Area is %.2f", M_PI*r*r*h);
    getch();
}
