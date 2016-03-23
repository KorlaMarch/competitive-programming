#include "stdio.h"
#include "string.h"
int m,n,l,i,j,k,a,b,c,t,d,e,mn;
char adjM[30][30];
char isV[30];

int getMn(int d, int e){
    int i,j,mn=-2,v;
    if(d==e){
        return 0;
    }
    isV[d] = 1;
    for(i = 0; i < n; i++){
        if(adjM[d][i]&&!isV[i]){
            v = getMn(i,e);
            if(v!=-1&&(mn==-2||v<mn)){
                mn = v;
            }
        }
    }
    isV[d] = 0;
    return mn+1;
}

int main(){
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; i++){
        scanf("%d",&l);
        for(j = 0; j < l; j++){
            scanf("%d%d",&a,&b);
            for(k = 0; k < b; k++){
                scanf("%d",&c);
                adjM[a][c] = 1;
            }
        }
    }
    scanf("%d",&t);
    for(i = 0; i < t; i++){
        scanf("%d%d",&d,&e);
        memset(isV,0,sizeof(isV));
        mn = getMn(d,e);
        if(mn==-1) printf("no\n");
        else printf("%d\n",mn-1);
    }
}
