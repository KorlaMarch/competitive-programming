#include "stdio.h"
#include "string.h"

char s1[101],s2[101];

int main(){
    scanf(" %s %s",s1,s2);
    if(strcmp(s1,s2)) printf("1\n");
    else printf("%s\n",s1);
}
