#include "stdio.h"
#include "algorithm"
#include "time.h"
#include "stdlib.h"

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int t[10000];
void mergeA(int a[], int na, int b[], int nb){
    int i,j;
    for(i=j=0;i<na||j<nb;){
        if(j<nb&&(i>=na||b[j]<a[i])){
            t[i+j] = b[j];
            j++;
        }else{
            t[i+j] = a[i];
            i++;
        }
    }
}
void mergesort(int a[], int n){
    if(n<=1) return;
    int i;
    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    mergeA(a,n/2,a+n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
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
        mergesort(a,n);
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
