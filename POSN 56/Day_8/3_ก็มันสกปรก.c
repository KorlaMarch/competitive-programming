#include <stdio.h>
#include <conio.h>

int main(){
    char s[160];
    int p = 0;
    char c, beforec = ' ';
    do{
        c = getche();
        if(c != beforec){
            s[p] = c;
            p++;
        }
        beforec = c;
    }while(c != '\r');
    s[p] = '\0';
    printf("\n%s\n", s);
    getch();
    return 0;
}
