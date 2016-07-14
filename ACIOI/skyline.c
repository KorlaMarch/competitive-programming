#include "stdio.h"

typedef struct node{
    int pi,hi;
    struct node* next;
}node;
node* new_node(int pi, int hi){
    node* n = (node*)malloc(typedef(node));
    n->hi = hi;
    n->pi = pi;
    return n;
}
int main(){
    int n,li,hi,ri,i;
    node* t;
    node* root = new_node(0,0);
    root->next = NULL;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d", &li,&hi,&ri);
        for(t=root; t->next != NULL && t->next->pi <= li; )
    }
}
