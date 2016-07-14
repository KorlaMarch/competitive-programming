#include <stdio.h>

int main(){
    int a, b, n;
    scanf("%d%d", &a, &b);
    if(a > b){
        n = a;
    }else{
        n = b;
    }

    while(1){
        if(a % n == 0 && b % n == 0){
            printf("%d", n);
            break;
        }
        n--;
    }

}
