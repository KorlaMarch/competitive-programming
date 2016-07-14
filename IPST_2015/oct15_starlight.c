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
int x[5005],y[5005];
int s,n,i,j,mxx,mxy;
int main(){
    scanf("%d%d",&s,&n);
    for(i = 0;i < n; i++){
        scanf("%d%d",x+i,y+i);
    }
    mergesort(x,n);
    mergesort(y,n);
    mxx = x[0]*2;
    mxy = y[0]*2;
    for(i = 1; i < n; i++){
        if(x[i]-x[i-1]>mxx) mxx = x[i]-x[i-1];
        if(y[i]-y[i-1]>mxy) mxy = y[i]-y[i-1];
    }
    if((s-x[i-1])*2>mxx) mxx = (s-x[i-1])*2;
    if((s-y[i-1])*2>mxy) mxy = (s-y[i-1])*2;
    if(mxx<mxy) printf("%.3f\n",mxx/2.0);
    else printf("%.3f\n",mxy/2.0);
}
