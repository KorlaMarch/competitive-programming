#include "stdio.h"
#include "algorithm"
int n,q,i,pt,j;
int cm[100000];
int a[100001],b[100001],fen[200500],tp[200501];

void add(int p, int v){
    for(p++;p<=pt;p+=(p&-p)) fen[p] += v;
}
int getV(int p){
    int v = 0;
    for(p++;p>0;p-=(p&-p)) v += fen[p];
    return v;
}

int main(){
    scanf("%d%d",&n,&q);
    for(i=pt=0; i < q; i++){
        scanf("%d",cm+i);
        if(cm[i]){
            scanf("%d%d",a+i,b+i);
            tp[pt++] = a[i];
            tp[pt++] = b[i]+1;
        }else{
            scanf("%d",a+i);
            tp[pt++] = a[i];
        }
    }
    std::sort(tp,tp+pt);
    for(i = 0; i < q; i++){
        if(cm[i]){
            add(std::lower_bound(tp,tp+pt,a[i])-tp,1);
            add(std::lower_bound(tp,tp+pt,b[i]+1)-tp,-1);
        }else{
            switch(getV(std::lower_bound(tp,tp+pt,a[i])-tp)%6){
                case 0: printf("sleep\n"); break;
                case 1: case 3: case 5: printf("eat\n"); break;
                case 2: case 4: printf("work\n"); break;
            }
        }
    }
}
