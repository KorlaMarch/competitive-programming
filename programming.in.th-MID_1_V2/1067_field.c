#include "stdio.h"

int main(){
    int n,m,k,i,j,x,y;
    char p;
    char fi[100][100];
    char run[100][100] = {};
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf(" %c",&fi[i][j]);
        }
    }
    for(i = 1; i <= k; i++){
        scanf("%d%d",&x,&y);
        p = 1;
        x--,y--;
        while(p){
            if(run[y][x] == i){
                printf("NO\n");
                break;
            }else{
                run[y][x] = i;
                switch(fi[y][x]){
                case '1':
                    if(y<1){
                        printf("N\n");
                        p=0;
                    }else{
                        y--;
                    }
                    break;
                case '2':
                    if(x+1>=n){
                        printf("E\n");
                        p=0;
                    }else{
                        x++;
                    }
                    break;
                case '3':
                    if(y+1>=m){
                        printf("S\n");
                        p=0;
                    }else{
                        y++;
                    }
                    break;
                case '4':
                    if(x<1){
                        printf("W\n");
                        p=0;
                    }else{
                        x--;
                    }
                    break;
                }
            }
        }

    }
}
