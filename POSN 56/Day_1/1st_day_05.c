#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
    int u,a,t;
    printf("Enter U : "); scanf("%d", &u);
    printf("Enter T : "); scanf("%d", &t);
    printf("Enter A : "); scanf("%d", &a);
    system("cls");
    printf("%1.2f", u*t + 0.5*a*t*t);
    getch();
    return 0;
}
