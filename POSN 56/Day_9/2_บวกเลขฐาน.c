#include <stdio.h>
#include <conio.h>


int strlen(char *s){
    int x;
    for(x = 0; s[x] != '\0'; x++);
    return x;
}

int main(){
    int base;
    char num1[11];
    char num2[11];
    char sum[15] = {0};
    int x;
    int len1, len2;
    printf("X = "); scanf("%d", &base);
    printf("Num1 = "); scanf("%s", num1);
    printf("Num2 = "); scanf("%s", num2);

    len1 = strlen(num1) - 1;
    len2 = strlen(num2) - 1;

    //printf("%d %d\n", len1, len2);

    for(x = 0; len1 >= 0 || len2 >= 0; len1--, len2--, x++){
        if(len1 >= 0) sum[x] += (num1[len1] & 0x0F);
        if(len2 >= 0) sum[x] += (num2[len2] & 0x0F);
        if(sum[x] >= base){
            sum[x + 1] = sum[x] / base;
            sum[x] = sum[x] % base;
        }
        sum[x] = sum[x] | 0x30;
    }

    if(sum[x] == 1){
        sum[x] = sum[x] | 0x30;
    }
    printf("Sum = ");
    while(x >= 0){
        printf("%c", sum[x]);
        x--;
    }
    getch();
    return 0;
}
