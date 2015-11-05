#include "stdio.h"
#include "stdlib.h"
typedef struct{
    int w,v;
}item;
int n,m,i,p,w,v;
char c;
item it[100001];
void swap(int a, int b){
    item t = it[a];
    it[a] = it[b];
    it[b] = t;
}
void rhup(int k){
    if(k&&it[k].w<it[(k-1)/2].w){
        swap(k,(k-1)/2);
        rhup((k-1)/2);
    }
}
void rhdown(int k){
    if(k*2+1<p&&(k*2+2>=p||it[k*2+1].w<it[k*2+2].w)){
        if(it[k].w>it[k*2+1].w){
            swap(k,k*2+1);
            rhdown(k*2+1);
        }
    }else if(k*2+2<p){
        if(it[k].w>it[k*2+2].w){
            swap(k,k*2+2);
            rhdown(k*2+2);
        }
    }
}
void push(int w, int v){
    it[p].w = w;
    it[p].v = v;
    rhup(p++);
}
int pop(){
    int v = it[0].v;
    if(p<=0) return 0;
    it[0] = it[--p];
    rhdown(0);
    return v;
}
int main(){
    scanf("%d%d",&n,&m);
    n += m;
    for(i = 0; i < n; i++){
        scanf(" %c",&c);
        if(c=='T'){
            scanf("%d%d",&w,&v);
            push(w,v);
        }else{
            printf("%d\n",pop());
        }
    }
}
