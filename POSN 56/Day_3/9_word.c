#include <stdio.h>
#include <conio.h>

int main(){
    int ch, time;
    int x,y;

    printf("Enter number of char : "); scanf("%d", &ch);
    printf("Enter times : "); scanf("%d", &time);

    for(x = 0; x < time; x++){
        for(y = 0; y < ch; y++){
            printf("%c", 'A' + (x + y)%ch);
        }
        printf(" ");
    }

    getch();
    return 0;
}
