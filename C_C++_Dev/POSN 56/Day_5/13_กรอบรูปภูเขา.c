#include <stdio.h>
#include <conio.h>

int main(){
    int h;
    int x,y;
    printf("Enter hight : "); scanf("%d", &h);
    for(y = 0; y < h; y++){
        //space
        printf("|");
        for(x = 0; x < h*2 - 1; x++){

            if(x < h-y-1 || x > h+y-1){
                printf(" ");
            }else{
                printf("*");
            }
        }
        printf("|\n");
    }
    getch();
    return 0;
}
