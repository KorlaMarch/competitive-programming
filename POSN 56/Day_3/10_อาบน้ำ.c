#include <stdio.h>
#include <conio.h>

int main(){
    int allday, start, x;
    int water = 0;
    printf("Enter total day : "); scanf("%d", &allday);
    printf("Enter start day : "); scanf("%d", &start);

    for(x = 1; x <= allday; x++){
        if((x + (start - 1))%7 == 3 && x % 2 == 1){
            water += 3;
        }else if((x + (start - 1))%7 == 5 && x % 2 == 1){
            water += 2;
        }else{
            water += 5;
        }

    }

    printf("Water = %d\n", water);
    getch();
    return 0;
}
