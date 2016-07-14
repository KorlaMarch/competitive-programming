#include <stdio.h>
#include <conio.h>

int strlen(char s[]){
    int x;
    for(x = 0; s[x] != '\0'; x++);
    return x;
}

int main(){
    char patten[10];
    int l,h;
    int x,y;
    int len;

    printf("Input Patten : "); scanf("%s", patten);
    printf("Input length : "); scanf("%d", &l);
    printf("Input hight : "); scanf("%d", &h);

    len = strlen(patten);
    for(y = 0; y < h; y++){
        for(x = 0; x < l; x++){
            putchar(patten[(y + x)%len]);
        }
        printf("\n");
    }
    getch();
}
