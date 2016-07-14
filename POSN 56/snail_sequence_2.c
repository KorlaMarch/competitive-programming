#include <stdio.h>
#include <conio.h>

#define after 0
#define before 1

int strlen(char *s){
    int x;
    for(x = 0; *(s+x) != '\0'; x++);
    return x;
}

void strc(char *dest, char ch, int mode){
    int x;
    int len = strlen(dest);

    if(mode == after){
        *(dest + len) = ch;
        *(dest + len + 1) = '\0';
    }else{
        for(x = len - 1; x >= 0; x--){
            *(dest+x + 1) = *(dest+x);
        }
        *dest = ch;
    }
    return;
}

void strDelete(char *s, int mode){
    int x;
    if(mode == after){
        *(s + strlen(s) - 1) = '\0';
    }else{
        for(x = 0; *(s + x) != '\0'; x++){
            *(s + x) = *(s + x + 1);
        }
    }
}

void strPlus(char *s ,int times){
    int x;
    for(x = 0; *(x + s) != '\0'; x++){
        *(x+s) = (*(x+s)-'A' + times)%26 + 'A';
    }
}

void snailPrint(int n,char ch, char *st, char *en){
    int x;
    if(n <= 1){
        printf("%s%c%s\n", st, 'A', en);
        return;
    }
    printf("%s", st);
    for(x = 0; x < n; x++){
        printf("%c", (ch+n*3-4-x)%26 + 'A');
    }
    printf("%s\n", en);
    strPlus(st, 1);
    strc(st, (ch+n*3-3)%26 + 'A', after);
    strPlus(en, -1);
    strc(en, (ch+n*2-4)%26 + 'A', before);
    snailPrint(n - 2, ch-(n-2)*3+1, st, en);

    strPlus(st, 1);
    strDelete(st, after);
    strPlus(en, -1);
    strDelete(en, before);

    printf("%s", st);
    for(x = 0; x < n; x++){
        if(x == 0){
            printf("%c", (ch+n*4-5)%26 + 'A');
        }else if(x == n - 1){
            printf("%c", (ch+n-2)%26 + 'A');
        }else{
            printf("%c", (ch+x-1)%26 + 'A');
        }
    }
    printf("%s\n", en);

}

int main(){
    int n;
    char st[256] = {'\0'};
    char en[256] = {'\0'};
    snailPrint(7,25, st, en);
    /*strc(st, 'C', before);
    printf("%s", st);
    //strDelete(st, before);
    printf("\n%s", st);*/
    getch();
    return 0;
}
