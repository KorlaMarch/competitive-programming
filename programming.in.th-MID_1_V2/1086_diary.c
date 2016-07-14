#include "stdio.h"

int n,k,a,i,j,x,p,c,mx,mxp;
int day[10010];

int main(){
    scanf("%d%d%d",&n,&k,&a);
    for(i=0,p=1; i < n; i++){
        scanf("%d",&x);
        for(j = 0; j < x; j++) day[p++] = i;
    }
    for(i = 1; i < p; i++){
        for(j=c=0,x=-1; j < k&&i+a*j < p; j++){
            if(day[i+a*j]!=x){
                x = day[i+a*j];
                c++;
            }
        }
        if(j!=k) break;
        if(c>mx){
            mxp = i;
            mx = c;
        }
    }
    printf("%d %d\n",mxp,mx);
}
