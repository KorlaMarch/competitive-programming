#include <stdio.h>
#include <conio.h>

int main(){
    int i,j,sum;
    for(j = 2; j <= 13; j++){
        for(i = 2, sum = 0; i <= 100; i += j){
            sum += i;
        }
        printf("J = %d , sum = %d\n", j, sum);
    }
    getch();
    return 0;
}
