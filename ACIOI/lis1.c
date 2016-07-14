#include "stdio.h"
int n,p=1,a,i,j,k;
int c[5001];
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    c[0] = -100001;
    scanf("%d",&n);
    for(k=0; k<n; k++){
        scanf("%d",&a);
        for(i=0,j=p-1;i<=j;){
            if(a<=c[(i+j)/2]) j = (i+j)/2-1;
            else i = (i+j)/2+1;
        }
        if(j+1>=p){
            c[j+1] = a;
            p++;
        }else c[j+1] = min(c[j+1],a);
    }
    printf("%d\n", p-1);
}
