#include "stdio.h"

void bbsort(int a[], int n){
    int i,j,isSorted = 0,t;
    for(i = 0; !isSorted; i++){
        isSorted = 1;
        for(j = 1; j < n-i; j++){
            if(a[j-1] > a[j]){
                //swap
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
                isSorted = 0;
            }
        }
    }
}

int main(){
    int n[10];
    int i;
    for(i = 0; i < 10; i++){
        scanf("%d", &n[i]);
    }
    bbsort(n,10);
    for(i = 0; i < 10; i++){
        printf("%d ", n[i]);
    }
}
