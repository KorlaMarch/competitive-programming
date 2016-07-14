#include <stdio.h>
#include <conio.h>

int main(){
    int x,y,n,ch;
    printf("Enter n : "); scanf("%d", &n);
    ch = n;
    for(x = 0; n > 0; x++){
        for(y = 0; y < x && n > 0; y++,n--){
            printf("%c", (ch - n)%26 + 'A');
        }
        printf("\n");
    }
    getch();
}
