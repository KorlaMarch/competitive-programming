#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int v;
    struct node *p1,*p2;
}node;
node* getNode(int v){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = v;
    tmp->p1 = NULL;
    tmp->p2 = NULL;
    return tmp;
}
node* ptr[200100];
node *next,*bot;
int n,l,i,j,k,m,x ;
char c;

int main(){
    scanf("%d%d",&l,&n);
    for(i=0,k=1; i < l; i++){
        scanf("%d",&m);
        for(j = 0; j < m; j++,k++){
            ptr[k] = getNode(k);
            if(j){
                ptr[k]->p1 = ptr[k-1];
                ptr[k-1]->p2 = ptr[k];
            }
        }
    }
    for(i=0,bot=ptr[1],next=ptr[1]->p2; i < n; i++){
        scanf(" %c",&c);
        if(c=='F'){
            if(next!=NULL){
                if(bot == next->p1){
                    bot = next;
                    next = bot->p2;
                }else{
                    bot = next;
                    next = bot->p1;
                }
            }
        }else if(c=='B'){
            if(bot->p1==next&&bot->p2){
                next = bot;
                bot = bot->p2;
            }else if(bot->p1!=next&&bot->p1){
                next = bot;
                bot = bot->p1;
            }
        }else{
            scanf("%d",&x);
            if(bot->p1==next){
                if(next){
                    if(next->p1 == bot) next->p1 = NULL;
                    else next->p2 = NULL;
                }
                bot->p1 = ptr[x];
                next = bot->p1;
            }else{
                if(next){
                    if(next->p1 == bot) next->p1 = NULL;
                    else next->p2 = NULL;
                }
                bot->p2 = ptr[x];
                next = bot->p2;
            }
            if(next->p1) next->p2 = bot;
            else next->p1 = bot;

            if(bot == next->p1){
                bot = next;
                next = bot->p2;
            }else{
                bot = next;
                next = bot->p1;
            }
        }
        printf("%d\n",bot->v);
    }
}
