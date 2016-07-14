#include "stdio.h"

/*
TASK: Satellite
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

int m,n;
char map[100][100];

int flood(int x, int y){
    int sum = 1;
    map[x][y] = '-';
    //printf("flood %d %d\n", x, y);
    if(x > 0 && map[x-1][y] != '-'){
        sum += flood(x-1, y);
    }
    if(y > 0 && map[x][y-1] != '-'){
        sum += flood(x, y-1);
    }
    if(x+1 < m && map[x+1][y] != '-'){
        sum += flood(x+1, y);
    }
    if(y+1 < n && map[x][y+1] != '-'){
        sum += flood(x, y+1);
    }
    return sum;
}

int main(){
    int i,j,x;
    int max;
    int fcount;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 5; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        scanf("%d%d", &m, &n);
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf(" %c", &map[i][j]);
            }
        }
        max = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(map[i][j] == '+'){
                    x = flood(i,j);
                    //printf("x = %d\n", x);
                    if(x > max){
                        max = x;
                    }
                }
            }
        }
        if(max > 4){
            printf("%d\n", max);
        }else{
            printf("0\n");
        }
    }
}
