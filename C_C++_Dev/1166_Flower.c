#include "stdio.h"

char map[500][500];
int maxS = 0;
int n,m;

void SpendRock(){
    int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(map[i][j] == '#'){
                if(i > 0){
                    map[i-1][j] = '-';
                }
                if(j > 0){
                    map[i][j-1] = '-';
                }
                if(i+1 < n){
                    if(map[i+1][j] == '.'){
                        map[i+1][j] = '-';
                    }
                }
                if(j+1 < m){
                    if(map[i][j+1] == '.'){
                        map[i][j+1] = '-';
                    }
                }
            }
        }
    }
}

int flood(int x,int y){
    int k = 1;
    //printf("call %d %d = %c\n",x,y,map[x][y]);
    //printMap();
    if(map[x][y] != '.'){
        return 0;
    }

    map[x][y] = '@';
    if(x+1 < n && map[x+1][y] == '.'){
        k += flood(x+1,y);
    }
    if(y+1 < m && map[x][y+1] == '.'){
        k += flood(x,y+1);
    }
    if(x > 0 && map[x-1][y] == '.'){
        k += flood(x-1,y);
    }
    if(y > 0 && map[x][y-1] == '.'){
        k += flood(x,y-1);
    }
    return k;
}

void printMap(){
    int i,j;
    printf("map :\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i,j,t;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf(" %c", &map[i][j]);
        }
    }
    SpendRock();

    for(i = 0; i < n;i++){
        for(j = 0; j < m;j++){
            if(map[i][j] == '.'){
                t = flood(i,j);
                //printf("flood %d %d = %d\n", i,j,t);
                //printMap();
                if(t > maxS){
                    maxS = t;
                }
            }
        }
    }
    printf("%d\n", maxS);
}
