#include "stdio.h"
#include "map"
#include "queue"
typedef struct item{
    int w,v,k,z;

}item;
typedef struct{
    public:
    bool operator()(struct item a, struct item b){
        return a.w==b.w?a.v>b.v:a.w>b.w;
    }
}cmp;
item getItem(int w, int v, int k, int z){
    item tmp;
    tmp.w = w;
    tmp.v = v;
    tmp.k = k;
    tmp.z = z;
    return tmp;
}
int n,m,i,p,w,v,d,x,j,c;
item tmp;
std::priority_queue<item,std::vector<item>,cmp> event;
std::map<int,int> mp;
int main(){
    scanf("%d%d",&n,&m);
    n += m;
    for(i = 0; i < n; i++){
        while(!event.empty()&&event.top().w<=i){
            tmp = event.top();
            event.pop();
            if(mp.count(tmp.v)){
                mp.erase(tmp.v);
                if(tmp.k!=0){
                    mp[tmp.k] = tmp.z;
                }
            }
        }

        scanf("%d",&c);
        if(c==1){
            scanf("%d",&j);
            if(j==1){
                scanf("%d%d",&w,&v);
            }else if(j==2){
                scanf("%d%d%d",&w,&v,&d);
                event.push(getItem(d,w,0,v));
            }else{
                scanf("%d%d%d%d",&w,&v,&d,&x);
                event.push(getItem(d,w,x,v));
            }
            mp[w] = v;
        }else{
            if(!mp.empty()){
                printf("%d\n",mp.begin()->second);
                mp.erase(mp.begin());
            }else printf("0\n");
        }
    }
}
