#include "stdio.h"
#include "stdlib.h"

long long swapCount;

void marge(int a[], int sa, int b[], int sb, int tar[]){
    int i = 0,j = 0,k = 0;
    while(i < sa || j < sb){
        if(j == sb || (i != sa && a[i] < b[j])){
            tar[k] = a[i];
            i++;
        }else{
            tar[k] = b[j];
            j++;
            swapCount += sa-i;
        }
        k++;
    }
}

void margesort(int a[], int n){
    int* temp;
    int i;
    if(n <= 1){
        return;
    }
    margesort(a, n/2);
    margesort(a+n/2, n-n/2);
    temp = (int*)malloc(sizeof(int)*n/2);
    for(i = 0; i < n/2; i++){
        temp[i] = a[i];
    }
    marge(temp, n/2, a+n/2, n-n/2, a);
    free(temp);
}

int main(){
    int i,n;
    //int a[10] = {1,3,6,2,60,10,50,40,30};
    int a[100000];
    swapCount = 0;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    margesort(a, n);
    printf("%lld", swapCount);
}
