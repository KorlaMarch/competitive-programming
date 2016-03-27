#include "stdio.h"
#include "algorithm"
#include "map"

int n,h,l,i,j,k,v,maxV;
int x[100005],y[100005];
std::map<int,int> co;

int main(){
    scanf("%d%d%d",&n,&h,&l);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(i = 0; i < n && x[i]-x[0]<=h; i++){
        for(k = 0; k <= l && y[i]-k > 0; k++){
            v = ++co[y[i]-k];
            if(v > maxV) maxV = v;
        }
    }
    for(j = 0; i < n; i++){
        while(x[i]-x[j]>h){
            for(k = 0; k <= l&& y[j]-k > 0; k++){
                co[y[j]-k]--;
            }
            j++;
        }
        for(k = 0; k <= l&& y[i]-k > 0; k++){
            v = ++co[y[i]-k];
            if(v > maxV){
                //printf("%d %d %d\n",i,j,y[i]+k);
                maxV = v;
            }
        }
    }
    printf("%d\n",maxV);
}
