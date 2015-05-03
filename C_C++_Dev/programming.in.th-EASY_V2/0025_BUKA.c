#include "stdio.h"
int strlen(char s[]){
    int i;
    for(i=0;s[i];i++);
    return i;
}
int main(){
    char s[101],s2[101];
    char c;
    int i,j;
    scanf(" %s %c %s",s,&c,s2);
    if(c == '*'){
        printf("%s%s\n",s,s2+1);
    }else{
        i = strlen(s);
        j = strlen(s2);
        if(i==j){
            printf("2%s\n", s+1);
        }else if(i>j){
            s[i-j] = '\0';
            printf("%s%s\n",s,s2);
        }else{
            s2[j-i] = '\0';
            printf("%s%s\n",s2,s);
        }
    }
}
