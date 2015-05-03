#include <stdio.h>
#include <conio.h>

int strlen(char s[]){
    int x;
    for(x = 0; s[x] != '\0'; x++);
    return x;
}

int main(){
    char s1[100];
    char s2[100];
    int len1, len2, x, y;
    // 0 = s1
    // 1 = s2
    int Tpos[2] = {-1,0};

    gets(s1);
    gets(s2);

    len1 = strlen(s1);
    len2 = strlen(s2);

    Tpos[0] = len1;

    for(x = 0; x < len1; x++){
        for(y = 0; y < len2; y++){
            if(s1[x] == s2[y]){
                Tpos[0] = x;
                Tpos[1] = y;
            }
        }
    }

    for(x = 0; x < len2; x++){
        for(y = 0; y <= len1; y++){
            if(y == Tpos[0]){
                printf("%c", s2[x]);
            }else if(x == Tpos[1]){
                printf("%c", s1[y]);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    getch();
    return 0;
}
