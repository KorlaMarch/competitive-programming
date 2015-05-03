#include <stdio.h>
#include <conio.h>

int main(){
    char s[50];
    int key, x;
    printf("String = "); gets(s);
    printf("Key = "); scanf("%d", &key);

    for(x = 0; s[x] != '\0'; x++){
        //เช็คประเภท
        if(s[x] >= 'A' && s[x] <= 'Z'){
            s[x] = (s[x] - 'A' + key) % 26 + 'A';
        }else if(s[x] >= 'a' && s[x] <= 'z'){
            s[x] = (s[x] - 'a' + key) % 26 + 'a';
        }
    }
    printf("Out = %s", s);
    getch();
    return 0;
}
