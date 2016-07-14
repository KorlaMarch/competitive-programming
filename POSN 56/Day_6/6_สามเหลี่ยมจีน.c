#include <stdio.h>
#include <conio.h>

int main(){
    int border, hight;
    int n[100] = {0};
    int x,y;
    int muti = 2;
    char temp[20];
    scanf("%d%d", &border, &hight);
    n[0] = border;
    for(x = 0; x < hight; x++){
        for(y = 0; y < hight*muti-x*muti-1; y++){
            printf(" ");
        }
        for(y = 0; y <= x; y++){
            sprintf(temp, "%%-%dd", muti*2);
            printf(temp, n[y]);
        }
        n[x] = border;
        for(y = x; y > 0; y--){
            //printf("\n%d %d\n", n[y] , n[y - 1]);
            n[y] = n[y] + n[y - 1];
        }
        n[x + 1] = border;
        printf("\n");
    }
    getch();
    return 0;
}
