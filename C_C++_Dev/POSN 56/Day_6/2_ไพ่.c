#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char pai[52][2];
    int x, i = 0, y;
    char temp[4];
    for(x = 0; x < 13; x++){
        for(y = 0; y < 4; y++){
            pai[x+13*y][0] = x;
            pai[x+13*y][1] = y;
        }
    }
    srand(time(NULL));
    while(1){
        x = rand() % 52;
        if(pai[x][0] != -1){
            if(pai[x][0] == 0){
                printf("A");
            }else if(pai[x][0] == 10){
                printf("J");
            }else if(pai[x][0] == 11){
                printf("Q");
            }else if(pai[x][0] == 12){
                printf("K");
            }else{
                printf("%d", pai[x][0] + 1);
            }

            printf(" %c\t", pai[x][1] + 3);
            pai[x][0] = -1;
            i++;
        }else if(i >= 52){
            break;
        }
    }
    getch();
    return 0;
}
