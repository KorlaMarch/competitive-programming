#include "stdio.h"

int cars[1000000];

int KSelection(int a[],int size,int k){
    int i = 1, j = size-1, t;
    int pivot;
    /*for(i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");*/
    pivot = a[0];


    while(i <= j){
        if(a[i] < pivot && a[j] >= pivot){
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
        if(a[i] >= pivot){
            i++;
        }
        if(a[j] < pivot){
            j--;
        }
    }

    t = a[0];
    a[0] = a[j];
    a[j] = t;
    if(j == k){
        return a[j];
    }else if(k > j){
        return KSelection(a+j+1,size-j-1, k-j-1);
    }else{
        return KSelection(a,j,k);
    }

}

int main(){
    int n, k, i;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &cars[i]);
    }

    printf("%d\n", KSelection(cars, n, k-1));
}
