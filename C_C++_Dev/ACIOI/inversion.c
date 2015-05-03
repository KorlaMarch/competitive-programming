#include "stdio.h"

int n,co;
int a[100000];
int tmp[100000];
void merge(int a[],int b[], int n1, int n2){
    int i,j;
    for(i=j=0; i<n1||j<n2;){
        if(i<n1&&(j>=n2||a[i]<=b[j])) tmp[i+j] = a[i++];
        else{
            co += n1-i;
            tmp[i+j] = b[j++];
        }
    }
}
void msort(int a[], int n){
    int i;
    if(n<=1) return;
    msort(a,n/2);
    msort(a+n/2, n-n/2);
    merge(a,a+n/2,n/2,n-n/2);
    for(i=0; i<n; i++) a[i] = tmp[i];
}

int main(){
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    msort(a,n);
    printf("%d\n",co);
}
