#include <stdio.h>
#include <conio.h>

int main(){
    int a[8] = {6,8,4,3,7,5,3,1};
    char command;
    int time;
    int x, y;
    printf("Enter command (L,R) : ");
    scanf("%c", &command);
    printf("Enter time : ");
    scanf("%d", &time);
    for(x = 0; x < time; x++){
        if(command == 'L'){
            for(y = 0; y < 7; y++){
                a[y] = a[y] ^ a[y + 1];
                a[y+1] = a[y] ^ a[y + 1];
                a[y] = a[y] ^ a[y + 1];
            }
        }else if(command == 'R'){
            for(y = 7; y > 0; y--){
                a[y] = a[y] ^ a[y - 1];
                a[y-1] = a[y] ^ a[y - 1];
                a[y] = a[y] ^ a[y - 1];
            }
        }else{
            printf("Error!\n");
        }
    }
    for(x = 0; x < 8; x++){
        printf("%d ", a[x]);
    }
    printf("\n");
    getch();
    return 0;
}
