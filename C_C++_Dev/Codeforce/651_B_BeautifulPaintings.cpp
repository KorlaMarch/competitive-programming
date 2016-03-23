#include "stdio.h"
#include "queue"

int n,i,c,a,l;
std::priority_queue<int> qu[2];

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        qu[0].push(a);
    }
    for(i = 0; !qu[i%2].empty(); i++){
        l = qu[i%2].top();
        qu[i%2].pop();
        while(!qu[i%2].empty()){
            if(l==qu[i%2].top()){
                qu[(i+1)%2].push(l);
                qu[i%2].pop();
            }else{
                c++;
                l = qu[i%2].top();
                qu[i%2].pop();
            }
        }
    }
    printf("%d\n",c);
}
