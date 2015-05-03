#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    char c;
    struct node* next;
    struct node* prev;
}node;
node* getNode(char c,node* prev){
    node* n = (node*)malloc(sizeof(node));
    n->c = c;
    n->next = NULL;
    n->prev = prev;
}
int main(){
    int n,i;
    char c;
    char s[100002];
    node* root = getNode('\0',NULL);
    node* tmp = root;
    node* tn;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %c", &c);
        tmp->next = getNode(c,tmp);
        tmp = tmp->next;
    }
    for(tmp=root; tmp; tmp = tmp->next){
        while(tmp->next&&tmp->next->next&&tmp->next->c == tmp->next->next->c){
            tn = tmp->next;
            tmp->next = tmp->next->next->next;
            if(tmp->next) tmp->next->prev = tmp;
            free(tn->next);
            free(tn);
            n -= 2;
            if(tmp->prev) tmp=tmp->prev;
        }
    }
    printf("%d\n", n);
    if(n){
        s[n] = '\0';
        for(tmp=root->next, i = n-1; tmp; tmp = tmp->next, i--){
            s[i] = tmp->c;
        }
        printf("%s\n", s);
    }else{
        printf("empty\n");
    }
}
