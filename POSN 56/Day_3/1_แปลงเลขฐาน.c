#include <stdio.h>
#include <conio.h>

int main(){
    int input,i = 0, x;
    char bit[20];
    printf("Input Decimal : "); scanf("%d", &input);

    //convent 10 to 2
    do{
        bit[i] = (input % 2) + '0';
        input = input / 2;
        i++;
    }while(input != 0);

    //output
    printf("Binary is ");
    for(x = i - 1; x >= 0; x--){
        putchar(bit[x]);
    }
    getch();
}
