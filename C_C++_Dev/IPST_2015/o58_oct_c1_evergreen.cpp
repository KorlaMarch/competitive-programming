#include "stdio.h"
#include "queue"
#include "algorithm"
int n,t,i,mn,mx;
long long k,sum,cu;
int xi[1005];
char isG[1000205];
std::queue<int> qu[2];
int main(){
    scanf("%d %lld",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d",&xi[i]);
        if(!isG[xi[i]]){
            qu[0].push(xi[i]);
            isG[xi[i]] = 1;
            if(!i||xi[i]<mn) mn = xi[i];
            if(!i||xi[i]>mx) mx = xi[i];
            cu++;
            sum++;
        }
    }
    for(i = 0; !qu[i%2].empty()&&sum<k; i++){
        cu += 2;
        while(!qu[i%2].empty()){
            t = qu[i%2].front();
            qu[i%2].pop();
            if(!isG[t+1]&&t+1<mx){
                qu[(i+1)%2].push(t+1);
                isG[t+1] = 1;
                cu++;
                //printf("PU %d\n",t+1);
            }
            if(!isG[t-1]&&t-1>mn){
                qu[(i+1)%2].push(t-1);
                isG[t-1] = 1;
                cu++;
                //printf("PU %d\n",t-1);
            }
        }
        //printf("%d:%lld %lld *\n",i,sum,cu);
        sum += cu;
    }
    for(; sum<k; i++){
        cu += 2;
        //printf("%d:%lld %lld\n",i,sum,cu);
        sum += cu;
    }
    printf("%d\n",i);
}
