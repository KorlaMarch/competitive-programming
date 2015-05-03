#include "stdio.h"

int main(){
    int i,d,t;
    char s[201];
    scanf(" %s", s);
    for(i=d=t=0; s[i]; i++){
        if(s[i]=='('){
            d++;
        }else{
            if(d) d--;
            else t++;
        }
    }
    printf("%d\n",d+t);
}
