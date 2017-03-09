#include "stdio.h"

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void qsort(int a[], int n){
    int p,i,j;
    if(n <= 1){
        return;
    }
    p = a[n/2];
    swap(a, a+n/2);

}

int main(){

}
