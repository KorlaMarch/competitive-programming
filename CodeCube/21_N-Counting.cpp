#include "stdio.h"
#include "algorithm"
typedef struct{
    int x,y;
}pos;
bool cmp(pos a, pos b){
    return a.y<b.y;
}
int n,q,i,x,y,ptr = 1;
int num[20001],fen[430000],p[430000],qu[200000][4];
pos a[200000],b[200000],se[200000];
int ans[200000];
void add(int p, int v){
    for(; p < ptr; p += (p&-p)) fen[p] += v;
}
int getV(int p){
    int s;
    for(s = 0; p > 0; p -= (p&-p)) s += fen[p];
    return s;
}

int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i < n; i++){
        scanf("%d",num+i);
        p[ptr++] = num[i];
    }
    p[0] = -1;
    for(i = 0; i < q; i++){
        scanf("%d%d%d%d",&a[i].y,&b[i].y,&se[i].x,&se[i].y);
        a[i].x = i = b[i].x = i;
        a[i].y -= 2;
        b[i].y--;
        p[ptr++] = --se[i].x;
        p[ptr++] = se[i].y;
    }
    std::sort(a,a+q,cmp);
    std::sort(b,b+q,cmp);
    std::sort(p,p+ptr);
    for(x = 0; a[x].y < 0; x++);
    for(i=y=0; i < n; i++){
        add(std::lower_bound(p,p+ptr,num[i])-p,1);
        for(;x<q&&a[x].y == i; x++){
            ans[a[x].x] -= getV(std::lower_bound(p,p+ptr,se[a[x].x].y)-p)-getV(std::lower_bound(p,p+ptr,se[a[x].x].x)-p);
        }
        for(;y<q&&b[y].y == i; y++){
            ans[b[y].x] += getV(std::lower_bound(p,p+ptr,se[b[y].x].y)-p)-getV(std::lower_bound(p,p+ptr,se[b[y].x].x)-p);
        }
    }
    for(i = 0; i < q; i++) printf("%d ", ans[i]);
}
