#include "stdio.h"
int n,k,i,j;
int ore[1000][1000];

int solve(){
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &ore[i][j]);
            if(i&&j) ore[i][j] += ore[i-1][j]+ore[i][j-1]-ore[i-1][j-1];
            else if(i) ore[i][j] += ore[i-1][j];
            else if(j) ore[i][j] += ore[i][j-1];
        }
    }for(i )
}

int main(){
    scanf("%d %d",&n, &k);
    printf("%d\n",solve()+solve()+solve());
}
