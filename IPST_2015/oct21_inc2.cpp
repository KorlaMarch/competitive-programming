#include "stdio.h"
#include "algorithm"
#include "unordered_map"

int max(int a, int b){
    return a>b?a:b;
}
int n,i,j,mx;
int x[100001],inc[100001],fen[100005],sx[100001];
std::unordered_map<int,int> hs;
void upmax(int i, int v){
    for(;i<=n;i+=(i&-i)){
        if(v>fen[i]) fen[i] = v;
        else break;
    }
}
int getMax(int i){
    int mx = 0;
    for(;i>0;i-=(i&-i)){
        if(fen[i]>mx) mx = fen[i];
    }
    return mx;
}
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&x[i]);
        sx[i] = x[i];
    }
    std::sort(sx+1,sx+n+1);
    for(i = 1; i <= n; i++){
        hs[sx[i]] = i;
    }
    mx = 0;
    for(i = 1; i <= n; i++){
        inc[i] = getMax(hs[x[i]]-1)+1;
        if(inc[i]>mx){
            mx = inc[i];
        }
        upmax(hs[x[i]],inc[i]);
    }
    printf("%d\n",mx);

}

