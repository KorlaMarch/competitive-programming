#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
    int width;
    int x,y;
    printf("Enter width : "); scanf("%d", &width);
    for(x = 0; x < width*2-1; x++){
        for(y = 0; y < width; y++){
            if(width - abs(width - x - 1) > y){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(y = 0; y < width; y++){
            if(abs(width - x - 1) <= y){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    getch();
    return 0;
}
