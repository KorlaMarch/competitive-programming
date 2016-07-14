#include "stdio.h"
#include "algorithm"

int n,i,j,zc,lm,c,sm;
int x[1005],y[1005];
double m[1005];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(i = 0; i < n; i++){
        for(j = i+1,lm=zc=0; j < n; j++){
            if(x[j]-x[i]==0) zc++;
            else m[lm++] = (y[j]-y[i])/(double)(x[j]-x[i]);
        }
        std::sort(m,m+lm);
        c += zc*(zc-1)/2;
        for(j = 1,sm = 1; j < lm; j++){
            if(m[j]==m[j-1]){
                sm++;
            }else{
                c += sm*(sm-1)/2;
                sm = 1;
            }
        }
        c += sm*(sm-1)/2;
    }
    printf("%d\n",n*(n-1)*(n-2)/6-c);
}
