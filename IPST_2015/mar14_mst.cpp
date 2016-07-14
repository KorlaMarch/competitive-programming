#include "stdio.h"
#include "queue"
#include "vector"
#include "algorithm"

struct tup{
    int u,v,i;
    double w;
    tup(int _u = 0, int _v = 0, double _w = 0.0, int _i = 0){
        u = _u;
        v = _v;
        w = _w;
        i = _i;
    }
    bool operator()(tup a, tup b){
        return a.w>b.w;
    }
};

std::priority_queue<tup,std::vector<tup>,tup> qu;
std::vector<int> ans;
int p[20005];
int n,m,i,j,u,v;
double w,sw;
tup t;

int unionF(int x){
    return x==p[x]?x:(p[x]=unionF(p[x]));
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d %lf",&u,&v,&w);
        qu.push(tup(u,v,w,i));
    }
    for(i = 1; i <= n; i++){
        p[i] = i;
    }
    while(!qu.empty()&&ans.size()<n-1){
        t = qu.top();
        qu.pop();
        if(unionF(t.u)!=unionF(t.v)){
            sw += t.w;
            ans.push_back(t.i);
            p[unionF(t.u)]=unionF(t.v);
        }
    }
    std::sort(ans.begin(),ans.end());
    printf("%.3f\n",sw);
    for(int x : ans){
        printf("%d\n",x);
    }
}
