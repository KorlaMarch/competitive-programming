#include "stdio.h"

char operS[205];
int evarS[205];
int topEvar,topOper,n;

int getP(char c){
    switch(c){
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '(': return 0;
    }
}
void cal(char c){
    switch(c){
    case '+': evarS[topEvar-2] = evarS[topEvar-2]+evarS[topEvar-1]; break;
    case '-': evarS[topEvar-2] = evarS[topEvar-2]-evarS[topEvar-1]; break;
    case '*': evarS[topEvar-2] = evarS[topEvar-2]*evarS[topEvar-1]; break;
    case '/': evarS[topEvar-2] = evarS[topEvar-2]/evarS[topEvar-1]; break;
    }
    topEvar--;
}
void push(){
    if(!n) return;
    evarS[topEvar] = n;
    topEvar++;
    n=0;
}
int main(){
    char s[401];
    int i;
    scanf(" %s",s);
    for(i=n=0; s[i]; i++){
        if(s[i]>='0'&&s[i]<='9'){
            n *= 10;
            n += s[i]-'0';
        }else if(s[i] == ')'){
            push();
            topOper--;
            while(operS[topOper] != '('){
                cal(operS[topOper]);
                topOper--;
            }
        }else if(s[i] == '('){
            operS[topOper] = s[i];
            topOper++;
        }else{
            push();
            while(getP(s[i]) <= getP(operS[topOper-1]) && topOper){
                topOper--;
                cal(operS[topOper]);
            }
            operS[topOper] = s[i];
            topOper++;
        }
    }
    if(n){
        push();
    }

    while(getP(s[i]) <= getP(operS[topOper-1]) && topOper){
        topOper--;
        cal(operS[topOper]);
    }
    printf("%d\n", evarS[0]);
}
