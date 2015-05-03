#include "stdio.h"
#include "math.h"
int i,j,k,n;
char s[16];
int isP(int n){
    int i,m = (int)sqrt(n);
    for(i = 2; i <= m; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}
int isPalin(){
    for(k = 0; k<=j-k-1;k++){
        if(s[k]!=s[j-k-1]) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(i = n; ; i++){
        for(j = 0,k = i; k != 0; k /= 10,j++) s[j] = k%10;
        if(isPalin() && isP(i)){
            printf("%d\n",i);
            return 0;
        }
    }
}
