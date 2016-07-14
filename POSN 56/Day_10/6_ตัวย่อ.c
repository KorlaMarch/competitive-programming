#include <stdio.h>
#include <conio.h>
#include <string.h>

void toLower(char *s){
    int x;
    for(x = 0; *(s+x) != '\0'; x++){
        if(*(s+x) >= 'A' && *(s+x) <= 'Z'){
            *(s+x) += 0x20;
        }
    }
}

int main(){
    char s[512];
    char d[256] = "";
    int p = 0;
    char word[32];
    int x = 0, y = 0;
    printf("Enter String :"); gets(s);
    toLower(s);
    //printf("%s\n", s);
    while(x == 0 || s[x - 1] != '\0'){
        if(s[x] != ' '){
            //printf("Loop\n");
            for(y = 0; s[x] != ' ' && s[x] != '\0'; x++, y++){
                word[y] = s[x];
            }
            word[y] = '\0';
            //printf("%s\n", word);
            if(strcmp(word, "i") && strcmp(word, "of") && strcmp(word, "the") &&
             strcmp(word, "on") && strcmp(word, "at") && strcmp(word, "for") &&
             strcmp(word, "with") && strcmp(word, "a") && strcmp(word, "an") && strcmp(word, "in")){
                    if(word[0] => 'a' && word[0] <= 'z'){
                        d[p] = word[0] - 0x20;
                    }else{
                        d[p] = word[0];
                    }

                    p++;
            }
        }
        x++;
    }
    d[p] = '\0';
    printf("%s", d);
    getch();
    return 0;
}
