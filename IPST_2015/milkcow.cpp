#include "stdio.h"
#include "algorithm"
typedef struct{
    int x,v;
}pos;
pos t[100001];
int n,i,o,lc,li,lt,ls;
bool cmp(pos a, pos b){
    return a.x<b.x;
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&t[i*2].x,&t[i*2+1].x);
        t[i*2].v = 1;
        t[i*2+1].v = -1;
    }
    std::sort(t,t+n*2,cmp);
    n *= 2;
    for(i=o=0; i < n; i++){
        o += t[i].v;
        while(i+1<n&&t[i].x==t[i+1].x){
            i++;
            o += t[i].v;
        }
        //printf("%d %d ",i, o);
        if(o>0&&ls==0){
            ls = 1;
            if(lt&&t[i].x-lt>li) li = t[i].x-lt;
            //printf("0:lt = %d %d\n",t[i].x,lt);
            lt = t[i].x;
        }else if(o==0&&ls==1){
            ls = 0;
            if(t[i].x-lt>lc) lc = t[i].x-lt;
            //printf("1:lt = %d %d\n",t[i].x,lt);
            lt = t[i].x;
        }
    }
    printf("%d\n%d\n",lc,li);
}
