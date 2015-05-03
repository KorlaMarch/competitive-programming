#include "stdio.h"

int isVowel(char c){
    switch(c){
    case 'a': case 'e': case 'i': case 'o': case 'u':
        return 1;
    }
    return 0;
}
int main(){
    int i;
    char s[105];
    scanf(" %[^\n]", s);
    for(i = 2; s[i-2]; i++){
        if(isVowel(s[i-2]) && s[i-1] == 'p' && isVowel(s[i])){
            putchar(s[i]);
            i+=2;
        }
        else putchar(s[i-2]);
    }

}
