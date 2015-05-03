#include "stdio.h"
int n,k,i,j,mx,mc;
char step[4][1000];
char con[100][100];
int px[4],py[4],cu[4];
void move(int p, int x, int y){
    if(x<0||y<0||x>=n||y>=n||con[x][y]>='0'){
        return;
    }
    con[px[p]][py[p]] -= '0';
    con[x][y] = p+'1';
    px[p] = x;
    py[p] = y;
}
int main(){
    int x,y;
    scanf("%d%d",&n,&k);
    py[0] = py[1] = n-1;
    py[2] = py[3] = 0;
    px[0] = px[3] = 0;
    px[1] = px[2] = n-1;
    con[0][0] = '4';
    con[0][n-1] = '1';
    con[n-1][0] = '3';
    con[n-1][n-1] = '2';

    for(i = 0; i < 4; i++){
        for(j = 0; j < k; j++){
            scanf(" %c", &step[i][j]);
        }
    }
    for(i = 0; i < k; i++){
        for(j = 0; j < 4; j++){
            switch(step[j][i]){
            case 'N':
                move(j,px[j]-1,py[j]);
                break;
            case 'E':
                move(j,px[j],py[j]+1);
                break;
            case 'S':
                move(j,px[j]+1,py[j]);
                break;
            case 'W':
                move(j,px[j],py[j]-1);
                break;
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(con[i][j]>='0'){
                cu[con[i][j]-'1']++;
            }else if(con[i][j]){
                cu[con[i][j]-1]++;
            }else{
                printf("No\n");
                return 0;
            }
        }
    }
    for(i=mx=mc=0; i<4; i++){
        if(cu[i]>mx){
            mc = 1;
            mx = cu[i];
        }else if(cu[i]==mx) mc++;
    }
    printf("%d %d\n",mc,mx);
    for(i=0; i<4; i++){
        if(cu[i]==mx) printf("%d\n", i+1);
    }
}
