#include "stdio.h"
#include "algorithm"
#include "vector"

struct segnode{
    int ver,c,s;
    segnode(int _ver = 0, int _c = 0, int _s = 0) : ver(_ver), c(_c), s(_s) {}
    friend bool operator<(const segnode& l, const segnode& r){
        return l.ver<r.ver;
    }
};

int n,q,e;
int num[100000];
int p[100000];
std::vector<segnode> seg[400005];

void initseg(int no, int x, int y){
    seg[no].push_back(segnode(0,0,0));
    if(x!=y){
        initseg(no*2+1,x,(x+y)/2);
        initseg(no*2+2,(x+y)/2+1,y);
    }
}

void insseg(int no, int i, int j, int x, segnode v){
    if(i==j){
        seg[no].push_back(v);
    }else{
        if(x<=(i+j)/2){
            insseg(no*2+1,i,(i+j)/2,x,v);
        }else{
            insseg(no*2+2,(i+j)/2+1,j,x,v);
        }
        seg[no].push_back(segnode(v.ver,seg[no*2+1].back().c+seg[no*2+2].back().c,seg[no*2+1].back().s+seg[no*2+2].back().s));
    }
}

bool isIntersect(int x, int y, int a, int b){
    return (x>=a&&x<=b)||(y>=a&&y<=b)||(a>=x&&a<=y)||(b>=x&&b<=y);
}

int getC(int ver, int no, int i, int j, int x, int y){
    if(i>=x&&j<=y){
        return seg[no][std::upper_bound(seg[no].begin(),seg[no].end(),segnode(ver))-seg[no].begin()-1].c;
    }else if(isIntersect(i,j,x,y)){
        return getC(ver,no*2+1,i,(i+j)/2,x,y)+getC(ver,no*2+2,(i+j)/2+1,j,x,y);
    }
    return 0;
}

int getS(int ver, int no, int i, int j, int x, int y){
    if(i>=x&&j<=y){
        return seg[no][std::upper_bound(seg[no].begin(),seg[no].end(),segnode(ver))-seg[no].begin()-1].s;
    }else if(isIntersect(i,j,x,y)){
        return getS(ver,no*2+1,i,(i+j)/2,x,y)+getS(ver,no*2+2,(i+j)/2+1,j,x,y);
    }
    return 0;
}

int main(){
    int v,a,b,i,j,z,x,y,m,r;
    scanf("%d%d%d",&n,&q,&e);
    for(i = 0; i < n; i++){
        scanf("%d",&num[i]);
        p[num[i]] = i;
    }
    initseg(0,0,n-1);
    for(v = 1; v <= n; v++){
        insseg(0,0,n-1,p[v],segnode(v,1,v));
    }
    for(i = 0; i < q; i++){
        scanf("%d%d",&a,&b);
        if(e==1&&i!=0){
            a ^= z;
            b ^= z;
        }
        a--,b--;
        x = 0, y = n;
        while(x<=y){
            m = (x+y)/2;
            r = getC(m,0,0,n-1,a,b);
            if(r==(b-a+1)/2){
                break;
            }else if(r<(b-a+1)/2){
                x = m+1;
            }else{
                y = m-1;
            }
        }
        z = getS(n,0,0,n-1,a,b)-2*getS(m,0,0,n-1,a,b);
        printf("%d\n",z);
    }
}
