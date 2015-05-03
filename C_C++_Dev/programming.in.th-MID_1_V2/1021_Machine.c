#include "stdio.h"

int n,i,x,h;
int heap[400001];
char c;

void rhup(int p){
    int t;
    if(p&&heap[(p-1)/2]<heap[p]){
        t = heap[p];
        heap[p] = heap[(p-1)/2];
        heap[(p-1)/2] = t;
        rhup((p-1)/2);
    }
}

void rhdown(int p){
    int t,pt = p*2+2<h?(heap[p*2+1]>=heap[p*2+2]?p*2+1:p*2+2):p*2+1<h?p*2+1:0;
    if(pt && heap[pt]>heap[p]){
        t = heap[pt];
        heap[pt] = heap[p];
        heap[p] = t;
        rhdown(pt);
    }
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %c",&c);
        if(c == 'P'){
            scanf("%d", &x);
            heap[h++] = x;
            rhup(h-1);
        }else{
            if(h){
                printf("%d\n", heap[0]);
                heap[0] = heap[--h];
                rhdown(0);
            }else printf("-1\n");
        }
    }
}
