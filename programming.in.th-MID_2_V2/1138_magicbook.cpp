#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n,k,s,i,j,c,mx,ans;
int xi[100005],ai[100005];
int ep[500500];
int seg[2000500];
int leaf[500500];
bool intersert(int i, int j, int x, int y){
    if((i>=x&&i<=y)||(j>=x&&j<=y)||(x>=i&&y<=j)) return true;
    else return false;
}
int max(int a, int b){
    return a>b?a:b;
}
int rmq(int p,int i, int j,int x, int y){
    if(i>=x&&j<=y){
        return seg[p];
    }else if(intersert(i,j,x,y)){
        return max(rmq(p*2+1,i,i+(j-i)/2,x,y),rmq(p*2+2,i+(j-i)/2+1,j,x,y));
    }
    return 0;
}
void makeSeg(int p, int i, int j){
    if(i==j) leaf[i] = p;
    else{
        makeSeg(p*2+1,i,i+(j-i)/2);
        makeSeg(p*2+2,i+(j-i)/2+1,j);
    }
}

void updateSeg(int p){
    seg[p] = max(seg[p*2+1],seg[p*2+2]);
    if(p) updateSeg((p-1)/2);
}
void setSeg(int p, int a){
    seg[leaf[p]] = a;
    updateSeg((leaf[p]-1)/2);
}
int getep(int v){
    return std::lower_bound(ep,ep+c,v)-ep;
}
int main(){
    scanf("%d%d%d",&n,&k,&s);
    ep[c++] = s;
    for(i = 0; i < n; i++){
        scanf("%d%d",&xi[i],&ai[i]);
        ep[c++] = xi[i]-k;
        ep[c++] = xi[i];
        ep[c++] = xi[i]+k;
    }
    std::sort(ep,ep+c);
    c = std::unique(ep,ep+c)-ep;
    makeSeg(0,0,c-1);
    setSeg(getep(s),1);
    for(i = 0; i < n; i++){
        mx = rmq(0,0,c-1,getep(xi[i]-k),getep(xi[i]+k));
        if(mx){
            setSeg(getep(xi[i]),mx+ai[i]);
            if(mx+ai[i]>ans) ans = mx+ai[i];
        }
    }
    printf("%d\n",ans-1);

}
