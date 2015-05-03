#include "stdio.h"

int getP(char c){
    switch(c){
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    case '(':
        return 0;
    default:
        return -1;
    }
}

int main(){
    int i,st,pt;
    char s[1000],post[1000],sk[1000];
    printf("Enter infix statement: "); scanf(" %s", s);
    for(i = st = pt = 0; s[i]; i++){
         switch(s[i]){
            case ')':
                for(;sk[st-1] != '(';st--) post[pt++] = sk[st-1];
                st--;
                break;
            case '+': case '-': case '*': case '/':
                while(st != 0 && getP(s[i]) <= getP(sk[st-1])) post[pt++] = sk[st-- - 1];
            case '(':
                sk[st++] = s[i];
                break;
            default:
                post[pt++] = s[i];
         }
    }
    while(st > 0) post[pt++] = sk[st-- -1];
    post[pt++] = '\0';
    printf("Postfix : %s\n", post);

    for(i=st=0; post[i]; i++){
        switch(post[i]){
        case '+':
            sk[st-- -2] = sk[st-2]+sk[st-1];
            break;
        case '-':
            sk[st-- -2] = sk[st-2]-sk[st-1];
            break;
        case '*':
            sk[st-- -2] = sk[st-2]*sk[st-1];
            break;
        case '/':
            sk[st-- -2] = sk[st-2]/sk[st-1];
            break;
        default:
            sk[st++] = post[i]-'0';
        }
    }
    printf("Result is: %d\n",sk[0]);
}
