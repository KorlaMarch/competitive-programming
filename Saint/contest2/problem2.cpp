#include "stdio.h"

int stp;
char st[10000];
char s[10000];
bool isError;

int main(){
    stp = 0;
    isError = false;

    printf("Enter string? ");
    scanf(" %s", s);
    for(int i = 0; s[i] && !isError; i++){
        switch(s[i]){
        case '(':
        case '[':
        case '{':
            st[stp++] = s[i];
            break;
        case ')':
            if(stp!=0&&st[stp-1]=='('){
                stp--;
            }else{
                isError = true;
            }
            break;
        case ']':
            if(stp!=0&&st[stp-1]=='['){
                stp--;
            }else{
                isError = true;
            }
            break;
        case '}':
            if(stp!=0&&st[stp-1]=='{'){
                stp--;
            }else{
                isError = true;
            }
            break;
        }
    }

    if(isError||stp!=0){
        printf("false");
    }else{
        printf("true");
    }

    return 0;

}
