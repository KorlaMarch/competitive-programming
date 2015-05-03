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
    int month;
    //int bunny[100] = {1};
    //int point = 1;
    //printf("%d", fiboAt(7));
    scanf("%d", &month);
    /*for(x = 0; x < month; x++){
        for(y = 0; y < point; y++){
            bunny[y]++;
            if(bunny[y] > 2){
                bunny[point] = 0;
                point++;
                all++;
            }
        }
    }

    for(x = 0; x < point; x++){
        printf("%d ", bunny[x]);
    }*/
    printf("All = %d\n", fiboAt(month + 1));
    getch();
    return 0;
}
