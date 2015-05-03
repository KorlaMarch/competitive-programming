#include <stdio.h>
#include <conio.h>

int main(){
    int n[3];
    int out[3];
    char patten[4];
    char x;
    int y, max, charPos;
    scanf("%d%d%d%s", &n[0], &n[1], &n[2], patten);
    //sort
    for(x = 'C'; x >= 'A'; x--){

        max = 0;
        for(y = 0; y < 3; y++){
            if(n[y] > n[max]){
                max = y;
            }
            if(patten[y] == x){
                charPos = y;
            }
        }
        out[charPos] = n[max];
        n[max] = -1;
    }

    printf("%d %d %d", out[0], out[1], out[2]);

    getch();
    return 0;
}
