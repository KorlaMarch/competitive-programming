#include "stdio.h"
#include "algorithm"
#include "vector"

int n,k,i,j,a,b,l;
int minL;
std::vector<std::pair<int,int>> edge[200005];
int si[200005];
bool isV[200005];
int buk[1000005];

int getSize(int x, int o){
    int sum = 1;
    for(auto pi : edge[x]){
        if(pi.first!=o&&!isV[pi.first]){
            sum += getSize(pi.first,x);
        }
    }
    return sum;
}
int getCentroid(int x, int o, int lm){
    si[x] = 1;
    for(auto pi : edge[x]){
        if(pi.first!=o&&!isV[pi.first]){
            int r = getCentroid(pi.first,x,lm);
            if(r!=-1) return r;
            si[x] += si[pi.first];
        }
    }
    for(auto pi : edge[x]){
        if(!isV[pi.first]&&pi.first!=o&&si[pi.first]>lm/2){
            return -1;
        }
    }
    if(lm-si[x]>lm/2) return -1;
    else return x;
}

void addToBuk(int x, int o, int h, int l){
    if(l>k) return;
    if(buk[l]) buk[l] = std::min(buk[l],h);
    else buk[l] = h;
    for(auto pi : edge[x]){
        if(!isV[pi.first]&&pi.first!=o){
            addToBuk(pi.first,x,h+1,l+pi.second);
        }
    }
}

void rmBuk(int x, int o, int l){
    if(l>k) return;
    buk[l] = 0;
    for(auto pi : edge[x]){
        if(!isV[pi.first]&&pi.first!=o){
            rmBuk(pi.first,x,l+pi.second);
        }
    }
}

void cmpBuk(int x, int o, int h, int l){
    if(l>k){
        return;
    }else if(l==k){
        minL = std::min(h,minL);
    }else if(buk[k-l]){
        minL = std::min(h+buk[k-l],minL);
    }
    for(auto pi : edge[x]){
        if(!isV[pi.first]&&pi.first!=o){
            cmpBuk(pi.first,x,h+1,l+pi.second);
        }
    }
}

void findMinL(int x, int si){
    int cen = getCentroid(x,-1,si);
    isV[cen] = true;
    for(auto pi : edge[cen]){
        if(!isV[pi.first]){
            cmpBuk(pi.first,cen,1,pi.second);
            addToBuk(pi.first,cen,1,pi.second);
        }
    }
    for(auto pi : edge[cen]){
        if(!isV[pi.first]){
            rmBuk(pi.first,cen,pi.second);
        }
    }
    for(auto pi : edge[cen]){
        if(!isV[pi.first]){
            findMinL(pi.first,getSize(pi.first,cen));
        }
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(i = 1; i < n; i++){
        scanf("%d%d%d",&a,&b,&l);
        edge[a].push_back({b,l});
        edge[b].push_back({a,l});
    }
    minL = 2*n;
    findMinL(0,n);
    printf("%d\n",minL==2*n?-1:minL);
}
