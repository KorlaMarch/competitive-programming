#include <stdio.h>
#include <conio.h>

int fiboAt(int n){
    int before = 0, num = 1;
    while(n > 1){
        num = num + before;
        before = num - before;
        n--;
    }
    return num;
}

int main(){
    /*int month;
    scanf("%d", &month);
    if(month < 12){
        printf("All = %d\n", fiboAt(month + 1));
    }else{
        printf("All = %d\n", fiboAt(month + 1) - fiboAt(month - 12));
    }
    getch();
    return 0;*/

    int month;
    int bunny[1000] = {1};
    int point = 1;
    int x,y;
    int all = 1;
    //printf("%d", fiboAt(7));
    scanf("%d", &month);
    for(x = 0; x < month; x++){
        for(y = 0; y < point; y++){
            if(bunny[y] != -1) bunny[y]++;
            if(bunny[y] > 2){
                bunny[point] = 0;
                point++;
                all++;
            }

            if(bunny[y] >= 12){
                bunny[y] = -1;
                all--;
            }
        }
    }

    /*for(x = 0; x < point; x++){
        printf("%d ", bunny[x]);
    }*/
    printf("All = %d\n", all);
    getch();
    return 0;
}
