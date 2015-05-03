#include "stdio.h"
int n,p=1,a,i,j,k;
int c[300001],in[300000],fi[300001];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    c[0] = 1000001;
    scanf("%d",&n);
    for(k=0; k<n; k++) scanf("%d", &in[k]);
    for(k=n-1; k>=0; k--){
        a = in[k];
        for(i=0,j=p-1;i<=j;){
            if(a>=c[(i+j)/2]) j = (i+j)/2-1;
            else i = (i+j)/2+1;
        }
        if(j+1>=p){
            c[j+1] = a;
            p++;
            for(i = 0; i < p; i++) fi[i] = c[i];
        }else{
            c[j+1] = max(c[j+1],a);
            if(j+1 == p-1) for(i = 0; i < p; i++) fi[i] = c[i];
        }
    }
    printf("%d\n", p-1);
    for(i=p-1;i>0;i--) printf("%d ", fi[i]);
}
