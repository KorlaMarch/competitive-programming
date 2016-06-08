#include "stdio.h"
#include "vector"
#include "algorithm"

int n,a,b,i,j,x,y,m,mxT;
std::vector<int> edge[300005];
std::vector<int> abp;
std::vector<int> tl;
int subt[300005];

int calsubt(int x, int o){
    std::vector<int> tlist;
    int mx = 0,i,j;
    for(int y : edge[x]){
        if(y!=o) tlist.push_back(calsubt(y,x));
    }
    std::sort(tlist.begin(),tlist.end());
    for(i = 0,j = tlist.size(); i < tlist.size(); i++,j--){
        if(tlist[i]+j>mx) mx = tlist[i]+j;
    }
    return subt[x] = mx;
}

bool findABP(int x, int o){
    if(x==a){
        abp.push_back(x);
        return true;
    }else{
        for(int i : edge[x]){
            if(i!=o){
                if(findABP(i,x)){
                    abp.push_back(x);
                    return true;
                }
            }
        }
    }
    return false;
}

int findMX(){
    int i,j,mx;
    std::sort(tl.begin(),tl.end());
    for(i=mx=0,j = tl.size(); i < tl.size(); i++,j--){
        if(tl[i]+j>mx) mx = tl[i]+j;
    }
    return mx;
}

void checkM(int m){
    int i,j;
    // a -> m-1
    for(i = m-1; i >= 0; i--){
        tl.clear();
        for(int x : edge[abp[i]]){
            if((i==0||x!=abp[i-1])&&x!=abp[m]){
                tl.push_back(subt[x]);
            }
        }
        subt[abp[i]] = findMX();
    }
    // b -> m
    for(i = m; i < abp.size(); i++){
        tl.clear();
        for(int x : edge[abp[i]]){
            if((i+1==abp.size()||x!=abp[i+1])&&x!=abp[m-1]){
                tl.push_back(subt[x]);
            }
        }
        subt[abp[i]] = findMX();
    }
}

int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(i = 1; i < n; i++){
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    findABP(b,-1);
    for(i = 0; i < abp.size(); i++){
        for(int x : edge[abp[i]]){
            if((i==0||x!=abp[i-1])&&(i+1==abp.size()||x!=abp[i+1])) calsubt(x,abp[i]);
        }
    }
    mxT = 1000000;
    //for(m = 1; m < abp.size(); m++){
    for(x = 1, y = abp.size()-1; x <= y; ){
        m = (x+y)/2;
        checkM(m);
        if(std::max(subt[a],subt[b])<mxT) mxT = std::max(subt[a],subt[b]);
        if(subt[a]>subt[b]){
            y = m-1;
        }else if(subt[a]<subt[b]){
            x = m+1;
        }else{
            break;
        }
    }
    printf("%d\n",mxT);
}
