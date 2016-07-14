#include "stdio.h"

int len(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

int main(){
    char patten[16];
    int w,h,i,j,l;
    gets(patten);
    l = len(patten);
    scanf("%d%d", &w, &h);
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            putchar(patten[(i+j)%l]);
        }
        printf("\n");
    }
}
