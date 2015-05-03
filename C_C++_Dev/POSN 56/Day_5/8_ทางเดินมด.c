#include <stdio.h>

#define size 5

int table[size][size];
int table_t[size][size];

void clone_table(){
    int x;
    int y;
    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            table_t[y][x] = table[y][x];
        }
    }
}

int countTouch(int p_x, int p_y){
    int count = 0;
    int x,y;
    int temp = table_t[p_x][p_y];
    table_t[p_x][p_y] = -1;

    for(y = p_y - 1; y <= p_y + 1; y++){

        for(x = p_x - 1; x <= p_x + 1; x++){

            if((p_x != x || p_y != y) && (x >= 0 && y >= 0)){

                if(table_t[x][y] == temp){
                    count += countTouch(x,y) + 1;
                    table_t[x][y] = -1;
                }
            }
        }
    }

    return count;
}

int main(){
    int maxPos[2];
    int sum,x,y;
    int max = 0, temp;
    /*for(y = 0; y < 10; y++){
        for(x = 0; x < 10; x++){

        }
    }*/

    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            scanf("%d", &table[y][x]);
        }
    }

    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            clone_table();
            temp = countTouch(x,y);
            if(temp + 1 > max){
                max = temp + 1;
                maxPos[0] = x;
                maxPos[1] = y;
            }
        }
    }

    /*for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            printf("%d ", table_t[y][x]);
        }
        printf("\n");
    }*/
    printf("%d %d",table[maxPos[0]][maxPos[1]], max);
}
