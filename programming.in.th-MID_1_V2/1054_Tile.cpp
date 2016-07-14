#include "stdio.h"
#include "algorithm"
#include "vector"
typedef struct{
    int x,y,r;
}pos;
bool cmp(pos a, pos b){
    return a.y<b.y;
}
int max(int a, int b){
    return a>b?a:b;
}
int n,i,j,s,sum;
pos in[100000];
std::vector<pos> vec[40002];

int getOver(pos p){
    std::vector<pos>::iterator it;
    pos t;
    int o = 0;
    t.x = max(0,p.x-p.r-9);
    t.y = p.y-p.r-9;
    for(;t.x<p.x;t.x++){
        for(it = std::lower_bound(vec[t.x].begin(),vec[t.x].end(),t,cmp);it != vec[t.x].end()&&it->y<p.y+p.r+10;++it){
            if((it->x-p.x)*(it->x-p.x)+(it->y-p.y)*(it->y-p.y)<(it->r+p.r)*(it->r+p.r)){
                o++;
            }
        }
    }
    for(it = std::lower_bound(vec[t.x].begin(),vec[t.x].end(),t,cmp);it->y<p.y;++it){
        if((it->x-p.x)*(it->x-p.x)+(it->y-p.y)*(it->y-p.y)<(it->r+p.r)*(it->r+p.r)){
            o++;
        }
    }
    return o;
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d",&in[i].x,&in[i].y,&in[i].r);
        in[i].x += 20000;
    }
    std::sort(in,in+n,cmp);
    for(i = 0; i < n; i++){
        vec[in[i].x].push_back(in[i]);
    }
    for(i = 0; i < 40001; i++){
        s = vec[i].size();
        for(j = 0; j < s; j++){
            sum += getOver(vec[i][j]);
        }
    }
    printf("%d\n",sum);
}
