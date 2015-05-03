#include "stdio.h"
#include "conio.h"

int main(){
    int base,x,y,i,j = 0,k = 0;
    char sum[50];
    scanf("%d%d%d", &base, &x, &y);
    while(x > 0 || y > 0){
        i = x%10+y%10+j;
        j = 0;
        if(i >= base){
            j = i/base;
            i = i%base;
        }
        sum[k] = i;
        k++;
        x /= 10;
        y /= 10;
        //printf("%d %d %d\n", sum[k-1], x, y);
    }
    if(j){
        sum[k] = j;
        k++;
    }
    printf("Sum is ");
    for(i = k-1; i >= 0; i--) putchar('0'+sum[i]);
    getch();
}
