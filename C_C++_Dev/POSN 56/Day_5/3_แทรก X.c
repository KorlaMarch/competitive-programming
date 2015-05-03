#include <stdio.h>
#include <conio.h>

int main(){
    char s[50] = "";
    int x,y;
    printf("Input string : "); gets(s);
    if(s[0] != '\0'){
        for(x = 0; s[x + 1] != '\0'; x++){
            putchar(s[x]);
            if(s[x] == s[x+1]){
                putchar('X');
            }

        }
    }else{
        printf("Emply string");
    }
    putchar(s[x]);
    getch();
    return 0;
}
