#include "stdio.h"

int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}

int main(){
    char c;
    int n,s,e,w,k,ms;
    n=s=e=w=0;
    while((c = getchar())!='\n'){
        switch(c){
            case 'N': n++; break;
            case 'S': s++; break;
            case 'E': e++; break;
            case 'W': w++; break;
        }
    }
    scanf("%d",&k);
    ms = min(n,s)+min(e,w);
    e = max(n,s)+max(e,w);
    if(k<=ms){
        printf("%d\n",(e-ms+k)*2);
    }else{
        printf("%d\n",(e-k+ms)*2);
    }
}
