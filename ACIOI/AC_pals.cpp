#include "stdio.h"

bool num[1000000][11];

int main(){
    int n,t,c;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &t);
        for(j = 0; j < 11; j++){
            num[i][j] = false;
        }
        while(t >= 0){
            num[i][t%10] = true;
            t /= 10;
        }
    }
    for(i = 0; i < 10; i++){
        c = 0;
        if(num[j][])
    }

}
