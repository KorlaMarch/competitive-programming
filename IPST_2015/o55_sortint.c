#include "stdio.h"
int t[100005];
void merge(int a[], int an, int b[], int bn){
    int i,j;
    for(i=j=0;i<an||j<bn;){
        if(i<an&&(j>=bn||a[i]<b[j])){
            t[i+j] = a[i];
            i++;
        }else{
            t[i+j] = b[j];
            j++;
        }
    }
}
void mergesort(int a[],int n){
    if(n<=1) return;
    int i;
    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    merge(a,n/2,a+n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}

int main(){
    int n,i;
    int x[100005];
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",x+i);
    }
    mergesort(x,n);
    for(i = 0; i < n; i++){
        printf("%d\n",x[i]);
    }
}
