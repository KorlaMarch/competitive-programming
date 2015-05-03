#include <stdio.h>
#include <conio.h>
#include <math.h>

int findMid(int ch){
    int n = 1;
    while(ch > 0){
        ch -= n;
        n++;
    }
    if((n - 1) % 2 == 1){
        return n - 2;
    }else{
        return n - 1;
    }
}

int main(){
    int size;
    int x,y, mid;
    char ch = 0;
    scanf("%d", &size);
    mid = findMid(size);
    //printf("mid = %d\n", mid);
    for(y = 1; size > 0; y++){
        //แผ่ทางขวา
        if(y % 2 == 1){
            for(x = 0; x < mid - 1; x++){
                putchar(' ');
            }
            for(x = 1; size > 0 && x <= y; x++){
                printf("%c", ch + 'A');
                ch = (ch + 1)%26;
                size--;
            }

        //แผ่ทางซ้าย
        }else{
            x = 0;

            if(mid == y){
                for(; x < mid - size; x++) putchar(' ');
            }
            for(; x < mid && size > 0; x++){
                if(x >= mid - y){
                    printf("%c", (ch + (mid - x - 1))%26 + 'A');
                    size--;
                }else{
                    putchar(' ');
                }
            }
            ch = (ch + y)%26;
        }

        printf("\n");
    }

    getch();
    return 0;
}
