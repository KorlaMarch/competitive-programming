#include "stdio.h"
typedef struct{
    double w,v,r;
}node;
node a[100001];
node t[100001];
void merge(node a[],node b[],node c[],int n,int n2){
    int i,j;
    for(i=j=0; i<n||j<n2;){
        if(i<n&&(j>=n2||a[i].r>b[j].r)) c[i+j] = a[i++];
        else c[i+j] = b[j++];
    }
}
void msort(node a[], int n){
    int i;
    if(n<=1) return;
    msort(a,n/2);
    msort(a+n/2,n-n/2);
    merge(a,a+n/2,t,n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}
int main(){
    int n,i;
    double W,w,v;
    scanf(" %lf %d",&W, &n);
    for(i = 0; i < n; i++) scanf(" %lf", &a[i].v);
    for(i = 0; i < n; i++){
        scanf(" %lf", &a[i].w);
        a[i].r = a[i].v/a[i].w;
    }
    msort(a,n);
    for(i=v=w=0; w+a[i].w<=W&&i<n;i++){
        v += a[i].v;
        w += a[i].w;
    }
    if(i<n) v += a[i].r*(W-w);
    printf("%.4lf",v);
}
