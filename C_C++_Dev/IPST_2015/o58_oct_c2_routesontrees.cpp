#include "stdio.h"
#include "algorithm"
#include "vector"
#include "queue"
#define fi first
#define se second
#define INF 2147483640
using namespace std;
struct node{
    int k,v,d;
    bool operator()(node a, node b){
        return a.d==b.d?a.k>=b.k:a.d>b.d;
    }
};
node getNode(int v, int k, int d){
    node tmp;
    //printf("PU %d %d %d\n",v,k,d);
    tmp.k = k;
    tmp.d = d;
    tmp.v = v;
    return tmp;
}
int n,m,k,ui,vi,hi,i,j;
bool isTM;
node t;
priority_queue<node,vector<node>,node> qu;
vector<pair<int,int>> edge[100001];
int d[10][100001];
void upD(int i, int j, int v){
    //printf("UDD %d %d %d\n",i,j,v);
    for(;j<=k; j++){
        if(v<d[j][i]) d[j][i] = v;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&ui,&vi,&hi);
        edge[ui].push_back(make_pair(vi,hi));
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= k; j++){
            d[j][i] = INF;
        }
    }
    upD(1,0,0);
    isTM = false;
    qu.push(getNode(1,0,0));
    while(!qu.empty()){
        t = qu.top();
        //printf("GET %d %d %d\n",t.v,t.k,t.d);
        qu.pop();
        if(t.v==n){
            printf("%d\n",t.d);
            isTM = true;
            break;
        }
        for(vector<pair<int,int>>::iterator it = edge[t.v].begin(); it != edge[t.v].end(); ++it){
            if(it->se<-100){
                if(t.k+1<=k&&t.d<d[t.k+1][it->fi]){
                    upD(it->fi,t.k+1,t.d);
                    qu.push(getNode(it->fi,t.k+1,t.d));
                }
            }else{
                if(it->se > 0){
                    if(t.d+it->se<d[t.k][it->fi]){
                        upD(it->fi,t.k,t.d+it->se);
                        qu.push(getNode(it->fi,t.k,t.d+it->se));
                    }
                }else{
                    //printf("IN %d %d\n",t.d,d[t.k][it->fi]);
                    if(t.d<d[t.k][it->fi]){
                        upD(it->fi,t.k,t.d);
                        qu.push(getNode(it->fi,t.k,t.d));
                    }
                }
            }
        }
    }
    if(!isTM){
        printf("-1\n");
    }
}
