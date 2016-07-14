#include "stdio.h"
int strlen(char s[]){
    int i;
    for(i = 0; s[i]; i++);
    return i;
}
int main(){
    int k,i,j,x,y,len;
    char s[1001],t[1001];
    scanf("%d %s",&k,s);
    if(k == 1){
        printf("%s\n",s);
        return 0;
    }
    len = strlen(s);
    t[len] = '\0';
    for(i = k-1,j=0; i < len ; i += k+2*(k-2)){
        for(x=0; x < k && i < len;x++){
            t[i++] = s[j++];
        }
    }
    for(x = 1; x+1 < k; x++){
        for(i = k-x-1,y=0; i < len; i += k+1+(y%2?(x-1)*2:(k-x-2)*2)){
            t[i] = s[j++];
            y++;
        }
    }
    t[0] = s[j++];
    for(i = k+(k-1)*2-1; i < len ; i += k+2*(k-2)){
        for(x=0; x < k && i < len;x++){
            t[i++] = s[j++];
        }
    }
    for(i = 0; i < len; i++) putchar(t[i]);
}
