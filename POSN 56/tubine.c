#include <stdio.h>

int main(){
    int n, x, y;
    scanf("%d", &n);
    for(y = 0; y < n*2-1; y++){
        for(x = 0; x < n*2-1; x++){
            if(x == y || x == n*2-2 - y){
                if((n*2-1)/2 - y < 0){
                    printf("%c", (y - (n*2-1)/2)%26 + 'A');
                }else{
                    printf("%c", ((n*2-1)/2 - y)%26 + 'A');
                }

            }else{
                printf(" ");
            }
        }

        printf("\t");

        for(x = 0; x < n*2-1; x++){
            if(x == y || x == n*2-2 - y){
                printf("*");
            }else{
                printf(" ");
            }
        }

        printf("\n");
    }
}
