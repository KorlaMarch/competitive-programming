#include <stdio.h>
#include <conio.h>

int main(){
    int c[16];
    int x, sum = 0;
    for(x = 0; x < 16; x++){
        c[x] = getchar() - '0';
    }

    for(x = 15; x >= 0; x--){
        if(x % 2 == 0){
            c[x] = c[x] * 2;
            if(c[x] >= 10){
                c[x] = c[x] % 10 + c[x]/10;
            }
        }
        sum += c[x];
    }

    if(sum % 10 == 0){
        printf("Value");
    }else{
        printf("Not value");
    }
}
