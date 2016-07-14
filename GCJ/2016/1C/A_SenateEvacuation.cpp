#include "stdio.h"
#include "queue"
#include "algorithm"

int t,k,n,sum,i;
int p[30];
std::priority_queue<std::pair<int,char>> qu;
std::pair<int,int> pi,pi2;
int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d",&p[i]);
            sum += p[i];
            qu.push({p[i],'A'+i});
        }
        printf("Case #%d:",k);
        while(!qu.empty()&&sum>0){
            pi = qu.top();
            qu.pop();
            if(pi.first-1<=(sum-1)/2&&(qu.empty()||qu.top().first<=(sum-1)/2)){
                //eva 1
                printf(" %c", pi.second);
                pi.first--;
                if(pi.first){
                    qu.push(pi);
                }
                sum--;
            }else{
                //eva 2
                if(pi.first>1&&(qu.empty()||qu.top().first<=(sum-2)/2)){
                    printf(" %c%c",pi.second,pi.second);
                    pi.first -= 2;
                    if(pi.first){
                        qu.push(pi);
                    }
                }else{
                    pi2 = qu.top();
                    qu.pop();
                    printf(" %c%c",pi.second,pi2.second);
                    pi.first--;
                    pi2.first--;
                    if(pi.first) qu.push(pi);
                    if(pi2.first) qu.push(pi2);
                }

                sum -= 2;
            }
        }
        printf("\n");
    }
}
