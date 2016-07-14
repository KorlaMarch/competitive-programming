#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
    int x;
    scanf("%d", &x);
    printf("%1.2f", sqrt((x*x)/(4+sqrt(x))));
    getch();
    return 0;
}
