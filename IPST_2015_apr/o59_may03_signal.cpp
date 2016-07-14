#include "stdio.h"
#include "algorithm"

int n,i,j,c,fc,mn;
int x[200],y[200];
int a[200][200];
std::pair<int,char> rd[23000];
int qs[23000];

int sq(int n){
    return n*n;
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(i=c=0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&a[i][j]);
            rd[c].first = sq(x[i]-x[j])+sq(y[i]-y[j]);
            rd[c++].second = a[i][j];
        }
    }
    std::sort(rd,rd+c);
    qs[c-1] = rd[c-1].second;
    for(i = c-2; i >= 0; i--){
        qs[i] = qs[i+1]+rd[i].second;
    }
    mn = qs[0];
    for(i = 0; i < c; i++){
        fc += !rd[i].second;
        //printf("%d : %d %d : %d %d\n",i,rd[i].first,rd[i].second,fc,qs[i+1]);
        if(i+1==n||rd[i].first!=rd[i+1].first){
            if(fc+qs[i+1]<mn) mn = fc+qs[i+1];
        }
    }
    printf("%d\n",mn);
}
