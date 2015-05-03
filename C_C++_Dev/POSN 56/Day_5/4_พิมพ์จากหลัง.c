#include <stdio.h>
#include <conio.h>

int strlen(char s[]){
    int x;
    for(x = 0; s[x] != '\0'; x++);
    return x;
}

int main(){
    char s[50];
    int x;
    printf("Input string : "); gets(s);
    for(x = strlen(s) - 1; x >= 0; x--){
        putchar(s[x]);
    }
    getch();
    return 0;
}
