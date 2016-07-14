#include "stdio.h"
#include "vector"
#include "algorithm"
#include "stack"

int n,i,j;
int a[100005],t[100005],x[100005];
std::vector<int> epT,epX;
std::vector<int> que[100005];
int fen[100005],ans[100005];
std::stack<std::pair<int,int>> st;
void addFen(int x, int v, bool isPush = true){
    if(isPush) st.push({x,v});
    for(;x<=n;x+=(x&-x)){
        fen[x] += v;
    }
}

int getFen(int x){
    int sum;
    for(sum = 0; x > 0; x -= (x&-x)){
        sum += fen[x];
    }
    return sum;
}

void clearFen(){
    std::pair<int,int> pi;
    while(!st.empty()){
        pi = st.top();
        st.pop();
        addFen(pi.first,-pi.second,false);
    }
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d",&a[i],&t[i],&x[i]);
        epT.push_back(t[i]);
        epX.push_back(x[i]);
    }
    std::sort(epT.begin(),epT.end());
    std::sort(epX.begin(),epX.end());
    epX.resize(std::unique(epX.begin(),epX.end())-epX.begin());
    for(i = 0; i < n; i++){
        que[std::lower_bound(epX.begin(),epX.end(),x[i])-epX.begin()].push_back(i);
    }

    for(i = 0; i < epX.size(); i++){
        for(int j : que[i]){
            if(a[j]==1){
                addFen(std::lower_bound(epT.begin(),epT.end(),t[j])-epT.begin()+1,1);
            }else if(a[j]==2){
                addFen(std::lower_bound(epT.begin(),epT.end(),t[j])-epT.begin()+1,-1);
            }else{
                ans[j] = getFen(std::lower_bound(epT.begin(),epT.end(),t[j])-epT.begin()+1);
            }
        }
        clearFen();
    }
    for(i = 0; i < n; i++){
        if(a[i]==3){
            printf("%d\n",ans[i]);
        }
    }
}
