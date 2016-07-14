#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int v;
    struct node* next;
}node;
node* getNode(int v){
    node* n = (node*)malloc(sizeof(node));
    n->v = v;
    return n;
}
node* adjL[300000];
node* t;
int dis[300000];
int n,i,u,v,m,mx;
int main(){
    scanf("%d",&n);
    for(i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        if(u<v){
            t = getNode(v-1);
            t->next = adjL[u-1];
            adjL[u-1] = t;
        }else{
            t = getNode(u-1);
            t->next = adjL[v-1];
            adjL[v-1] = t;
        }
    }

    for(i=n-1,mx=0; i>=0; i--){
        for(t=adjL[i],m=0; t != NULL; t=t->next){
            if(dis[t->v]>m) m = dis[t->v];
        }
        dis[i] = 1+m;
        if(dis[i]>mx) mx = dis[i];
    }
    printf("%d\n", mx);
}
