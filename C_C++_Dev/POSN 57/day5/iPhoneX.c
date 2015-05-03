#include "stdio.h"
#include "conio.h"

int main(){
    int y;
    double price=30000,money=20821,h=4.7;
    for(y = 0; money < price; y++){
        money += money*0.0025;
        money += 100.0;
        if(y % 24 == 0 && y){
            price *= 1.1;
            h *= 1.1;

        }
        if(y % 12 == 0)
            printf("%f %f\n", price, money);
    }
    printf("Need %d years before she can buy iPhone %d that long %.2f inch %.2f\n", y/12, y/24+6, h, price);
    getch();
}
