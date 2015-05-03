#include <stdio.h>
#include <conio.h>

int main(){
    int sum = 0, i, in;
    for(i = 1; i <= 10; i++){
        printf("Enter %d value : ", i); scanf("%d", &in);
        sum += in;
    }

    printf("Average is = %.2f\n", sum / 10.0);
    getch();
    return 0;
}
