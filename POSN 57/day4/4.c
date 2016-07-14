#include "stdio.h"
#include "conio.h"

int main(){
    int sum = 0,i = 0,n;
    do{
        scanf("%d", &n);
        if(n >= 0){
            sum += n;
            i++;
        }
    }while(n >= 0);
    printf("Sum is %d\nAvg is %.2f", sum, (float)sum/i);
    getch();
}
