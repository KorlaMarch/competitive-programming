#include "stdio.h"

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    char in[26][26];
    int room[26][26] = {};
    int rowSum[26][26][2];
    int m,n,i,j;
    int maxP = 0;
    scanf("%d%d", &n , &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf(" %c", &in[i][j]);
        }
    }
    //make row sum
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(i > 0 && in[i-1][j] == '0'){
                rowSum[i][j][0] = rowSum[i-1][j][0]+1;
            }else{
                rowSum[i][j][0] = 2;
            }

            if(j > 0 && in[i][j-1] == '0'){
                rowSum[i][j][1] = rowSum[i][j-1][1]+1;
            }else{
                rowSum[i][j][1] = 2;
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(in[i][j] == '0'){
                if(i > 0 && j > 0 && in[i-1][j] == '0' && in[i][j-1] == '0'){
                    room[i][j] = max(room[i-1][j], room[i][j-1])+1;
                }else if(i > 0 && in[i-1][j] == '0'){
                    room[i][j] = rowSum[i][j][0];
                }else if(j > 0 && in[i][j-1] == '0'){
                    room[i][j] = rowSum[i][j][1];
                }else{
                    room[i][j] = 2;
                }
            }
            if(room[i][j] > maxP){
                maxP = room[i][j];
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%2d", room[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", maxP*2);
}
