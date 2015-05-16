#include "stdio.h"
#include "vector"
#include "set"
#include "queue"
#include "utility"

typedef struct{
    int d,n;
    char eo;
}node;
typedef struct{
    bool operator()(node a, node b){
        return a.d>b.d?true:false;
    }
}cmp;
int n,m,a,b,c,i,j,x;
int adj[1000][1000],sPath[2][1000];
std::pair<int,int> inp[5000];
char isV[2][1000];
char eo;
node t,t2;
std::priority_queue<node,std::vector<node>,cmp> qu;
std::set<std::pair<int,int> > path;
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d %d %d",&a, &b, &c);
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
        inp[i] = std::make_pair(a-1,b-1);
    }
    t.d = t.eo = t.n = 0;
    qu.push(t);
    while(!qu.empty()){
        t = qu.top();
        //printf("%d %d %d\n",t.d,t.n,t.eo);
        qu.pop();
        if(t.n==n-1&&t.eo==1){
            break;
        }else if(!isV[t.eo][t.n]){
            isV[t.eo][t.n] = 1;
            for(i = 0; i < n; i++){
                x = sPath[t.eo][t.n]+adj[t.n][i];
                //printf("I:%d = %d %d\n",sPath[(t.eo+1)%2][i],x);
                if(adj[t.n][i]&&!isV[(t.eo+1)%2][i]&&(sPath[(t.eo+1)%2][i]==0||x<sPath[(t.eo+1)%2][i])){
                    //printf("IN\d");
                    sPath[(t.eo+1)%2][i] = x;
                    t2.d = x;
                    t2.n = i;
                    t2.eo = (t.eo+1)%2;
                    qu.push(t2);
                }
            }
        }
    }
    for(i=n-1,eo=1;i>0;eo=(eo+1)%2){
        //printf("i=%d\n",i);
        for(j = 0; j < n; j++){
            //printf("%d %d %d\n",adj[i][j],sPath[(eo+1)%2][j],sPath[eo][i]-adj[i][j]);
            if(adj[i][j]&&sPath[(eo+1)%2][j]==sPath[eo][i]-adj[i][j]){
                //printf("\tADD: %d %d\n",i,j);
                path.insert(std::make_pair(i,j));
                break;
            }
        }
        i = j;
    }
    for(i = 0;i < m&&path.size(); i++){
        path.erase(inp[i]);
        x = inp[i].first;
        inp[i].first = inp[i].second;
        inp[i].second = x;
        path.erase(inp[i]);
        //printf("REMOVE: %d %d S:%d\n",inp[i].first,inp[i].second,path.size());
    }
    printf("%d %d\n",i,sPath[1][n-1]);
}
