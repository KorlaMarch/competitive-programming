#include "stdio.h"
#include "stdio.h"
#include "math.h"

void marge(int m[], int len1, int n[], int len2, int a[]){
    int i = 0,j = 0,k = 0, x = 0;
    while(i < len1 && j < len2){
        if(m[i] < n[j]){
            a[k] = m[i];
            i++;
        }else{
            a[k] = n[j];
            j++;
        }
        k++;
    }

    if(i < len1){
        while(i < len1){
            a[k] = m[i];
            i++;
            k++;
        }
    }else{
        while(j < len2){
            a[k] = n[j];
            j++;
            k++;
        }
    }
}

void copyArray(int* a, int* b, int start, int end){
    int i,j;
    for(i = 0, j = start; j <= end; i++,j++){
        a[i] = b[j];
    }
}

void margeSort(int* N, int len){
    int i;
    int* a;
    int* b;
    if(len == 1){
        return;
    }
    a = (int*)malloc(sizeof(int)*(len/2)+1);
    b = (int*)malloc(sizeof(int)*(len/2)+1);
    copyArray(a, N, 0, len/2-1);
    copyArray(b, N, len/2, len-1);
    margeSort(a, len/2);
    margeSort(b, (int)ceil(len/2.0));
    marge(a, len/2, b, (int)ceil(len/2.0), N);
    free(a);
    free(b);
}

int main(){
    int a[] = {5,1,2,9,11,8,5,45,8};
    int i;
    margeSort(a, sizeof(a)/sizeof(int));
    for(i = 0; i <  sizeof(a)/sizeof(int); i++){
        printf("%d ", a[i]);
    }
}
