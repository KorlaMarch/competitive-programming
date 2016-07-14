#include <stdio.h>

int main(){
    char s[61];
    int x;
    int po = 1;
    gets(s);
    for(x = 0; s[x] != '\0'; x++){
        if(s[x] >= 'A' && s[x] <= 'Z'){
            s[x] = s[x] - 'A' - (po);
            //putchar(s[x] + 'A');
            if(s[x] < 0 && s[x]%26 != 0){
                s[x] = 26 + (s[x]%26);
            }else if(s[x]%26 == 0){
                s[x] = 0;
            }
            s[x] += 'A';
            po++;
        }else if(s[x] >= 'a' && s[x] <= 'z'){
            s[x] = s[x] - 'a' - (po);
            if(s[x] < 0 && s[x]%26 != 0){
                s[x] = 26 + s[x] % 26;
            }else if(s[x]%26 == 0){
                s[x] = 0;
            }
            s[x] += 'a';
            po++;
        }
    }
    printf("%s", s);
    return 0;
}
