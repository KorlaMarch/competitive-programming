#include "stdio.h"
#include "set"
int n,k,i,j,x,mx,v;
int ore[1001][1001],mv[1001][1001];
int maxC[3][1001][1001];
std::multiset<int> mxT;

void calMaxC(int m){
    mxT.clear();
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d",&ore[i][j]);
            ore[i][j] += ore[i-1][j]+ore[i][j-1]-ore[i-1][j-1];
        }
    }
    for(i = 1; i+k-1 <= n; i++){
        for(j = 1; j+k-1 <= n; j++){
            mv[i][j] = ore[i+k-1][j+k-1]-ore[i+k-1][j-1]-ore[i-1][j+k-1]+ore[i-1][j-1];
        }
    }
    for(i = 1; i <= k; i++){
        for(j = 1; j <= k; j++){
            mxT.insert(mv[i][j]);
        }
    }
    maxC[m][k][k] = *mxT.rbegin();
    for(j = k; j+k-1 <= n; j++){
        for(x = 1; x <= k; x++) mxT.erase(mv[x][j-k]);
        for(x = 1; x <= k; x++) mxT.insert(mv[x][j]);
        maxC[m][k][j] = *mxT.rbegin();
    }

}

int main(){
    scanf("%d%d",&n,&k);
    calMaxC(0);
    calMaxC(1);
    calMaxC(2);
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            v = maxC[0][i][j]+maxC[1][i][j]+maxC[2][i][j];
            if(v>mx) mx = v;
        }
    }
    printf("%d\n",mx);
}
