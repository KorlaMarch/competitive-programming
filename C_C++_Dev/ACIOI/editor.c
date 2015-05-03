#include "stdio.h"

typedef struct node{
    char s[11];
    struct node* next;
    struct node* prev;
}node;

node *p,*t;

int main(){
    int n,i;
    char c;
    p = (node*)malloc(sizeof(node));
    p->next = p->prev = NULL;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %c",&c);
        switch(c){
        case 'i':
            t = (node*)malloc(sizeof(node));
            scanf(" %s", t->s);
            t->next = p->next;
            t->prev = p;
            p->next = t;
            if(t->next != NULL) t->next->prev = t;
            p = t;
            break;
        case 'r':
            if(p->next != NULL) p = p->next;
            break;
        case 'l':
            if(p->prev != NULL) p = p->prev;
            break;
        case 'd':
            if(p->next == NULL) break;
            p = p->next;
        case 'b':
            if(p->prev != NULL){
                t = p;
                p->prev->next = p->next;
                if(t->next != NULL) p->next->prev = p->prev;
                p = p->prev;
                free(t);
            }
            break;
        }
    }
    while(p->prev != NULL) p = p->prev;
    for(p = p->next; p != NULL; p = p->next){
        printf("%s ", p->s);
    }
}
