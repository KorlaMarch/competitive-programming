#include "stdio.h"
int a[500000];
int t[500000];
void merge(int a[],int b[],int c[],int n,int n2){
    int i,j;
    for(i=j=0; i<n||j<n2;){
        if(i<n&&(j>=n2||a[i]<b[j])) c[i+j] = a[i++];
        else c[i+j] = b[j++];
    }
}
void msort(int a[], int n){
    int i;
    if(n<=1) return;
    msort(a,n/2);
    msort(a+n/2,n-n/2);
    merge(a,a+n/2,t,n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}

int main(){
    int n,i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    msort(a,n);
    for(i = 0; i < n; i++) printf("%d\n", a[i]);
}

