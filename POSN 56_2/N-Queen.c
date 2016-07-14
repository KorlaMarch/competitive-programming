#include "stdio.h"

int table[100][100] = {};
int n;

int checkRow(int x, int y, int dx, int dy){
    int i, j;
    i += dx, j += dy;
    for(i = x, j = y; i >= 0 && j >= 0 && i < n && j < n; i += dx, j += dy){
        if(table[i][j] != 0){
            return 0;
        }
    }
    return 1;
}

int canPlace(int x, int y){
    return  checkRow(x, y, -1, -1) &&
            checkRow(x, y, -1, 0) &&
            checkRow(x, y, -1, 1) &&
            checkRow(x, y, 0, -1) &&
            checkRow(x, y, 0, 1) &&
            checkRow(x, y, 1, -1) &&
            checkRow(x, y, 1, 0) &&
            checkRow(x, y, 1, 1);
}

int placeQueen(int row){
    int i;
    if(row >= n){
        return 1;
    }
    for(i = 0; i < n; i++){
        if(canPlace(i, row)){
            table[i][row] = 1;
            if(placeQueen(row+1)){
                return 1;
            }else{
                table[i][row] = 0;
            }
        }
    }

    return 0;
}

int main(){
    int i,j;
    scanf("%d", &n);
    if(placeQueen(0)){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(table[j][i] == 1){
                    putchar('Q');
                }else{
                    putchar('.');
                }
            }
            putchar('\n');
        }
    }else{
        printf("No Solution\n");
    }
}
