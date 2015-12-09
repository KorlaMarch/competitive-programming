#include "stdio.h"

int n;
char s[100001];

int findLS(){
    int i,t;
    t = 1;
    for(i = 1; i < n; i++){
        if(s[i-1]!=s[i]) t++;
    }
    return t;
}
int min(int a, int b){
    return a<b?a:b;
}
int getINC(){
    int i,j,v;
    for(i=1,v=0; i < n; i++){
        if(s[i]==s[i-1]) v++;
    }
    return min(2,v);
}

int main(){
    scanf("%d %s",&n,s);
    printf("%d\n",findLS()+getINC());
}
