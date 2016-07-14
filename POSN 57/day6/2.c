#include "stdio.h"

int main(){
    int n,i,j,c;
    scanf("%d", &n);
    for(i=1,c=0; c < n; i++){
        for(j = 0; j < i && c < n; j++,c++){
            putchar('A'+c%26);
        }
        printf("\n");
    }
}
