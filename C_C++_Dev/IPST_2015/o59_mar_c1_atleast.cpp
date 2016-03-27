#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"

int n,m,i,j,s,t,mx;
int x[100005];
double sum,u,av;
std::priority_queue<int,std::vector<int>,std::greater<int> > qu;

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&x[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d%d %lf",&s,&t,&u);
        while(!qu.empty()) qu.pop();
        sum = mx = 0;
        for(j = s-1; j < t; j++){
            qu.push(x[j]);
            sum += x[j];
            if(x[j]>mx) mx = x[j];
        }
        if(mx<u) printf("-1\n");
        else{
            //printf("AV = %d %d %.6f %.6f\n",sum,qu.size(),sum/(double)qu.size(),u);
            while(qu.size()>1&&sum/qu.size()<u){
                sum -= qu.top();
                qu.pop();
                //printf("AV = %d %d %.6f\n",sum,qu.size(),sum/(double)qu.size());
            }
            printf("%d\n",(t-s+1)-qu.size());
        }
    }
}
