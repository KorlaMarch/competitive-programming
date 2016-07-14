#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"
using namespace std;

struct node{
    int w,u,v;
    bool operator()(node a, node b){
        return a.w==b.w?a.u>b.u:a.w>b.w;
    }
    node(int _w = 0, int _u = 0, int _v = 0){
        w = _w;
        u = _u;
        v = _v;
    }
};

int n,k,i,j,c;
int s[100005];
bool isV[100005];
priority_queue<node,vector<node>,node> qu;
node t;
int main(){
    scanf("%d%d",&n,&k);
    for(i = 1; i <= n; i++){
        scanf("%d",&s[i]);
        if(i!=1){
            qu.push(node(s[i]-s[i-1],i-1,i));
        }
    }
    isV[0] = isV[n+1] = true;
    for(i = 0; !qu.empty() && i < k;){
        t = qu.top();
        //printf("%d %d %d\n",t.u,t.v,t.w);
        qu.pop();
        if(isV[t.u]||isV[t.v]){
            continue;
        }
        c += t.w;
        isV[t.u] = isV[t.v] = true;
        qu.push(node((s[t.u]-s[t.u-1])+(s[t.v+1]-s[t.v])-t.w,t.u-1,t.v+1));
        i++;
    }
    if(qu.empty()) printf("ERROR\n");
    printf("%d\n",c);
}
