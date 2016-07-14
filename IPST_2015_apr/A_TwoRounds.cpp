#include "stdio.h"
#include "vector"
#include "algorithm"

std::vector<std::vector<int> > li;

struct goup{
    int sa,sb,ida,idb;
    goup(){
        sa = sb = 0;
        ida = li.size();
        li.push_back(std::vector<int>());
        idb = li.size();
        li.push_back(std::vector<int>());
    }
    goup(int _sa, int _sb, int _ida, int _idb) : sa(_sa), sb(_sb), ida(_ida), idb(_idb) {}
    bool trySwap(){
        if(sa<sb){
            int t;
            t = sa;
            sa = sb;
            sb = t;

            t = ida;
            ida = idb;
            idb = t;

            return true;
        }else return false;
    }
};
bool cmp(goup a, goup b){
    if(a.sa==b.sa) return a.sb>b.sb;
    else return a.sa>b.sa;
}
int n,m;
std::vector<int> edge[200];
std::vector<goup> gp;
std::vector<int> va,vb;
char fl[200];

bool findG(int x, int ind){
    char op;
    if(fl[x]=='W'){
        op = 'B';
        gp[ind].sa++;
        li[gp[ind].ida].push_back(x);
    }else{
        op = 'W';
        gp[ind].sb++;
        li[gp[ind].idb].push_back(x);
    }
    for(int i : edge[x]){
        if(fl[i]){
            if(fl[i]==fl[x]) return false;
        }else{
            fl[i] = op;
            if(!findG(i,ind)) return false;
        }
    }
    return true;
}

bool recur(int x, int sum){
    if(sum>n) return false;
    else if(x>=gp.size()){
        if(sum==n){
            return true;
        }else{
            return false;
        }
    }else if(gp[x].sa==gp[x].sb){
        if(recur(x+1,sum+gp[x].sa)){
            for(int p : li[gp[x].ida]){
                va.push_back(p);
            }
            for(int p : li[gp[x].idb]){
                vb.push_back(p);
            }
            return true;
        }
    }else if(gp[x].sa==1){
        if(sum<n){
            if(recur(x+1,sum+1)){
                va.push_back(li[gp[x].ida][0]);
                return true;
            }
        }else{
            if(recur(x+1,sum)){
                vb.push_back(li[gp[x].ida][0]);
                return true;
            }
        }
    }else{
        int sa = gp[x].sa, sb = gp[x].sb;
        //try A
        if(recur(x+1,sum+sa)){
            for(int p : li[gp[x].ida]){
                va.push_back(p);
            }
            for(int p : li[gp[x].idb]){
                vb.push_back(p);
            }
            return true;
        }
        //try B
        if(recur(x+1,sum+sb)){
            for(int p : li[gp[x].idb]){
                va.push_back(p);
            }
            for(int p : li[gp[x].ida]){
                vb.push_back(p);
            }
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    //printf("%d\n",li.size());
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 1; i <= 2*n; i++){
        if(!fl[i]){
            fl[i] = 'W';
            gp.push_back(goup());
            if(!findG(i,gp.size()-1)){
                printf("IMPOSSIBLE\n");
                return 0;
            }
            gp.back().trySwap();
        }
    }
    std::sort(gp.begin(),gp.end(),cmp);
    if(recur(0,0)){
        std::sort(va.begin(),va.end());
        std::sort(vb.begin(),vb.end());
        for(int x : va){
            printf("%d ",x);
        }
        printf("\n");
        for(int x : vb){
            printf("%d ",x);
        }
        printf("\n");
    }else{
        printf("IMPOSSIBLE\n");
    }
}
