#include "stdio.h"

char dishNum[21][3] = {};
int top[3] = {};

void moveBlock(char from, char to){
    if(top[to] == 0 || dishNum[top[to]-1][to] > dishNum[top[from]-1][from]){
        printf("%d %c %c\n", dishNum[top[from]-1][from], from+'A', to+'A');
        dishNum[top[to]][to] = dishNum[top[from]-1][from];
        dishNum[top[from]-1][from] = 0;
        top[to]++;
        top[from]--;
    }else{
        printf("Error!\n");
    }
}

void showMoveHanoi(int size, char from, char to){
    if(size == 1){
        moveBlock(from, to);
        return;
    }
    showMoveHanoi(size-1, from, 3-from-to);
    moveBlock(from, to);
    showMoveHanoi(size-1, 3-from-to, to);
}

int main(){
    int n,i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        dishNum[i][0] = n-i;
    }
    top[0] = n;
    showMoveHanoi(n, 0, 2);
}
