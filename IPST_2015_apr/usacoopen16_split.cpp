#include "stdio.h"
#include "algorithm"
#include "set"

int n,i,j,x,y,minX,minY,maxX,maxY,tmp;
long long fa,sa,a;
std::vector<std::pair<int,int>> p;
std::multiset<int> stF,stS;

void findSa(){
    int i;
    std::sort(p.begin(),p.end());
    for(i = 0; i < n; i++){
        stS.insert(p[i].second);
    }
    for(i = 0; i+1 < n; i++){
        stF.insert(p[i].second);
        stS.erase(stS.lower_bound(p[i].second));
        a = (p[i].first-p[0].first)*(long long)(*stF.rbegin()-*stF.begin())+(p[n-1].first-p[i+1].first)*(long long)(*stS.rbegin()-*stS.begin());
        if(a<sa) sa = a;
    }
}

int main(){
    scanf("%d",&n);
    minX = minY = 1000000000;
    for(i = 0; i < n; i++){
        scanf("%d%d",&x,&y);
        p.push_back({x,y});
        if(x<minX) minX = x;
        if(x>maxX) maxX = x;
        if(y<minY) minY = y;
        if(y>maxY) maxY = y;
    }
    sa = fa = (maxX-minX)*(long long)(maxY-minY);
    findSa();
    stS.clear();
    stF.clear();
    for(auto& i : p){
        tmp = i.first;
        i.first = i.second;
        i.second = tmp;
    }
    findSa();
    printf("%lld\n",fa-sa);
}
