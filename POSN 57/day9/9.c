#include "stdio.h"

int strlen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

int main(){
    char s1[32];
    char s2[32];
    int x,y,i,j,len,isFind;
    gets(s1);
    gets(s2);
    len = strlen(s1);
    //find common pos
    for(x = 0,isFind = 0; x < len && !isFind; x++){
        for(y = 0; y < len && !isFind; y++){
            if(s1[x] == s2[y]){
                isFind = 1;
            }
        }
    }
    x--;
    y--;
    if(!isFind){
        x = len;
        y = 0;
    }
    //print
    for(i = 0; i < len; i++){
        for(j = 0; j <= len; j++){
            if(i == y && j < len){
                printf("%c",s1[j]);
            }else if(j == x){
                printf("%c",s2[i]);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
