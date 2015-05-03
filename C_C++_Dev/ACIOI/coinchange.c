#include "stdio.h"
int n,q,i,j,k,x,m;
int ty[100],ch[500001];
int main(){
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d",&ty[i]);
    scanf("%d",&q);
    for(j=0,i=1;j<q;j++){
        scanf("%d",&x);
        for(;i<=x;i++){
            for(k=0,m=i;k<n;k++){
                if(i-ty[k]>=0&&ch[i-ty[k]]+1<m) m=ch[i-ty[k]]+1;
            }
            ch[i] = m;
        }
        printf("%d\n",ch[x]);
    }
}
