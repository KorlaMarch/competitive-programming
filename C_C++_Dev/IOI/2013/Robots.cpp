#include "stdio.h"
#include "algorithm"
#include "queue"

int a,b,t,i,j,p,q,m;
int x[100005],y[100005];
std::pair<int,int> toy[1000005];
std::priority_queue<int> qu;

bool canFit(int lm){
    int i,j,k;
    while(!qu.empty()) qu.pop();
    for(i=j=0; i < a; i++){
        for(;j<t&&toy[j].first<x[i];j++){
            qu.push(toy[j].second);
        }
        for(k = 0; !qu.empty() && k < lm; k++){
            qu.pop();
        }
    }
    for(; j < t; j++){
        qu.push(toy[j].second);
    }
    for(i = b-1; i >= 0; i--){
        for(k = 0; !qu.empty() && k < lm && qu.top() < y[i]; k++){
            qu.pop();
        }
    }
    //printf("Can fit %d : %d\n",lm,qu.empty());
    return qu.empty();
}

int main(){
    scanf("%d%d%d",&a,&b,&t);
    for(i = 0; i < a; i++){
        scanf("%d",&x[i]);
    }
    for(i = 0; i < b; i++){
        scanf("%d",&y[i]);
    }
    std::sort(x,x+a);
    std::sort(y,y+b);
    for(i = 0; i < t; i++){
        scanf("%d%d",&toy[i].first,&toy[i].second);
    }
    std::sort(toy,toy+t);
    p=0,q=t+1;
    while(p<=q){
        m = (p+q)/2;
        //printf("::%d %d %d\n",p,m,q);
        if(canFit(m)){
            q = m-1;
        }else{
            p = m+1;
        }
    }
    //printf("%d %d",p,q);
    if(q==t+1) printf("-1\n");
    else printf("%d\n",q+1);
}
