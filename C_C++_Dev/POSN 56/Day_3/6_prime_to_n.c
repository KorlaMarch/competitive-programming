#include <stdio.h>
#include <math.h>
#include <conio.h>

int checkPrime(int n){
    int x;
    if(n % 2 == 0 && n != 2){
        return 0;
    }else{
        for(x = 3; x < sqrt(n); x += 2){
            if(n % x == 0){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int n, x, total = 0;
    printf("input : "); scanf("%d", &n);

    for(x = 2; x <= n; x++){
        total += checkPrime(x);
    }

    printf("total = %d", total);
    getch();
    return 0;
}
