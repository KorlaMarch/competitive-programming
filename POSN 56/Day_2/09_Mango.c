#include <stdio.h>

int main(){
    int price;
    float weight, total;
    printf("Enter Price : "); scanf("%d", &price);
    printf("Enter Weight : "); scanf("%f", &weight);
    total = price * weight;

    if(total > 300){
        total = total*0.85;
    }else if(total > 200){
        total = total*0.9;
    }else if(total > 100){
        total = total*0.95;
    }

    printf("Total price is : %.2f", total*1.07);
}
