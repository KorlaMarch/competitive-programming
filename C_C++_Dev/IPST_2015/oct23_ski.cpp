#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
int n,np,k,m,i,j,p1,p2,q1,q2,r,b,s,minS;
vector<pii> edge[1002];
queue<pii> qu;
pii t;
bool isB[1002];
bool canS[1002][2002];
int main(){
    scanf("%d%d %d",&n,&np,&k);
    for(i = 0; i < k; i++){
        scanf("%d%d",&p1,&p2);
        edge[p1].push_back(make_pair(p2,0));
    }
    for(i = 1; i <= np; i++) isB[i] = true;
    for(i = 1; i < n; i++){
        if(isB[i]){
            for(vector<pii>::iterator it = edge[i].begin(); it != edge[i].end(); ++it){
                isB[j] = true;
            }
        }
    }
    scanf("%d",&m);
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&q1,&q2,&r);
        edge[q1].push_back(make_pair(q2,r));
    }
    scanf("%d%d",&b,&s);
    qu.push(make_pair(b,s));
    minS = 1000000000;
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        for(vector<pii>::iterator it = edge[t.x].begin(); it != edge[t.x].end(); ++it){
            if(t.y>=it->y&&!canS[it->x][t.y-it->y]){
                canS[it->x][t.y-it->y] = true;
                if(isB[it->x]&&t.y-it->y<minS) minS = t.y-it->y;
                qu.push(make_pair(it->x,t.y-it->y));
            }
        }
    }
    printf("%d\n",minS);
}
