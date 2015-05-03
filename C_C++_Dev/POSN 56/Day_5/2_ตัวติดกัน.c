#include <stdio.h>
#include <conio.h>

int main(){
    char s[50] = "";
    int x,y;
    printf("Input string : "); gets(s);
    if(s[0] != '\0'){
        for(x = 0; s[x + 1] != '\0'; x++){
            if(s[x] == s[x+1]){
                printf("Find double %c at %d\n", s[x], x + 1);
                //skip ถ้าติดกัน 2 ตัวขึ้นไป
                for(y = 0; s[x + 1] == s[x]; y++){
                    x++;
                }
            }

        }
    }else{
        printf("Emply string");
    }
    getch();
    return 0;
}
