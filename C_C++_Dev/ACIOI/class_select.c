#include "stdio.h"
typedef struct{
    int s,e;
}sub;
sub a[100000];
sub t[100000];
void merge(sub a[],sub b[],sub c[],int n,int n2){
    int i,j;
    for(i=j=0; i<n||j<n2;){
        if(i<n&&(j>=n2||a[i].e<b[j].e)) c[i+j] = a[i++];
        else c[i+j] = b[j++];
    }
}
void msort(sub a[], int n){
    int i;
    if(n<=1) return;
    msort(a,n/2);
    msort(a+n/2,n-n/2);
    merge(a,a+n/2,t,n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}
int main(){
    int n,i,c,t;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i].s);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &a[i].e);
    }
    msort(a,n);
    for(i=t=c=0; i < n; i++){
        if(t <= a[i].s){
            c++;
            t = a[i].e;
        }
    }
    printf("%d\n", c);
}
