#include "stdio.h"

int n,s,i,j,k,maxS;
int h[2005];
int p[1005];
int dyn[2][20005];

int max(int a, int b){
    return a>b?a:b;
}

int main(){
    scanf("%d%d",&n,&s);
    for(i = 0; i < n; i++){
        scanf("%d",&h[i]);
        for(j = 1; j <= h[i]; j++){
            scanf("%d",&p[j]);
            p[j] += p[j-1];
        }
        for(j = 1; j <= s+1; j++){
            dyn[(i+1)%2][j] = 0;
            for(k = 0; k <= h[i]; k++){
                //printf("MX : %d\n",dyn[i%2][j-k-1]+p[k]);
                if(j-k-1>=i) dyn[(i+1)%2][j] = max(dyn[(i+1)%2][j],dyn[i%2][j-k-1]+p[k]);
            }
            //printf("%d %d : %d\n",i,j,dyn[(i+1)%2][j]);
            if(dyn[(i+1)%2][j]>maxS) maxS = dyn[(i+1)%2][j];
        }
    }
    printf("%d\n",maxS);
}
