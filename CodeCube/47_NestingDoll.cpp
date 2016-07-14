#include "stdio.h"
#include "algorithm"
#include "map"
std::map<int,int> doll;
int n,i,s,c;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&s);
        doll[s]++;
    }
    for(c=0;!doll.empty();c++){
        for(auto it = doll.begin(); it != doll.end();){
            it->second--;
            if(!it->second){
                auto tmp = it;
                tmp++;
                doll.erase(it);
                it = tmp;
            }else it++;
        }
    }
    printf("%d\n",c);
}
