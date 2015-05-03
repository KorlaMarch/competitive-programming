#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *next;
};

typedef struct node *NODEPTR;

struct stack{
    NODEPTR head;
    int size;
};

typedef struct stack *stackptr;

NODEPTR getnode(){
    return (NODEPTR)malloc(sizeof(struct node));
}

stackptr createStack(){
    stackptr s = (stackptr)malloc(sizeof(struct stack));
    s->head = NULL;
    s->size = 0;
}

void push(stackptr s, int data){
    NODEPTR p = getnode();
    p->data = data;
    p->next = s->head;
    s->head = p;
    s->size++;
}

int pop(stackptr s){
    if(s->size <= 0){
        return -1;
    }else{
        NODEPTR p = s->head;
        int i = p->data;
        s->head = p->next;
        free(p);
        s->size--;
        return i;
    }
}

int top(stackptr s){
    return s->size > 0 ? s->head->data : -1;
}

int print_list(NODEPTR head){
    NODEPTR q;
    if(head != NULL){
        for(q = head; q != NULL; q = q->next){
            printf("%d ", q->data);
        }
    }else{
        printf("NULL");
    }
    printf("\n");
}

int getPower(char c){
    switch(c){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
    default:
        return -1;
    }
}

int main(){
    stackptr s = createStack();
    char infix[1000];
    int n;
    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++){
        if(infix[i] >= '0' && infix[i] <= '9'){
            //start atoi
            n = 0;
            for(; infix[i] >= '0' && infix[i] <= '9'; i++){
                n *= 10;
                n += infix[i] - '0';
            }
            printf("%d ", n);
            i--;
        }else{
            switch(infix[i]){
            case '+':
            case '-':
            case '*':
            case '/':
                while(getPower(top(s)) >= getPower(infix[i])){
                    printf("%c ", pop(s));
                }
                push(s, infix[i]);
                break;
            case '(':
                push(s, infix[i]);
                break;
            case ')':
                while(top(s) != '('){
                    printf("%c ", pop(s));
                }
                pop(s);
                break;
            }
        }
    }
    while(s->size > 0){
        printf("%c ", pop(s));
    }
}
