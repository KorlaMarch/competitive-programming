#include "stdio.h"
#include "algorithm"
#include "map"

struct pos{
    int x1,x2,y,i;
};

int n,i;
pos a[100005];
int ft[100005];
int dyn[100005];
int sol[100005];
std::multimap<int,int> fp;
std::multimap<int,int>::iterator it,tmp;
bool cmp(pos a, pos b){
    return a.y<b.y;
}

int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].y);
        a[i].i = i;
    }
    std::sort(a+1,a+n+1,cmp);
    for(i = n; i>0; i--){
        it = fp.upper_bound(a[i].x1);
        while(it!=fp.end()&&it->first < a[i].x2){
            ft[it->second] = i;
            tmp = it++;
            fp.erase(tmp);
        }
        fp.insert( std::pair<int,int>(a[i].x2,i));
    }
    dyn[0] = 0;
    for(i=1; i <= n; i++){
        dyn[i] = dyn[ft[i]]+1;
        sol[a[i].i] = dyn[i];
    }
    for(i = 1; i <= n; i++){
        printf("%d\n",sol[i]);
    }
}
