#include "stdio.h"

char isUsed[10] = {};
int path[10] = {};

void list_p(int n, int d){
    int i;
    if(d >= n){
        //print P
        for(i = 0; i < n; i++){
            printf("%d ", path[i]+1);
        }
        printf("\n");
        return;
    }

    for(i = 0; i < n; i++){
        if(!isUsed[i]){
            isUsed[i] = 1;
            path[d] = i;
            list_p(n, d+1);
            isUsed[i] = 0;
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    list_p(n, 0);
}
