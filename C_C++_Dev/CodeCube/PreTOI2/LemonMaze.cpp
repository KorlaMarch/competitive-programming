#include "stdio.h"
#include "queue"
typedef struct{
    int x,y,t;
}node;
node gn(int x, int y, int t){
    node tp;
    tp.x = x;
    tp.y = y;
    tp.t = t;
    return tp;
}
int n,m,i,j,c,in;
char mz[300][301];
char block[4][300][300];
char isV[4][300][300];
node t;
std::queue<node> qu;

void fb(int in, int i, int j, int dx, int dy){
    for(;i<n&&j<m&&i>=0&&j>=0&&mz[i][j]=='.';i+=dx,j+=dy){
        block[in][i][j] = 1;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf(" %s",mz[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(mz[i][j]=='#'){
                block[0][i][j] = block[1][i][j] = block[2][i][j] = block[3][i][j] = 1;
            }else if(mz[i][j] == 'S'){
                t.x = i;
                t.y = j;
                t.t = 0;
                qu.push(t);
                isV[0][i][j] = 1;
            }else if(mz[i][j] != 'E' && mz[i][j] != '.'){
                switch(mz[i][j]){
                case '|': c = 0; break;
                case '/': c = 1; break;
                case '-': c = 2; break;
                case '\\': c = 3; break;
                }
                block[0][i][j] = block[1][i][j] = block[2][i][j] = block[3][i][j] = 1;
                fb(c,i-1,j,-1,0);
                fb(c,i+1,j,1,0);
                fb((c+1)%4,i-1,j+1,-1,1);
                fb((c+1)%4,i+1,j-1,1,-1);
                fb((c+2)%4,i,j+1,0,1);
                fb((c+2)%4,i,j-1,0,-1);
                fb((c+3)%4,i-1,j-1,-1,-1);
                fb((c+3)%4,i+1,j+1,1,1);
            }
        }
    }
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        if(mz[t.x][t.y]=='E'){
            printf("%d\n",t.t);
            return 0;
        }
        in = (t.t+1)%4;
        if(t.x&&!isV[in][t.x-1][t.y]&&!block[in][t.x-1][t.y]){
            isV[in][t.x-1][t.y] = 1;
            qu.push(gn(t.x-1,t.y,t.t+1));
        }
        if(t.y&&!isV[in][t.x][t.y-1]&&!block[in][t.x][t.y-1]){
            isV[in][t.x][t.y-1] = 1;
            qu.push(gn(t.x,t.y-1,t.t+1));
        }
        if(t.x+1<n&&!isV[in][t.x+1][t.y]&&!block[in][t.x+1][t.y]){
            isV[in][t.x+1][t.y] = 1;
            qu.push(gn(t.x+1,t.y,t.t+1));
        }
        if(t.y+1<m&&!isV[in][t.x][t.y+1]&&!block[in][t.x][t.y+1]){
            isV[in][t.x][t.y+1] = 1;
            qu.push(gn(t.x,t.y+1,t.t+1));
        }
    }
    printf("-1\n");

}
