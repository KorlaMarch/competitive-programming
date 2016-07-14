#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
int n,p,i,j,x,y,t;
int chem[100000][10];
int slist[100000];
int tar[11];
bool cmp(int a, int b){
    int i;
    for(i = 0; i < p; i++){
        if(chem[a][i]<chem[b][i]) return true;
        else if(chem[b][i]<chem[a][i]) return false;
    }
    return false;
}
int bs(int i, int j, int d, int v){
    int m;
    while(i<=j){
        m = (i+j)/2;
        if(v>chem[slist[m]][d]){
            i = m+1;
        }else{
            j = m-1;
        }
    }
    return j;
}
int main(){
    scanf("%d%d",&n,&p);
    for(i = 0; i < n; i++){
        slist[i] = i;
        for(j = 0; j < p; j++){
            scanf("%d", &chem[i][j]);
        }
    }
    std::sort(slist,slist+n,cmp);
    for(i = 0; i < p; i++){
        scanf("%d", &tar[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            if(chem[i][j]!=tar[j]) break;
        }
        if(j==p) break;
    }
    if(i!=n){
        printf("%d\n", i+1);
    }else{
        for(i = 0; i < n; i++){
            for(j=x=0,y=n-1; j < p; j++){
                t = bs(x,y,j,tar[j]-chem[slist[i]][j]);
                y = bs(x,y,j,tar[j]-chem[slist[i]][j]+1);
                x = t+1;
                if(y<0||x>y) break;
            }
            if(j==p&&i!=y){
                if(slist[i]<slist[y]) printf("%d %d\n", slist[i]+1,slist[y]+1);
                else printf("%d %d\n", slist[y]+1,slist[i]+1);
                return 0;
            }
        }
        printf("NO\n");
    }
}
