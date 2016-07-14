#include "stdio.h"
#include "algorithm"
int n,q,i,j,a,mx,mxP;
char c;
int cash[20][15000],xi[20];
int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i < n; i++){
        scanf("%d",xi+i);
        for(j = 0; j < xi[i]; j++){
            scanf("%d",&cash[i][j]);
        }
        std::sort(cash[i],cash[i]+xi[i]);
    }
    for(;q>0;q--){
        scanf(" %c %d",&c,&a);
        if(c=='0'){
            a--;
            for(i = 0,xi[a]--; i < xi[a]; i++) cash[a][i] = cash[a][i+1];
        }else{
            mx = std::lower_bound(cash[0],cash[0]+xi[0],a)-cash[0];
            mxP = 0;
            for(i = 1; i < n; i++){
                j = std::lower_bound(cash[i],cash[i]+xi[i],a)-cash[i];
                if(j<mx){
                    mx = j;
                    mxP = i;
                }
            }
            for(i=xi[mxP]++;i>mx; i--) cash[mxP][i] = cash[mxP][i-1];
            cash[mxP][mx] = a;
            printf("%d\n",mxP+1);
        }
    }
}
