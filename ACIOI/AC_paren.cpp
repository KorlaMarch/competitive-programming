#include "stdio.h"
#include "stack"

char getOppositeP(char c){
    switch(c){
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    case '>':
        return '<';
    default:
        return 0;
    }
}

int main(){
    std::stack<char> parenS;
    int n,i,j,t;
    char s[128];
    bool isCorrect;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf(" %s", s);
        isCorrect = true;
        for(j = 0; s[j] != '\0'; j++){
            t = getOppositeP(s[j]);
            if(!t){
                parenS.push(s[j]);
            }else{
                if(!parenS.empty() && parenS.top() == t){
                    parenS.pop();
                }else{
                    isCorrect = false;
                    break;
                }
            }
        }
        if(!parenS.empty()){
            isCorrect = false;
        }
        while(!parenS.empty()) parenS.pop();
        if(isCorrect){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
}
