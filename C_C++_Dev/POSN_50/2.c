#include "stdio.h"

int main(){
    int n,i,j;
    scanf("%d", &n);
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(i == 0 || j == 0 || i == j){
                putchar('*');
            }else{
                putchar(' ');
            }
        }
        putchar('\n');
    }
}
