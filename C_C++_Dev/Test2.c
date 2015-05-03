#include "stdio.h"

int putNum(char a[],int num, int sp){
    int len,i,j;
    //find len
    for(i = num, len = 0; i > 0; i /= 10,len++);
    for(i = sp+len-1,j = num; i >= sp; i--,j /= 10){
        a[i] = j%10;
    }
    return sp+len;
}

int main(){
    int n,i,j;
    char num[10000];
    scanf("%d", &n);
    for(i = 1,j = 0; j <= n; i++){
        j = putNum(num, i, j);
    }
    printf("%d\n", num[n-1]);
}
