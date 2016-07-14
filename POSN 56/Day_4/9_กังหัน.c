#include <stdio.h>
#include <conio.h>

int main(){
    int n, size;
    int x,y;
    printf("Enter size : "); scanf("%d", &size);

    for(x = 0; x < size * 2 - 1; x++){
        for(y = 0; y < size * 2 - 1; y++){
            if(x == y){
                if(y < size){
                    printf("%d", (y+1)%10);
                }else{
                    printf("%d", ((size * 2 - 1) - y)%10);
                }
            }else if((size*2-2)-x == y){
                if(y < size){
                    printf("%d", (y+1)%10);
                }else{
                    printf("%d", ((size * 2 - 1) - y)%10);
                }
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    getch();
}
