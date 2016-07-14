#include "stdio.h"

void printTile(int x,int y,int n){
    int i;
    if(x == 0){
        for(i = 0; i < y; i++) putchar('A'+i);
    }else{
        for(i = 0; i < y; i++) putchar('A'+i+n-y);
    }
    printf("\n");
}

int main(){
    int n,w,h;
    int i,c;
    int tiles[2][1000] = {};
    scanf("%d%d%d", &n, &w, &h);
    for(i = 0,c = 0; i < h; i++){
        //printf("i = %d ", i);
        //front
        if(i%n){
            if(tiles[1][n-i%n]){
                //printf("Use : "); printTile(1,n-i%n,n);
                tiles[1][n-i%n]--;
            }else{
                c++;
                //printf("Cut : "); printTile(0,i%n,n);
                tiles[0][i%n]++;
            }
        }
        //back
        if((w-n+i)%n){
            if(tiles[0][(w-n+i)%n]){
                //printf("Use : "); printTile(0,(w-n+i)%n,n);
                tiles[0][(w-n+i)%n]--;
            }else{
                c++;
                //printf("Cut : "); printTile(1,n-(w-n+i)%n,n);
                tiles[1][n-(w-n+i)%n]++;
            }
        }
    }
    printf("c = %d\n", c);
    printf("Remain:\n");
    for(i = 1; i < n; i++){
        for(;tiles[0][i] > 0; tiles[0][i]--) printTile(0,i,n);
        for(;tiles[1][i] > 0; tiles[1][i]--) printTile(1,i,n);
    }
}
