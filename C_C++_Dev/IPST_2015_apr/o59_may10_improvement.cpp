#include "stdio.h"
#include "vector"

struct ed{
    int i,p,q,t;
    ed(int _i = 0, int _q = 0, int _t = 0, int _p = 0) : i(_i), q(_q), t(_t), p(_p) {}
};

int n,m,i,j,p,q,t,c;
bool isN[100005];
std::vector<ed> edge[100005];
std::vector<ed> edl;
long long lc[100005];
long long mx;

int countN(int x, int o, int t){
    int co = 0;
    for(ed e : edge[x]){
        if(e.t<=t&&e.q!=o){
            co += countN(e.q,x,t);
        }
    }
    return co+isN[x];
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d",&p);
        isN[p]++;
    }
    for(i = 1; i < n; i++){
        scanf("%d%d%d",&p,&q,&t);
        edge[p].push_back(ed(i-1,q,t));
        edge[q].push_back(ed(i-1,p,t));
        edl.push_back(ed(i-1,q,t,p));
    }
    for(i = 0; i < edl.size(); i++){
        lc[i] = countN(edl[i].p,edl[i].q,edl[i].t)*countN(edl[i].q,edl[i].p,edl[i].t);
        if(lc[i]>mx){
            c = 1;
            mx = lc[i];
        }else if(lc[i]==mx) c++;
    }
    printf("%d %lld\n",c,mx);
    for(i = 0; i < edl.size(); i++){
        if(lc[i]==mx) printf("%d ",i);
    }

}
