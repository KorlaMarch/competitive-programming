#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int a[],int n){
    int i,j,k,pivot;
    if(n <= 1) return;
    swap(a, a+n/2);
    pivot = a[0];
    i = 1, j = n-1;
    while(i <= j){
        if(a[i] >= pivot && a[j] < pivot){
            swap(a+i, a+j);
            i++;
            j--;
        }
        if(a[i] < pivot) i++;
        if(a[j] >= pivot) j--;
    }
    swap(a,a+j);
    quicksort(a,j);
    quicksort(a+j+1, n-j-1);
}

int main(){
    int a[1000];
    int i,isSort;
    srand(time(NULL));
    printf("Before sorting:\n");
    for(i = 0; i < 1000; i++){
        a[i] = rand()%1000;
        printf("%d ", a[i]);
        //scanf("%d", &a[i]);
    }
    quicksort(a,1000);
    printf("\n\nAfter sorting:\n");
    for(i = 0,isSort = 1; i < 1000; i++){
        printf("%d ", a[i]);
        if(i > 0 && a[i-1] > a[i]){
            isSort = 0;
        }
    }
    printf("\n\nisSorted : %d", isSort);
}
