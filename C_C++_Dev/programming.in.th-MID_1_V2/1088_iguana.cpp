#include "stdio.h"
#include "algorithm"

typedef struct{
    int x,y;
}pos;
bool cmp(pos a, pos b){
    return a.x<b.x;
}
int n,m,i,cnt,lp,ans;
char t;
pos tp[200000];

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d %d",&tp[i*2].x,&tp[i*2+1].x);
        tp[i*2].y = 1;
        tp[i*2+1].x++;
        tp[i*2+1].y = -1;
    }
    scanf(" %c", &t);
    switch(t){
        case 'R': t = 3; break;
        case 'G': t = 4; break;
        case 'B': t = 5; break;
    }
    std::sort(tp,tp+m*2,cmp);
    m *= 2;
    for(i = 0,lp = 1; i < m; i++){
        ans += (tp[i].x-lp)*((t-cnt%3)%3);
        lp = tp[i].x;
        cnt += tp[i].y;
    }
    ans += (n+1-lp)*((t+3-cnt%3)%3);
    printf("%d\n",ans);
}
