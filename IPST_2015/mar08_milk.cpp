#include "stdio.h"

int n,q,i,x,y;
int p[100005];
char c;

int unionF(int x){
    return x==p[x]?x:(p[x]=unionF(p[x]));
}

int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i <= n; i++){
        p[i] = i;
    }
    for(i = 0; i < q; i++){
        scanf(" %c %d %d",&c,&x,&y);
        if(c=='c'){
            p[unionF(x)] = unionF(y);
        }else{
            if(unionF(x)==unionF(y)) printf("yes\n");
            else printf("no\n");
        }
    }
}
