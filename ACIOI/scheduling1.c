#include "stdio.h"
typedef struct{
    int p,q;
}pro;
void merge(pro a[],pro b[],pro c[],int n,int n2){
    int i,j;
    for(i=j=0; i<n||j<n2; ){
        if(i<n&&(j>=n2||a[i].p<b[j].p)) c[i+j]=a[i++];
        else c[i+j]=b[j++];
    }
}
pro t[100001];
pro ps[100001];
void msort(pro a[],int n){
    int i;
    if(n <= 1) return;
    msort(a,n/2);
    msort(a+n/2,n-n/2);
    merge(a,a+n/2,t,n/2,n-n/2);
    for(i=0;i<n;i++) a[i] = t[i];
}
void ave(){
    int n,m,i,t,s;
    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d%d", &ps[i].p, &ps[i].q);
    scanf("%d",&m);
    msort(ps,n);
    for(i=s=t=0; i<n; i++){
        if(t>ps[i].p){
            s += t-ps[i].p;
            t += ps[i].q;
        }else{
            t = ps[i].p+ps[i].q;
        }
    }
    printf("%.*lf\n",m,((double)s)/n);
}
int main(){
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++) ave();
}
