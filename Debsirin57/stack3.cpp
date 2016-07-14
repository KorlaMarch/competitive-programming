#include "stdio.h"
#include "stdlib.h"

struct node{
    float data;
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

void push(stackptr s, float data){
    NODEPTR p = getnode();
    p->data = data;
    p->next = s->head;
    s->head = p;
    s->size++;
}

float pop(stackptr s){
    if(s->size <= 0){
        return -1;
    }else{
        NODEPTR p = s->head;
        float i = p->data;
        s->head = p->next;
        free(p);
        s->size--;
        return i;
    }
}

float top(stackptr s){
    return s->size > 0 ? s->head->data : -1;
}

void print_list(NODEPTR head){
    NODEPTR q;
    if(head != NULL){
        for(q = head; q != NULL; q = q->next){
            printf("%.3f ", q->data);
        }
    }else{
        printf("NULL");
    }
    printf("\n");
}

float oper(float a, float b, char opera){
    switch(opera){
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return (float)a / b;
    }
    return 0;
}

int main(){
    stackptr s = createStack();
    char postfix[1000];
    int n;
    float a, b;
    gets(postfix);
    //printf("%s\n", postfix);
    for(int i = 0; postfix[i] != '\0'; i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            //start atoi
            n = 0;
            for(; postfix[i] >= '0' && postfix[i] <= '9'; i++){
                n *= 10;
                n += postfix[i] - '0';
            }
            push(s, (float)n);
            i--;
        }else{
            switch(postfix[i]){
            case '+':
            case '-':
            case '*':
            case '/':
                b = pop(s);
                a = pop(s);
                push(s, oper(a, b, postfix[i]));
                break;
            }
        }
        //print_list(s->head);
    }
    printf("%.3f\n", pop(s));
}
