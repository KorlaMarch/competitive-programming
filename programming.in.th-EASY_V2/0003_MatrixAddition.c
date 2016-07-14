#include "stdio.h"

int main(){
    int i,j,m,n,x;
    int ma[100][100];
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &ma[i][j]);
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &x);
            printf("%d ", ma[i][j]+x);
        }
        printf("\n");
    }
}
