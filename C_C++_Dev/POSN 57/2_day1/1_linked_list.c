#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int v;
    struct node* next;
    struct node* prev;
}node;

node* insert_order(node* h, int x){
    node *p,*t;
    if(h == NULL){
        h = (node*)malloc(sizeof(node));
        h->v = x;
        h->prev = h->next = NULL;
    }else if(x <= h->v){
        t = (node*)malloc(sizeof(node));
        t->v = x;
        t->next = h;
        h->prev = t;
        h = t;
    }else{
        for(p=h; p->next && p->next->v < x; p = p->next);
        t = (node*)malloc(sizeof(node));
        t->v = x;
        t->next = p->next;
        t->prev = p;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
    return h;
}

node* del(node* h, int n){
    node *t,*p;
    if(h->v == n){
        t = h;
        h = h->next;
        if(h) h->prev = NULL;
        free(t);
    }else{
        for(p=h;p->next && p->next->v != n; p = p->next);
        if(p->next){
            if(p->next->next) p->next->next->prev = p;
            t = p->next;
            p->next = p->next->next;
            free(t);
        }
    }
    return h;
}
void print_list(node* t){
    for(; t; t = t->next){
        printf("%d ", t->v);
    }
    printf("\n");
}
int main(){
    int n,i,x;
    node *head = NULL,*t;
    printf("How many values? "); scanf("%d",&n);
    for(i = 0; i < n; i++){
        printf("Value: "); scanf("%d", &x);
        head = insert_order(head,x);
    }
    printf("Sorted list: ");
    print_list(head);
    printf("Enter Number to delete\n");
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        head = del(head,x);
        printf("Left: "); print_list(head);
    }
}
