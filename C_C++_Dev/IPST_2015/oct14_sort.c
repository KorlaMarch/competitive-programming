#include "stdio.h"
int n;
int a[1000];
void bsort(int i, int n){
    int t;
    if(i>=n) return;
    if(a[i-1]>a[i]){
        t = a[i-1];
        a[i-1] = a[i];
        a[i] = t;
    }
    bsort(i+1,n);
}
void bbsort(int i){
    if(i<=1) return;
    bsort(1,i);
    bbsort(i-1);
}
void scanN(int i, int n){
    if(i>=n) return;
    scanf("%d", a+i);
    scanN(i+1,n);
}
void printN(int i, int n){
    if(i>=n) return;
    printf("%d\n", a[i]);
    printN(i+1,n);
}
int main(){
    scanf("%d",&n);
    scanN(0,n);
    bbsort(n);
    printN(0,n);
}
