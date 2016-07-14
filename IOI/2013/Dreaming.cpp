#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

#define INF 2000000000

int n,m,l,i,j,a,b,c,d,mx,mnt;
std::vector<std::pair<int,int>> edge[100005];
std::priority_queue<int> dis;
int p[100005];
bool isV[100005];
int maxD[100005];
int unionF(int x){
    return x==p[x]?x:(p[x]=unionF(p[x]));
}

void dynU(int x, int o){
    maxD[x] = 0;
    for(auto pi : edge[x]){
        if(pi.first!=o){
            dynU(pi.first,x);
            maxD[x] = std::max(maxD[x],pi.second+maxD[pi.first]);
        }
    }
}

void dynD(int x, int o, int od){
    int fm,sm;
    mnt = std::min(mnt,std::max(maxD[x],od));
    if(od>=maxD[x]){
        for(auto pi : edge[x]){
            if(pi.first!=o){
                dynD(pi.first,x,od+pi.second);
            }
        }
        mx = std::max(mx,od+maxD[x]);
    }else{
        fm = od;
        sm = 0;
        for(auto pi : edge[x]){
            if(pi.first!=o){
                if(pi.second+maxD[pi.first]>=fm){
                    sm = fm;
                    fm = pi.second+maxD[pi.first];
                }else if(pi.second+maxD[pi.first]>sm){
                    sm = pi.second+maxD[pi.first];
                }
            }
        }
        mx = std::max(mx,fm+sm);
        for(auto pi : edge[x]){
            if(pi.first!=o){
                if(pi.second+maxD[pi.first]==fm){
                    dynD(pi.first,x,sm+pi.second);
                }else{
                    dynD(pi.first,x,fm+pi.second);
                }
            }
        }
    }
}

void findMD(int x){
    mnt = INF;
    dynU(x,-1);
    dynD(x,-1,0);
    dis.push(mnt);
}

int main(){
    scanf("%d%d%d",&n,&m,&l);
    for(i = 0; i < n; i++){
        p[i] = i;
    }
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&a,&b,&d);
        edge[a].push_back({b,d});
        edge[b].push_back({a,d});
        p[unionF(b)] = unionF(a);
    }
    for(i = 0; i < n; i++){
        if(!isV[unionF(i)]){
            isV[unionF(i)] = true;
            findMD(unionF(i));
        }
    }
    if(dis.size()>=2){
        a = dis.top();
        dis.pop();
        b = dis.top();
        dis.pop();
        //printf("%d : %d %d %d\n",mx,a,b,l);
        mx = std::max(mx,a+b+l);
        if(!dis.empty()){
            c = dis.top();
            dis.pop();
            mx = std::max(mx,b+c+2*l);
        }
    }
    printf("%d\n",mx);
}
