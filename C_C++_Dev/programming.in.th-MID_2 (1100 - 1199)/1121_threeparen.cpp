#include "stdio.h"
#include "stdlib.h"

struct st{
    char array[100000];
    int top;
};

typedef struct st* stack;

void push(stack s, char c){
    s->array[s->top] = c;
    s->top++;
}

char top(stack s){
    if(s->top > 0){
        return s->array[s->top - 1];
    }else{
        return '\0';
    }
}

int main(){
    int n;
    char c;
    int isError;
    stack s = (stack)malloc(sizeof(struct st));
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        isError = 0;
        s->top = 0;
        while((c = getchar()) != '\n'){
            if(!isError)
            switch(c){
            case '(':
            case '[':
            case '{':
                push(s, c);
                break;
            case ')':
                if(top(s) == '('){
                    s->top--;
                }else{
                    isError = 1;
                }
                break;
            case ']':
                if(top(s) == '['){
                    s->top--;
                }else{
                    isError = 1;
                }
                break;
            case '}':
                if(top(s) == '{'){
                    s->top--;
                }else{
                    isError = 1;
                }
                break;
            }
        }
        if(isError || s->top != 0){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    return 0;
}
