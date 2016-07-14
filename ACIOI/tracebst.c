#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int num;
    struct node* l;
    struct node* r;
}node;

node* newNode(int i){
    node* n;
    n = (node*)malloc(sizeof(node));
    n->num = i;
    n->l = n->r = NULL;
    return n;
}
int c=1;
int order[100001];
void infix(node* p){
    if(p->l != NULL) infix(p->l);
    order[p->num] = c++;
    if(p->r != NULL) infix(p->r);
}
int main(){
    int n,i,j;
    char s[100001];
    node *r,*p;
    scanf("%d *",&n);
    r = newNode(0);
    for(i=1; i<n; i++){
        scanf(" %s", s);
        p = r;
        for(j=0; s[j+1] != '*'; j++){
            if(s[j] == 'R') p = p->r;
            else p = p->l;
        }
        if(s[j] == 'R') p->r = newNode(i);
        else p->l = newNode(i);
    }
    infix(r);
    for(i=0;i<n;i++){
        printf("%d\n", order[i]);
    }
    return 0;
}
