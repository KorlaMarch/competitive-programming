#include "stdio.h"
#include "queue"

int main(){
    int t,i,n,k,x;
    int hi[2];
    std::priority_queue<int> qu;
    for(scanf("%d",&t);t>0;t--){
        scanf("%d%d",&n,&k);
        for(i=hi[1]=0; i < n; i++){
            scanf("%d",hi+i%2);
            if((hi[i%2]-hi[(i+1)%2])>0) qu.push(hi[i%2]-hi[(i+1)%2]);
        }
        for(i = 0; i < k && !qu.empty(); i++){
            qu.pop();
        }
        if(qu.empty()){
            printf("0\n");
        }else{
            printf("%d\n",qu.top());
            while(!qu.empty()) qu.pop();
        }
    }
}
