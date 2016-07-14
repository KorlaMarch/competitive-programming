#include "stdio.h"
typedef struct{
    int x,y;
}pos;
pos t[100005];
void merge(pos a[], int an, pos b[], int bn){
    int i,j;
    for(i=j=0;i<an||j<bn;){
        if(i<an&&(j>=bn||(a[i].x==b[j].x?(a[i].y<b[j].y):(a[i].x<b[j].x)))){
            t[i+j] = a[i];
            i++;
        }else{
            t[i+j] = b[j];
            j++;
        }
    }
}
void mergesort(pos a[],int n){
    if(n<=1) return;
    int i;
    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    merge(a,n/2,a+n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}

int main(){
    int n,i;
    pos x[100005];
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x[i].x,&x[i].y);
    }
    mergesort(x,n);
    for(i = 0; i < n; i++){
        printf("%d %d\n",x[i].x,x[i].y);
    }
}
