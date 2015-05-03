#include <stdio.h>
#include <stdlib.h>

int main(){
    int sum = 0, sumEven = 0, sumOdd = 0;
    int n = 0;
    char c[2] = "0";
    char bc[2] = "0";
    do{
        bc[0] = c[0];
        c[0] = (char)getchar();
        //for 3
        sum += atoi(c);

        //for 11
        if(n % 2 == 1){
            sumEven += atoi(bc)*10 + atoi(c);
        }else{
            sumOdd += atoi(bc)*10 + atoi(c);
        }

        n++;
    }while(c[0] != '\n');
    if(n % 2 == 1){
        printf("%d %d", sum % 3, sumEven % 11);
    }else{
        printf("%d %d", sum % 3, sumOdd % 11);
    }
}
