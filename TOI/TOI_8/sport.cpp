#include "stdio.h"

char arr[300];
int k;

void printAll(int n, int aptr, int a, int b){
    int i;
    if(n >= k*2-1 || a >= k || b >= k){
        for(i = 0; i < aptr; i++){
            printf("%c ", arr[i]);
        }
        printf("\n");
        return;
    }
    arr[aptr] = 'W';
    printAll(n+1,aptr+1,a+1,b);
    arr[aptr] = 'L';
    printAll(n+1,aptr+1,a,b+1);
}

int main(){
    int a,b;
    scanf("%d%d%d", &k, &a, &b);
    printAll(0,0,a,b);
}
