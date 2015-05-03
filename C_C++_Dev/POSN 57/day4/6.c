#include "stdio.h"
#include "conio.h"

int main(){
    int n,m;
    int i,j;
    int last[200][2];
    scanf("%d%d", &last[0][0], &m);
    last[0][1] = last[0][0];
    for(i = 0; i < m; i++){
        for(j = 1; j < m-i; j++) putchar(' ');
        for(j = 0; j <= i; j++){
            printf("%d ", last[j][i%2]);
        }
        //update
        last[i+1][i%2] = last[i+1][(i+1)%2] = last[0][i%2];
        for(j = 1; j <= i+1; j++){
            last[j][i%2] = last[j-1][(i+1)%2]+last[j][(i+1)%2];
        }
        putchar('\n');
    }
    getch();
}
