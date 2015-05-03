#include <stdio.h>

int main(){
    int n,x = 0, y, size;
    int number[9];
    char digit[100];

    //clear array
    for(y = 0; y < 9; y++){
        number[y] = 0;
    }

    printf("Enter interger : ");
    while(1){
        digit[x] = getchar();
        if(digit[x] != '\n'){
            number[digit[x] - '0']++;
            x++;
        }else{
            break;
        }
    }
    x--;
    size = x;
    for(y = 0; y <= size; y++){
        printf("Digit 1");
        //print 0
        for(n = 1; n <= x; n++){
            putchar('0');
        }

        printf(" = %c\n", digit[y]);
        x--;
    }

    printf("\n");

    for(y = 0; y < 9; y++){
        if(number[y] != 0){
            printf("\'%d\' = %d\n", y, number[y]);
        }
    }

    getch();
}
