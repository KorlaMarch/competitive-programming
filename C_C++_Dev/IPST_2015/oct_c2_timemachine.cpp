#include "stdio.h"
#include "math.h"
int n,m,k,i,j,minT;
int xi[12],yi[12],p[12],cost[12][12];
char isV[12];
void findMinT(int x, int y, int t, int d){
    int i;
    //printf("%d %d %d\n",x,y,t);
    if(d==k){
        if(t<minT) minT = t;
        return;
    }
    if(!x&&!y){
        for(i = 0; i <= k; i++){
            isV[i] = 1;
            findMinT(xi[i],yi[i],(int)ceil(sqrt(xi[i]*xi[i]+yi[i]*yi[i]))-p[i],i);
            isV[i] = 0;
        }
    }else for(i = 0; i <= k; i++){
        if(!isV[i]){
            isV[i] = 1;
            findMinT(xi[i],yi[i],t+cost[d][i]-p[i],i);
            isV[i] = 0;
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    xi[k] = n-1,yi[k] = m-1;
    for(i = 0; i < k; i++){
        scanf("%d%d%d",xi+i,yi+i,p+i);
    }
    for(i = 0; i <= k; i++){
        for(j = 0; j <= k; j++){
            cost[i][j] = (int)ceil(sqrt((xi[i]-xi[j])*(xi[i]-xi[j])+(yi[i]-yi[j])*(yi[i]-yi[j])));
        }
    }
    minT = 100000000;
    findMinT(0,0,0,0);
    printf("%d\n",minT);
}
