#include <stdio.h>
#include <conio.h>

int getValue(char c){
    if(c >= 'a' && c <= 'z') c = c - 0x20;
    switch(c){
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
}

int main(){
    char roman[64];
    int sum = 0;
    int x;
    printf("Enter roman : "); gets(roman);

    for(x = 0; roman[x] != '\0'; x++){
        if(roman[x + 1] != '\0' && getValue(roman[x]) < getValue(roman[x+1])){
            sum -= getValue(roman[x]);
        }else{
            sum += getValue(roman[x]);
        }
    }

    printf("%d\n", sum);
    getch();
    return 0;
}
