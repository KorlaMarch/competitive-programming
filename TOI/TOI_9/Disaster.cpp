#include "stdio.h"

int main(){
    bool adjM[30][30] = {};
    char a,b,c,maxC = 0;
    bool isFind;
    int n,i,j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf(" %c%c", &a, &b);
        adjM[a-'A'][b-'A'] = true;
        adjM[b-'A'][a-'A'] = true;
        if(a > maxC){
            maxC = a;
        }
        if(b > maxC){
            maxC = b;
        }
    }

    for(i = 0; i < 28; i++){
        for(j = 0,c = 0; j < 28; j++){
            if(adjM[i][j]){
                c++;
            }
        }
        if(c%2 == 1){
            break;
        }
    }
    if(i == 28){
        i = maxC-'A';
    }
    while(i != -1){
        printf("%c ", i+'A');
        isFind = false;
        for(j = 0; j < 28; j++){
            if(adjM[i][j]){
                isFind = true;
                adjM[i][j] = false;
                adjM[j][i] = false;
                i = j;
                break;
            }
        }
        if(!isFind){
            i = -1;
        }
    }
}
