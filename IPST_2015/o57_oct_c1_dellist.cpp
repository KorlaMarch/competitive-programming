#include "stdio.h"
#include "stdlib.h"
#include "unordered_map"
using namespace std;
typedef struct node{
    int o,v;
    struct node* next;
}node;
node* getNode(int o, int v){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->o = o;
    tmp->v = v;
    tmp->next = NULL;
    return tmp;
}
int k,m,l,i,j,x,y,t,v;
unordered_map<int,int> dellist;
node* fr[100005];
node* bk[100005];
void pushBack(node*& fr,node*& bk, int o, int v){
    if(fr==NULL){
        fr = bk = getNode(o,v);
    }else{
        bk->next = getNode(o,v);
        bk = bk->next;
    }
}
void pushFront(node*& fr,node*& bk, int o, int v){
    node* tmp;
    if(fr==NULL){
        fr = bk = getNode(o,v);
    }else{
        tmp = getNode(o,v);
        tmp->next = fr;
        fr = tmp;
    }
}
int main(){
    scanf("%d%d",&k,&m);
    for(i = 1; i <= k; i++){
        scanf("%d",&l);
        for(j = 0; j < l; j++){
            scanf("%d",&x);
            pushBack(fr[i],bk[i],0,x);
        }
    }
    for(i = 0; i < m; i++){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&x,&y);
            pushFront(fr[x],bk[x],1,y);
            pushBack(fr[x],bk[x],-1,y);
        }else{
            scanf("%d%d",&x,&y);
            bk[x]->next = fr[y];
            bk[x] = bk[y];
            fr[y] = bk[y] = NULL;
        }
    }
    for(i = 1; i <= k; i++){
        for(node* it = fr[i]; it != NULL; it = it->next){
            //printf(":%d %d\n",it->o,it->v);
            if(it->o == 0){
                if(!dellist.count(it->v)||dellist.find(it->v)->second<=0){
                    printf("%d\n",it->v);
                }
            }else if(it->o == 1){
                dellist[it->v]++;
            }else if(it->o == -1){
                dellist[it->v]--;
            }
        }
    }
}
