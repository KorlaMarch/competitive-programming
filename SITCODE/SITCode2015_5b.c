#include "stdio.h"
#include "math.h"
char s[32];

int isP(int n){
    int i,j;
    for(i = 0; n; i++){
        s[i] = n%10;
        n /= 10;
    }
    j = i-1;
    for(i = 0; i < j; i++,j--){
        if(s[i]!=s[j]) return 0;
    }
    return 1;
}

int isPr(int n){
    int i,li = (int)sqrt(n);
    for(i = 2; i <= li; i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int pp(int n){
    int i;
    for(i = n; ; i++){
        if(isP(i)&&isPr(i)) return i;
    }
}

int main(){
    int n,i,x;
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&x);
        printf("Case #%d\n%d\n",i,pp(x));
    }
}
