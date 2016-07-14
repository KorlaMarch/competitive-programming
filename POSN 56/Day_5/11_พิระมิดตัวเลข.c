#include <stdio.h>
#include <conio.h>

int main(){
    int n;
    int x,x2,y;
    printf("Enter n : "); scanf("%d", &n);
    for(y = 0; y < n; y++){
        //space

        for(x = 0, x2 = (y + 1)%10; x < n*2; x++){

            if(x < n-y-1 || x > n+y-1){
                printf(" ");
            }else{
                putchar(x2 + '0');
                if(x < n - 1){
                    x2++;
                    if(x2 > 9) x2 = x2 % 10;
                }else{
                    x2--;
                    if(x2 < 0) x2 = 9;
                }


            }
        }
        printf("\n");
    }
    getch();
}
