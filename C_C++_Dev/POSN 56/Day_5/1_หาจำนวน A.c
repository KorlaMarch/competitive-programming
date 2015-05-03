#include <stdio.h>
#include <conio.h>

int main(){
    char s[21];
    int x, sum = 0;
    char c;
    printf("Input string : "); gets(s);
    printf("Input Char :"); scanf("%c", &c);
    for(x = 0; s[x] != '\0'; x++){
        if(s[x] == c){
            sum++;
        }
    }
    printf("Finding '%c' in %s : %d\n", c, s, sum);
    getch();
    return 0;
}
