#include "stdio.h"

typedef struct{
    int w,v;
}node;

int n,m,l;
node heap[100002];

void swap(int i, int j){
    node t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}
void reheap_up(int p){
    if(p&&heap[p].w<heap[(p-1)/2].w){
        swap(p,(p-1)/2);
        reheap_up((p-1)/2);
    }
}
void reheap_down(int p){
    int s = p*2+2<l?(heap[p*2+2].w<heap[p*2+1].w?p*2+2:p*2+1):(p*2+1<l?p*2+1:0);
    if(s && heap[s].w<heap[p].w){
        swap(p,s);
        reheap_down(s);
    }
}

int main(){
    int i;
    node t;
    char c;
    scanf("%d%d", &n, &m);
    m +=n;
    for(i = 0; i < m; i++){
        scanf(" %c", &c);
        if(c == 'T'){
            scanf(" %d%d", &t.w, &t.v);
            heap[l++] = t;
            reheap_up(l-1);
        }else if(l){
            printf("%d\n",heap[0].v);
            heap[0] = heap[--l];
            reheap_down(0);
        }else{
            printf("0\n");
        }
    }
}
