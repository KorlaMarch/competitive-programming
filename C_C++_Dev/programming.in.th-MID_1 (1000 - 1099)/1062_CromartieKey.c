#include "stdio.h"

char mid(char a, char b, char c){
    if((a >= b && a <= c) ||(a >= c && a <= b)){
        return a;
    }else if((b >= a && b <= c) ||(b >= c && b <= a)){
        return b;
    }else{
        return c;
    }
}

int main(){
    int l,k;
    int i,j;
    char key[3][256];

    scanf("%d%d", &l, &k);
    for(i = 1; i < 3; i++){
        for(j = 0; j < l; j++){
            scanf(" %c", &key[i][j]);
        }
    }

    for(i = 0; i < k; i++){
        scanf(" %c", &key[0][i]);
    }
    key[0][k] = '\0';
    for(i = 0; i < l+k; i++){
        for(j = k-i-1; j-k+i+1 < l && j < k; j++){
            if(j >= 0){
                key[0][j] = mid(key[0][j], key[1][j-k+i+1], key[2][j-k+i+1]);
                //printf("%d %d get : %c\n", i, j, key[0][j]);
            }
        }
        //printf("%s\n", key[0]);
    }
    printf("%s\n", key[0]);
}
