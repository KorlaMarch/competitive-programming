#include "stdio.h"
char getD(char c){
    switch(c){
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    }
}
int main(){
    char s[100001],c;
    int st,q,i;
    scanf("%d ",&q);
    for(i = 0; i < q; i++){
        st = 0;
        while((c=getchar())!='\n'){
            switch(c){
            case '(':
            case '[':
            case '{':
                s[st++] = c;
                break;
            case ')':
            case ']':
            case '}':
                c = getD(c);
                if(st<=0||s[st-1]!=c){
                    st=1;
                    scanf("%s", s);
                    break;
                }else{
                    st--;
                }
            }
        }

        if(st){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
}
