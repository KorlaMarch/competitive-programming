#include "stdio.h"

int n,i;
long long int inv;
int a[100005],t[100005];

void merge(int a[], int an, int b[], int bn){
    int i,j;
    for(i=j=0; i<an||j<bn;){
        if(i<an&&(j>=bn||a[i]<=b[j])){
            t[i+j] = a[i];
            i++;
        }else{
            t[i+j] = b[j];
            j++;
            inv += an-i;
        }
    }
}

void mergesort(int a[], int n){
    int i;
    if(n<=1) return;
    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    merge(a,n/2,a+n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",a+i);
    }
    mergesort(a,n);
    printf("%lld\n",inv);
}
