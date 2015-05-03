#include "stdio.h"

int getV(int n, char oper){
    return oper == '+' ? n : n*-1;
}

int main(){
    char s[301];
    int i,j,sum,a;
    char lastOper = '+';
    scanf(" %s", s);

    for(i = sum = a = 0; s[i] != '\0'; i++){
        if(s[i] == '+' || s[i] == '-'){
            sum += getV(a, lastOper);
            a = 0;
            lastOper = s[i];
        }else{
            a *= 10;
            a += s[i]-'0';
        }
        //printf("%d\n", sum);
    }
    sum += getV(a, lastOper);
    printf("%d\n", sum);
}
