#include "stdio.h"
#include "conio.h"

int main(){
    char c,lc;
    int i = 1;
    char s[256];
    lc = getchar();
    s[0] = lc;
    while((c = getchar()) != '\n'){
        if(c != lc){
            s[i] = c;
            i++;
            lc = c;
        }
    }
    s[i] = '\0';
    printf("%s\n", s);
    getch();
}
