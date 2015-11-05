#include "stdio.h"
#include "algorithm"
#include "time.h"
#include "stdlib.h"

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void quicksort(int a[], int n){
    int i=1,j=n-1,pivot = a[0];
    if(n<=1) return;
    while(i<=j){
        if(a[i]<=pivot){
            i++;
        }else if(a[j]>pivot){
            j--;
        }else{
            swap(a+i,a+j);
            i++;
            j--;
        }
    }
    swap(a,a+j);
    quicksort(a,j);
    quicksort(a+j+1,n-j-1);
}

int main(){
    int n,t,i,j;
    int a[100000],b[100000];
    srand(time(NULL));
    scanf("%d %d",&n,&t);
    for(i = 0; i < t; i++){
        for(j = 0; j < n; j++){
            a[j] = rand()%100000;
            b[j] = a[j];
        }
        std::sort(b,b+n);
        quicksort(a,n);
        for(j = 0; j < n; j++){
            if(a[j]!=b[j]) break;
        }
        if(j!=n){
            printf("Wrong\n");
            return 0;
        }
    }
    printf("Right\n");
}
