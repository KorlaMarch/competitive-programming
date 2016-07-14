#include "stdio.h"

char getMatch(char c){
    switch(c){
        case '}': return '{';
        case ']': return '[';
        case ')': return '(';
        case '>': return '<';
    }
}

int main(){
    int n,i,j,top = 0;
    char s[200001];
    char s1[200001];
    char o;
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++){
        scanf(" %s", &s1);
        for(j=top=0,o=1; s1[j]; j++){
            if(o)
            switch(s1[j]){
            case '{': case '[': case '(': case '<':
                s[top] = s1[j];
                top++;
                break;
            case '}': case ']': case ')': case '>':
                if(top != 0 && s[top-1] == getMatch(s1[j])) top--;
                else o = 0;
            }
        }
        if(top)o=0;
        printf("%s\n",o?"YES":"NO");
    }
}
