#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"

struct con{
    int a,b,c,d;
    con(int x = 0, int y = 0){
        a = x%101;
        b = x/101;
        c = y%101;
        d = y/101;
    }
};

int getnm(int x,int y){
    return x+101*y;
}

int n,m,i,j,d,w;
char mp[110][310];
std::vector<con> cv;
std::vector<int> edge[100001];
std::priority_queue<std::pair<int,int>> qu;
std::pair<int,int> pi;
int p[100001];

int unionF(int x){
    return x==p[x]?x:(p[x]=unionF(p[x]));
}

int calDeg(int x){
    int c = 0;
    for(int y : edge[x]){
        if(unionF(x)!=unionF(y)) c++;
    }
    return c;
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        scanf(" %s",mp[i]+1);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(mp[i][j]=='.'){
                if(mp[i-1][j]=='.'){
                    edge[getnm(i,j)].push_back(getnm(i-1,j));
                }
                if(mp[i+1][j]=='.'){
                    edge[getnm(i,j)].push_back(getnm(i+1,j));
                }
                if(mp[i][j-1]=='.'){
                    edge[getnm(i,j)].push_back(getnm(i,j-1));
                }
                if(mp[i][j+1]=='.'){
                    edge[getnm(i,j)].push_back(getnm(i,j+1));
                }
            }
        }
    }
    for(i = 0; i <= getnm(n,m); i++){
        if(!edge[i].empty()) qu.push({edge[i].size(),i});
        p[i] = i;
    }
    w = 0;
    while(!qu.empty()){
        pi = qu.top();
        qu.pop();
        d = calDeg(pi.second);
        /*if(w < 100){
            printf("GET %d : %d %d\n",pi.first,pi.second,d);
            w++;
        }*/
        if(pi.first!=d){
            qu.push({d,pi.second});
        }else{
            for(int y : edge[pi.second]){
                if(unionF(pi.second)!=unionF(y)){
                    cv.push_back(con(pi.second,y));
                    p[unionF(pi.second)] = unionF(y);
                }
            }
        }
    }
    printf("%d\n",cv.size());
    for(con c : cv){
        printf("%d %d %d %d\n",c.a,c.b,c.c,c.d);
    }
}
