#include "stdio.h"
int n,m,top;
long long s;
int ti[100];
int a[100000];

//sort
int tmp[100000];
void merge(int a[],int b[], int n1, int n2){
    int i,j;
    for(i=j=0; i<n1||j<n2;){
        if(i<n1&&(j>=n2||a[i]<b[j])) tmp[i+j] = a[i++];
        else tmp[i+j] = b[j++];
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
    int i,x;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++) scanf("%d", &a[i]);
    msort(a,m);
    for(i = 0; i < m; i++){
        ti[i%n] += a[i];
        s += ti[i%n];
    }
    printf("%.3lf\n",((double)s)/m);
    return 0;
}
