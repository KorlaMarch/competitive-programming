#include "stdio.h"
#include "string.h"

char s[100005],c[300];
int i,j,len,t;

int main(){
    scanf(" %s %s",s,c);
    len = strlen(c);
    if(strlen(s)<len){
        printf("0\n");
    }else{
        for(i = 0; s[i+len-1]!='\0'; i++){
            for(j = 0; j < len; j++){
                if(s[i+j]!=c[j]) break;
            }
            if(j==len){
                t++;
                s[i+len-1] = '#';
            }
        }
        printf("%d\n",t);
    }
}
