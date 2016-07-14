#include <stdio.h>
#include <conio.h>

int main(){
    int sum = 0, size, x, y;
    printf("Enter size : "); scanf("%d", &size);
    for(x = 2; x < size - 1; x++){
        for(y = 2; y <= x; y++){
            //printf("%d",y);
            sum += y;
        }
        //printf("\n");
    }
    printf("Sum = %d", sum);
    getch();
}
