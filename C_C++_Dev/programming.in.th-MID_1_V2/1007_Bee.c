#include "stdio.h"
int i;
int bee[26][2];
int main(){
    bee[0][0] = 1;
    for(i = 1; i <= 25; i++){
        bee[i][0] = 1+bee[i-1][0]+bee[i-1][1];
        bee[i][1] = bee[i-1][0];
    }
    while(1){
        scanf("%d",&i);
        if(i==-1) break;
        printf("%d %d\n", bee[i][0],bee[i+1][0]);
    }
}
