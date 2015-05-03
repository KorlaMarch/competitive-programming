#include "stdio.h"

int main(){
    char keypad[10][6] = {"!@.0","?,;1","abc2","def3","ghi4","jkl5","mno6","pqrs7","tuv8","wxyz9"};
    char c,lc = ' ';
    int i = -1;
    while((c = getchar()) != '*'){
        //printf("\ni = %d lc = %c c = %c\n", i, lc, c);
        if((c != lc || c == ' ') && lc != ' '){
            if(lc == '#')
                putchar(' ');
            else{
                //i--;
                if(keypad[lc-'0'][4] == '\0'){
                    putchar(keypad[lc-'0'][i%4]);
                }else{
                    putchar(keypad[lc-'0'][i%5]);
                }

            }
            if(c == ' '){
                i = -1;
            }else{
                i = 0;
            }
        }else{
            i++;
        }
        lc = c;
    }
    if(lc == '#') putchar(' ');
    else if(keypad[lc-'0'][4] == '\0'){
        putchar(keypad[lc-'0'][i%4]);
    }else{
        putchar(keypad[lc-'0'][i%5]);
    }
}
