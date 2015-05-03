#include <stdio.h>
#include <conio.h>

int main(){
    int start, day;
    int x;
    printf("Total : "); scanf("%d", &day);
    printf("Start (1 = Sundey, 2 = Mondey...) : "); scanf("%d", &start);
    printf("\n\tSu\tMo\tTu\tWe\tTh\tFr\tSa\n\n");
    for(x = 1 - x; x <= day; x++){
        if(x > 0){
            printf("\t%d", x);
            if((x+start)%7 == 0){
                printf("\n");
            }
        }else{
                printf("\t");
        }
    }
    getch();
    return 0;
}
