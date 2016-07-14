#include "stdio.h"
#include "algorithm"
struct edge{
    int a,b,i;
};
bool cmp(edge x, edge y){
    return x.a==y.a?x.b>y.b:x.a<y.a;
}
int n,m,i,j,c,x,y;
edge ed[100005];
int ans[2][100005];
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&ed[i].a,&ed[i].b);
        ed[i].i = i;
    }
    std::sort(ed,ed+m,cmp);
    for(i=0,c=1,x=1,y=3; i < m; i++){
        if(ed[i].b==1){
            c++;
            ans[0][ed[i].i] = c-1;
            ans[1][ed[i].i] = c;
        }else{
            if(y>c) break;
            ans[0][ed[i].i] = x;
            ans[1][ed[i].i] = y;
            x++;
            if(x+1>=y){
                y++;
                x = 1;
            }
        }
    }
    if(i!=m) printf("-1\n");
    else{
        for(i = 0; i < m; i++){
            printf("%d %d\n",ans[0][i],ans[1][i]);
        }
    }
}
