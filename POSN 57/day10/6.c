#include "stdio.h"

void toUpper(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 0x20;
        }
    }
}

int getValue(char c){
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
    default:
        return -1;
    }
}

int main(){
    char r[32];
    int i,n;
    gets(r);
    toUpper(r);

    for(i = n = 0; r[i] != '\0'; i++){
        if(getValue(r[i]) == -1){
            printf("Error!\n");
            return -1;
        }else if(getValue(r[i]) < getValue(r[i+1])){
            n += getValue(r[i+1])-getValue(r[i]);
            i++;
        }else{
            n += getValue(r[i]);
        }
    }
    printf("= %d\n", n);
}
