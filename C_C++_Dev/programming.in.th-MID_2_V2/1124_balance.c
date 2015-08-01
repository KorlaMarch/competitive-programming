#include "stdio.h"
int v[10] = {1,3,9,27,81,243,729,2187,6561,19683};
char s[10];
void findP(int d, int n){
    int i;
    if(n==10){
        if(d==0){
            for(i = 0; i < 10; i++) printf("%d ",-s[i]+1);
            printf("\n");
        }
        return;
    }else{
        for(i = -1; i <= 1; i++){
            s[n] = i;
            findP(d+v[n]*i,n+1);
        }
    }
}
int main(){
    int i;
    for(i = 9000; i < 10000; i++){
        printf("i:%d :",i);
        findP(i,0);
    }
}
