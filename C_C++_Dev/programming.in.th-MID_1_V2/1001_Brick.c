#include "stdio.h"
int main(){
    int n,m,i,j,b;
    char map[21][20];
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf(" %s",map[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d",&b);
        for(j = 0; j < n&&map[j][i] != 'O'; j++);
        for(j--;b>0&&j>=0; b--,j--) map[j][i] = '#';
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}
