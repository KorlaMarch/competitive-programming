#include "stdio.h"
int n,i,j,k,lim,len;
char exp[128];
int in[65];

int getP(char c){
    switch(c){
    case '+':
        return 3;
    case '*':
        return 2;
    case '^':
        return 1;
    default:
        return 0;
    }
}

void printOP(int n){
    if(n<0){
        printf("p");
        return;
    }
    printf("op(%d,", in[n]);
    printOP(n-1);
    printf(")");
}

void printEX(char s[], int n, int d){
    int i,pi,j;
    char m;
    if(d>=lim){
        for(i = 0; i < n; i++) putchar(s[i]);
        putchar('\n');
        return;
    }else if(s[0]=='('&&s[n-1]==')'){
        for(pi=0,j=i=1; i < n-1 && j; i++){
            if(s[i]=='(') pi++;
            else if(s[i]==')') pi--;
            if(pi<0) j = 0;
        }
        if(j&&!pi){
            if(in[d]!=1){
                printf("null\n");
            }else{
                printEX(s+1,n-2,d+1);
            }
            return;
        }
    }
    for(i=m=pi=0; i < n; i++){
        if(s[i]=='(') pi++;
        else if(s[i]==')') pi--;
        else if(!pi&&getP(s[i])>getP(m)) m = s[i];
    }
    i = -1,j = 1;
    if(in[d] > 1){
        for(i=pi=0,j = 1;i < n; i++){
            if(s[i]=='(') pi++;
            else if(s[i]==')') pi--;
            else if(!pi&&s[i]==m){
                j++;
                if(j == in[d]){
                    break;
                }
            }
        }
    }
    if(i == n) printf("null\n");
    else{
        for(j = i+1,pi=0; j<n&&(s[j]!=m||pi); j++){
            if(s[j]=='(') pi++;
            else if(s[j]==')') pi--;
        }
        printEX(s+i+1,j-i-1,d+1);
    }
}

int main(){
    scanf(" %s%d", exp, &n);
    for(i = 0; exp[i]; i++);
    len = i;
    for(i = 0; i < n; i++){
        for(j=0,scanf("%d",&k); k != 0; scanf("%d",&k),j++){
            in[j] = k;
        }
        lim = j;
        printOP(j-1);
        printf("=");
        printEX(exp,len,0);
    }
}
