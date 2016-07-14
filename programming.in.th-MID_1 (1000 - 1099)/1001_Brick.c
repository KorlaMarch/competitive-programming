#include <stdio.h>

char gameBoard[20][21];

void addBirck(int pos, int col, int num){
    int x;
    for(x = pos; x >= 0 && num > 0; x--){
        gameBoard[x][col] = '#';
        num--;
    }
}

int main(){
    int n, m, brick;
    int x, y;
    scanf("%d%d", &n, &m);

    //input board
    for(x = 0; x < n; x++){
        scanf("%s", gameBoard[x]);
    }

    //add brick
    for(x = 0; x < m; x++){
        scanf("%d", &brick);
        for(y = -1; y < n; y++){
            if(y + 1 == n || gameBoard[y + 1][x] == 'O'){
                addBirck(y, x, brick);
                break;
            }
        }
    }

    //print
    for(y = 0; y < n; y++){
        printf("%s\n", gameBoard[y]);
    }
}
