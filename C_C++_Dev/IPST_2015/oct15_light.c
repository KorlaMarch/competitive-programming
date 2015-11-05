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

int a[100005],b[100005],x[100005];
int n,m,i,j,k,p,ov;
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d%d",a+i,b+i);
    }
    for(i = 0; i < m; i++){
        scanf("%d",x+i);
    }
    mergesort(a,n);
    mergesort(b,n);
    mergesort(x,m);
    for(p=i=j=k=ov=0;k<m;k++){
        for(;i<n&&a[i]<x[k];i++) ov++;
        for(;j<n&&b[j]<=x[k];j++) ov--;
        p = (p+ov)%2007;
    }
    printf("%d\n",p);
}
