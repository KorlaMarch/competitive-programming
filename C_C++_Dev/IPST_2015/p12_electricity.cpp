#include "stdio.h"
#include "queue"
#include "vector"

int n,k,i,j;
int p[500001];
std::priority_queue<int,std::vector<int>,std::greater<int>> mlist,dellist;
int main(){
    scanf("%d%d%d",&n,&k,&p[0]);
    mlist.push(p[0]);
    for(i = 1; i < n; i++){
        scanf("%d",&p[i]);
        if(i-k-1>=0){
            dellist.push(p[i-k-1]);
        }
        while(!dellist.empty()&&mlist.top()==dellist.top()){
            mlist.pop();
            dellist.pop();
        }
        p[i] += mlist.top();
        mlist.push(p[i]);
    }
    printf("%d\n",p[n-1]);
}
