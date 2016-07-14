#include "stdio.h"
#include "set"
#include "list"
typedef struct{
    int mp,id,h;
}ms;
typedef struct{
    bool operator()(ms a, ms b){
        return a.mp==b.mp?a.id<b.id:a.mp>b.mp;
    }
}cmp;
ms getMS(int mp, int id, int h){
    ms tmp;
    tmp.mp = mp;
    tmp.id = id;
    tmp.h = h;
    return tmp;
}

int k,m,h,cu,i;
long long sumMP;
char c;
ms t;
std::set<ms,cmp> maxMana;
std::list<ms> event[100005];

int main(){
    scanf("%d",&k);
    for(i = 0; i < k; i++){
        for(std::list<ms>::iterator it = event[i].begin(); it!=event[i].end() ;++it){
            t = *it;
            //printf("i = %d D %d %d %d\n",i,t.mp/2,t.id,t.h);
            maxMana.erase(t);
            if(t.mp/2){
                t = getMS(t.mp/2,t.id,t.h);
                maxMana.insert(t);
                event[i+t.h].push_back(t);
            }
        }
        event[i].clear();
        scanf(" %c",&c);
        if(c=='u'){
            if(!maxMana.empty()){
                //printf("U %d %d %d\n",maxMana.begin()->id,maxMana.begin()->mp,maxMana.begin()->h);
                sumMP += maxMana.begin()->mp;
                maxMana.erase(maxMana.begin());
            }
        }else{
            scanf(" %c",&c);
            if(c=='n'){
                scanf("%d",&m);
                maxMana.insert(getMS(m,cu++,0));
            }else{
                scanf("%d%d",&m,&h);
                t = getMS(m,cu++,h);
                maxMana.insert(t);
                event[i+h].push_back(t);
            }
        }
    }
    printf("%lld\n%d\n",sumMP,maxMana.size());
    return 0;
}
