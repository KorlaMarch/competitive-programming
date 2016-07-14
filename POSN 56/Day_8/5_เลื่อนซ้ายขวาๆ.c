#include <stdio.h>
#include <conio.h>

int main(){
    char array[5][6] = {{5,6,3,1,4,7},
                        {6,1,3,8,9,4},
                        {5,7,1,8,4,6},
                        {1,2,9,1,3,4},
                        {9,8,5,2,3,1}};

    int shift[5];
    int x;
    int read_digit;

    for(x = 0; x < 5; x++){
        scanf("%d", &shift[x]);
        shift[x]--;
    }

    /*for(x = 0; x < 5; x++){
        for(y = 0; y < 6; y++){
            printf("%d ", array[x][y]);
        }
        printf("\n");
    }*/
    scanf("%d", &read_digit);
    for(x = 0; x < 5; x++){
        if(x % 2 == 0){
            if(read_digit + shift[x] > 5){
                printf("_ ");
            }else{
                printf("%d ", array[x][read_digit + shift[x]]);
            }
        }else{
            if(read_digit - shift[x] < 0){
                printf("_ ");
            }else{
                printf("%d ", read_digit - shift[x]);
            }
        }
    }
    getch();
    return 0;
}
