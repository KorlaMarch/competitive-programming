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

char getPair(char c){
    switch(c){
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    }
    return 0;
}

int main(){
    char str[1000];
    stackptr s = createStack();

    scanf("%s", &str);
    for(int i = 0; str[i] != '\0'; i++){
        switch(str[i]){
        case '(':
        case '[':
        case '{':
            push(s, str[i]);
            break;
        case ')':
        case ']':
        case '}':
            if(top(s) == getPair(str[i])){
                pop(s);
            }else{
                printf("NO\n");
                return 0;
            }
            break;
        }
        //print_list(s->head);
    }

    printf("%s\n", s->size <= 0 ? "YES" : "NO");
}
