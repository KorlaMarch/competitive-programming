#include "stdio.h"
char adj[100][100];
char color[100];
char maxC[100];
int n,m,k,a,b,i,j,x,max;

void colorG(int d, int c){
    int i,canP;
    if(d>=n){
        if(c > max){
            max = c;
            for(i = 0; i < n; i++) maxC[i] = color[i];
        }
        return;
    }
    for(i = 0, canP = 1; i < n && canP; i++){
        if(adj[d][i]&&color[i]==1) canP = 0;
    }
    if(canP){
        color[d] = 1;
        colorG(d+1,c+1);
    }

    color[d] = 0;
    colorG(d+1,c);
}

int main(){
    scanf("%d",&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&n,&k);
        for(j = 0; j < n; j++)
            for(x = 0; x < n; x++)
                adj[j][x] = 0;
        for(j = 0; j < n; j++) color[j] = 0;
        for(j = 0; j < k; j++){
            scanf("%d%d",&a,&b);
            adj[a-1][b-1] = 1;
            adj[b-1][a-1] = 1;
        }
        max = 0;
        colorG(0,0);
        printf("%d\n",max);
        for(j = 0; j < n; j++){
            if(maxC[j])
            printf("%d ",j+1);
        }
    }
}
