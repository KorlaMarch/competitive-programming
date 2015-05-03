#include "stdio.h"

/*
TASK: Frog
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

int r[501][501];
int d[501][501];
int hop[501][501];

int main(){
    int fcount,n,m,i,j,x,min;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        scanf("%d%d", &m, &n);
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &r[i][j]);
            }
        }
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &d[i][j]);
            }
        }
        hop[m-1][n-1] = 0;
        for(i =  n-1;  i >= 0; i--){

            for(j = i == n-1 ? m-2 : m-1; j >= 0; j--){
                min = 99999;
                //find min
                //right
                //printf("t %d %d\n", j, i);
                for(x = 1; x <= r[j][i] && x+i < n; x++){
                    if(hop[j][i+x] < min){
                        min = hop[j][i+x];
                    }
                    //printf("look %d %d\n", j, i+x);
                }
                //down
                for(x = 1; x <= d[j][i] && x+j < m; x++){
                    if(hop[j+x][i] < min){
                        min = hop[j+x][i];
                    }
                    //printf("look %d %d\n", j+x, i);
                }
                //printf("min = %d\n",min);
                hop[j][i] = min+1;
            }
        }
        /*printf("\n");
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                printf("%d ", hop[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n", hop[0][0]);
    }
}
