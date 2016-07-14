#include <stdio.h>

int main(){
    int size,x,y;
    printf("Enter base size : "); scanf("%d", &size);
    for(x = 1; x <= size; x++){
        for(y = 1; y <= x; y++){
            printf("*");
        }
        printf("\n");
    }
}
