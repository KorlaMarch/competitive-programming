#include <stdio.h>
#include <conio.h>

int table[4][4] = {
        {5,6,3,4},
        {1,7,2,8},
        {9,5,1,3},
        {2,1,4,6}
    };


int main(){
    char command[50];
    int x,y;
    printf("Enter command : "); gets(command);
    for(x = 0; command[x] != '\0' && command[x+1] != '\0'; x += 2){

        switch(command[x]){
        case 'U':
            for(y = 0; y < 3; y++){
                table[y][command[x+1]&0x0F-1] = table[y][command[x+1]&0x0F-1] ^ table[y + 1][command[x+1]&0x0F-1];
                table[y+1][command[x+1]&0x0F-1] = table[y][command[x+1]&0x0F-1] ^ table[y + 1][command[x+1]&0x0F-1];
                table[y][command[x+1]&0x0F-1] = table[y][command[x+1]&0x0F-1] ^ table[y + 1][command[x+1]&0x0F-1];
            }
            break;
        case 'D':
            for(y = 2; y >= 0; y--){
                table[y][command[x+1]&0x0F-1] = table[y][command[x+1]&0x0F-1] ^ table[y + 1][command[x+1]&0x0F-1];
                table[y+1][command[x+1]&0x0F-1] = table[y][command[x+1]&0x0F-1] ^ table[y + 1][command[x+1]&0x0F-1];
                table[y][command[x+1]&0x0F-1] = table[y][command[x+1]&0x0F-1] ^ table[y + 1][command[x+1]&0x0F-1];
            }
            break;
        case 'L':
            for(y = 0; y < 3; y++){
                table[command[x+1]&0x0F-1][y] = table[command[x+1]&0x0F-1][y] ^ table[command[x+1]&0x0F-1][y+1];
                table[command[x+1]&0x0F-1][y+1] = table[command[x+1]&0x0F-1][y] ^ table[command[x+1]&0x0F-1][y+1];
                table[command[x+1]&0x0F-1][y] = table[command[x+1]&0x0F-1][y] ^ table[command[x+1]&0x0F-1][y+1];
            }
            break;
        case 'R':
            for(y = 2; y >= 0; y--){
                table[command[x+1]&0x0F-1][y] = table[command[x+1]&0x0F-1][y] ^ table[command[x+1]&0x0F-1][y+1];
                table[command[x+1]&0x0F-1][y+1] = table[command[x+1]&0x0F-1][y] ^ table[command[x+1]&0x0F-1][y+1];
                table[command[x+1]&0x0F-1][y] = table[command[x+1]&0x0F-1][y] ^ table[command[x+1]&0x0F-1][y+1];
            }
            break;
        }
    }
    for(x = 0; x < 4; x++){
        for(y = 0; y < 4; y++){
            printf("%d ", table[x][y]);
        }
        printf("\n");
    }
    getch();
    return 0;
}
