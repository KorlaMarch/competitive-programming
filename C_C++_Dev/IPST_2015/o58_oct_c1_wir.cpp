#include "stdio.h"

int n,m,i,j,k,li,bk;
int h[100005];

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&h[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d",&k);
        bk = 0;
        for(j = 1,li = h[0]; j < n; j++){
            if(h[j]-li>k){
                bk++;
            }else li = h[j];
        }
        printf("%d\n",bk);
    }
}
