#include "stdio.h"

int n,t;
int heap[100005];

void swap(int i, int j){
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}
void reheapUP(int p){
    if(p&&heap[p]>heap[(p-1)/2]){
        swap(p,(p-1)/2);
        reheapUP((p-1)/2);
    }
}

void reheapDown(int p){
    int s = p*2+2<t?heap[p*2+2]>heap[p*2+1]?p*2+2:p*2+1:p*2+1<t?p*2+1:0;
    if(s&&heap[p]<heap[s]){
        swap(s,p);
        reheapDown(s);
    }
}

int main(){
    int i,x,a;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d",&heap[t]);
        reheapUP(t++);
    }
    while(t>1){
        a=heap[0];
        heap[0] = heap[--t];
        reheapDown(0);
        x = ((a&heap[0])+(a|heap[0])+(a^heap[0]))/3;
        heap[0] = heap[--t];
        reheapDown(0);
        heap[t] = x;
        reheapUP(t++);
    }
    printf("%d\n", heap[0]);
}
