#include <stdio.h>
#include <conio.h>

int checkAnagram(char *a, char *b){
    int num[30] = {0};
    int num2[30] = {0};
    int x;
    while(*a != '\0' || *b != '\0'){
        num[*a >= 'a' && *a <= 'z' ? *a - 0x20 - 'A' : *a - 'A']++;
        num2[*b >= 'a' && *b <= 'z' ? *b - 0x20 - 'A' : *b - 'A']++;
        a++;
        b++;
    }

    for(x = 0; x < 30; x++){
        if(num[x] != num2[x]) return 0;
    }
    return 1;
}

int main(){
    char s[20][100];
    int n,x;
    printf("Enter n :"); scanf("%d", &n);
    for(x = 0; x < n*2; x += 2){
        scanf("%s", s[x]);
        scanf("%s", s[x+1]);
    }
    for(x = 0; x < n*2; x += 2){
        if(checkAnagram(s[x], s[x + 1]) == 1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    getch();
    return 0;
}
