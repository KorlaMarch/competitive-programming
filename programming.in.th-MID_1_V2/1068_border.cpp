#include "stdio.h"
#include "queue"
#include "vector"
int bor[201][101];
int main(){
    int n,k,i,j,x,y,sum,m;
    std::priority_queue<int,std::vector<int>,std::greater<int> > q;
    scanf("%d%d", &n, &k);
    x = n*2+1;
    for(i = 0; i < x; i++){
        y = i%2?n+1:n;
        for(j = 0; j < y; j++){
            scanf("%d", &bor[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
             q.push(3*bor[i*2][j]+5*bor[i*2+1][j]-3*bor[i*2+2][j]-5*bor[i*2+1][j+1]);
        }
    }
    for(i = sum = 0; i < k; i++){
        sum += q.top();
        q.pop();
    }
    printf("%d\n",sum);
}
