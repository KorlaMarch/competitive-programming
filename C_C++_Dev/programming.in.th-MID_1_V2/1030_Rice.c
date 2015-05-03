#include "stdio.h"

typedef struct{
    double p,q;
}rice;

rice r[100000], t[100000];

void merge(rice a[], rice b[], int na, int nb){
    int i,j;
    for(i=j=0; i<na||j<nb;){
        if(i<na&&(j>=nb||a[i].p/a[i].q<b[j].p/b[j].q)) t[i+j] = a[i++];
        else t[i+j] = b[j++];
    }
}

void msort(rice r[], int n){
    int i;
    if(n<=1) return;
    msort(r,n/2);
    msort(r+n/2,n-n/2);
    merge(r,r+n/2,n/2,n-n/2);
    for(i = 0; i < n; i++) r[i] = t[i];
}

int main(){
    int k,i,j,m;
    double b,s;
    scanf("%d",&k);
    for(i = 0; i < k; i++){
        scanf("%lf%lf",&r[i].p,&r[i].q);
    }
    msort(r,k);
    scanf("%d",&m);
    for(i = j = 0; i < m; i++){
        scanf("%lf",&b);
        for(s = 0.0; b>0;){
            if(r[j].q <= b){
                b -= r[j].q;
                s += r[j].p;
                j++;
            }else{
                s += r[j].p/r[j].q*b;
                r[j].p -= r[j].p/r[j].q*b;
                r[j].q -= b;
                b=0;
            }
        }
        printf("%.3lf\n", s);
    }
}
