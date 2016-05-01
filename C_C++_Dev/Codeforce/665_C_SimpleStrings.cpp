#include "stdio.h"

int i;
char s[200005];

int main(){
    scanf(" %s",s);
    for(i = 1; s[i]; i++){
        if(s[i-1]==s[i]){
            if(s[i-1]!='a'&&s[i+1]!='a'){
                s[i] = 'a';
            }else if(s[i-1]!='b'&&s[i+1]!='b'){
                s[i] = 'b';
            }else{
                s[i] = 'c';
            }
        }
    }
    printf("%s\n",s);
}
