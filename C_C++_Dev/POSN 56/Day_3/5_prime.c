#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(){
    int n, x;
    printf("Enter number to check : "); scanf("%d", &n);

    if(n % 2 == 0 && n != 2){
        printf("This number isn't prime number");
    }else{
        for(x = 3; x < sqrt(n); x += 2){
            if(n % x == 0){
                printf("This number isn't prime number");
                return 0;
            }
        }
        printf("This number is prime number.");

    }
    getch();
    return 0;
}
