#include "stdio.h"
int m,n,i,j,a;
char map[1005][1005];

void set(int i, int j){
    if(i>=0&&j>=0&&i<n&&j<m&&map[i][j]=='A') map[i][j] = '.';
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf(" %s", map[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(map[i][j]=='+'){
                map[i][j] = '.';
                set(i-1,j);
                set(i+1,j);
                set(i,j-1);
                set(i,j+1);
            }else if(map[i][j]=='x'){
                map[i][j] = '.';
                set(i-2,j-2);
                set(i+2,j-2);
                set(i-2,j+2);
                set(i+2,j+2);
                set(i-1,j-1);
                set(i+1,j-1);
                set(i-1,j+1);
                set(i+1,j+1);
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(map[i][j]=='A') a++;
        }
    }
    printf("%d\n",a);
    for(i = 0; i < n; i++){
        printf("%s\n",map[i]);
    }
}
