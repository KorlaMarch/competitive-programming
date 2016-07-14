#include <stdio.h>

int main(){
    int money;
    printf("Enter Money :"); scanf("%d", &money);
    printf("B 1000 = %d\n", money / 1000);
    printf("B 500  = %d\n", (money%1000)/500);
    printf("B 100  = %d\n", (money%500)/100);
    return 0;
}
