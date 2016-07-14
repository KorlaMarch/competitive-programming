#include "stdio.h"

//Age of quick sum :P
int n,m,k,i,j,f,sum,ms;
int v[1001],h[1000];
char c,ls[1000];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < n; i++){
        for(j=0,ms=k; j < m; j++){
            scanf(" %c", &c);
            if(c=='1'){
                sum++;
            }else{
                v[i]++;
            }
            sum -= ls[f];
            ls[f] = c-'0';
            f = (f+1)%k;
            if(sum<ms&&j+1>=k) ms = sum;
        }
        h[i] = ms;
        v[i+1] = v[i];
    }
    for(i=n-1;i>=0;i--){
        if(h[i]<=v[n-1]-v[i]) break;
    }
    printf("%d\n",i+1);
}
