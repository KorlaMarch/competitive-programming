#include "stdio.h"
#include "queue"

int main(){
    int t,k,d,i,m,pi;
    int p[2000];
    std::priority_queue<int> q;
    scanf("%d",&t);
    for(k=1;k<=t;k++){
        scanf("%d",&d);
        for(i = 0; i < d; i++){
            scanf("%d",&p[i]);
            q.push(p[i]);
        }
        for(i = 0,m=2000; i < m; i++){
            if(i+q.top()<m) m = i+q.top();
            pi = q.top();
            q.pop();
            if(pi-(pi/3*2)+1<pi-pi/2){
                q.push(pi/3);
                q.push(pi/3);
                q.push(pi-(pi/3*2));
                i++;
            }else{
                q.push(pi/2);
                q.push(pi-pi/2);
            }
        }
        while(!q.empty()) q.pop();
        for(i=0; i < d; i++) q.push(p[i]);
        for(i = 0; i < m; i++){
            if(i+q.top()<m) m = i+q.top();
            pi = q.top();
            q.pop();
            q.push(pi/2);
            q.push(pi-pi/2);
        }
        printf("Case #%d: %d\n", k,m);
        while(!q.empty()) q.pop();
    }
}
