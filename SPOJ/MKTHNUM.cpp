#include "stdio.h"
#include "vector"
#include "algorithm"

struct node{
    int v;
    node *l,*r;
};

int n,m,i,j,x,y,a,b,k;
int num[100001];
int p[100001];
std::vector<node*> seg;
std::vector<std::pair<int,int>> path;

bool cmp(std::pair<int,int> a, std::pair<int,int> b){
    return a.first<b.first;
}

void initSeg(int no, int x, int y){
    seg[no].push_back({0,0});
    if(x!=y){
        initSeg(no*2+1,x,(x+y)/2);
        initSeg(no*2+2,(x+y)/2+1,y);
    }
}

void insseg(int no, int x, int y, int p, std::pair<int,int> v){
    if(x==y){
        seg[no].push_back(v);
    }else{
        if(p<=(x+y)/2){
            insseg(no*2+1,x,(x+y)/2,p,v);
        }else{
            insseg(no*2+2,(x+y)/2+1,y,p,v);
        }
        seg[no].push_back({v.first,seg[no*2+1].back().second+seg[no*2+2].back().second});
    }
}

bool isIntersect(int x, int y, int a, int b){
    return (x>=a&&x<=b)||(y>=a&&y<=b)||(a>=x&&a<=y)||(b>=x&&b<=y);
}

int getSeg(int no, int ver, int x, int y, int a, int b){
    std::pair<int,int> in;
    if(x>=a&&y<=b){
        in.first = ver;
        return seg[no][std::upper_bound(seg[no].begin(),seg[no].end(),in,cmp)-seg[no].begin()-1].second;
    }else if(isIntersect(x,y,a,b)){
        return getSeg(no*2+1,ver,x,(x+y)/2,a,b)+getSeg(no*2+2,ver,(x+y)/2+1,y,a,b);
    }
    return 0;
}

int main(){
    int r,mid;
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&num[i]);
        path.push_back({num[i],i});
    }
    std::sort(path.begin(),path.end());
    for(i = 0; i < n; i++){
        p[i+1] = path[i].second;
    }
    initSeg(0,0,n-1);
    for(i = 1; i <= n; i++){
        insseg(0,0,n-1,p[i],{i,1});
    }
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&a,&b,&k);
        x = 0,y = n;
        a--,b--;
        while(x<=y){
            mid = (x+y)/2;
            r = getSeg(0,mid,0,n-1,a,b);
            //printf("%d %d %d : %d %d\n",x,mid,y,k-1,r);
            if(r<=k-1){
                x = mid+1;
            }else{
                y = mid-1;
            }
        }
        //printf("%d %d \n",x,y);
        printf("%d\n",path[x-1].first);
    }
}
