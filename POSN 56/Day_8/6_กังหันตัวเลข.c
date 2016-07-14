#include <stdio.h>
#include <conio.h>

int strlen(char s[]){
    int x;
    for(x = 0; s[x] != '\0'; x++);
    return x;
}

int main(){
    char s[100];
    int len, x, y;
    printf("Enter S :");
    gets(s);
    len = strlen(s);
    for(x = 0; x < len; x++){
        for(y = 0; y < len; y++){
            if(y == (len-1)/2 || x == (len-1)/2){
                putchar(s[y]);
            }else{
                putchar(' ');
            }
        }
        //เลื่อน ตำแหน่ง
        for(y = 0; y < len - 1; y++){
            s[y] = s[y] ^ s[y + 1];
            s[y + 1] = s[y] ^ s[y + 1];
            s[y] = s[y] ^ s[y + 1];
        }
        //printf("\n");
        //for(y = 0; y < len; y++) printf("%c ", s[y]);
        printf("\n");
    }
    getch();
    return 0;
}
