#include "stdio.h"
int t[100000];
void merge(int a[], int b[], int n1, int n2){
    int i,j;
    for(i=j=0; i<n1||j<n2;){
        if(i<n1&&(j>=n2||a[i]<b[j])) t[i+j] = a[i++];
        else t[i+j] = b[j++];
    }
}
void msort(int a[], int n){
    int i;
    if(n<=1) return;
    msort(a,n/2);
    msort(a+n/2,n-n/2);
    merge(a,a+n/2,n/2,n-n/2);
    for(i=0;i<n;i++) a[i] = t[i];
}
int main(){
    int a[100000];
    int n,m,i,j,k,q,r;
    scanf("%d%d", &n,&m);
    for(i = 0; i < n; i++) scanf("%d",&a[i]);
    msort(a,n);
    for(k = 0; k < m; k++){
        scanf("%d", &q);
        for(i=0,j=n-1,r=1; i<j&&r;){
            if(a[i]+a[j] == q) r = 0;
            else if(a[i]+a[j]>q) j--;
            else i++;
        }
        printf("%s\n",r?"NO":"YES");
    }
}
