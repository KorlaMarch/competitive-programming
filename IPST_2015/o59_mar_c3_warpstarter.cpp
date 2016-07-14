#include "stdio.h"
#include "map"
#include "algorithm"

int n,k,i,j,lx,ly;
std::pair<int,int> wp[100005];
std::map<int,int> mpX;
std::map<int,int>::iterator it,it2,it3;
long long minC,dis;

long long abs(long long x){
    return x<0?-x:x;
}
long long caldis(std::map<int,int>::iterator it1, std::map<int,int>::iterator it2){
    return abs(it1->first-it2->first)+abs(it1->second-it2->second);
}
int main(){
    scanf("%d%d",&n,&k);
    //second = x , first = y
    if(k==1){
        printf("0\n");
        return 0;
    }
    for(i = 0; i < n; i++){
        scanf("%d%d",&wp[i].second,&wp[i].first);
    }
    std::sort(wp,wp+n);
    for(i = 0; i < k; i++){
        mpX[wp[i].second] = wp[i].first;
    }
    it = mpX.begin();
    lx = it->first;
    ly = it->second;
    for(++it; it != mpX.end(); ++it){
        dis += abs(it->first-lx)+abs(it->second-ly);
        lx = it->first;
        ly = it->second;
    }
    minC = dis;
    for(i = k; i < n; i++){
        //remove old
        it = it2 = it3 = mpX.lower_bound(wp[i-k].second);
        it3++;
        if(it == mpX.begin()){
            dis -= caldis(it,it3);
        }else if(it3 == mpX.end()){
            it2--;
            dis -= caldis(it,it2);
        }else{
            it2--;
            dis -= caldis(it,it2)+caldis(it,it3)-caldis(it2,it3);
        }
        mpX.erase(it);
        //add new
        i;
        mpX[wp[i].second] = wp[i].first;
        it = it2 = it3 = mpX.lower_bound(wp[i].second);
        it3++;
        if(it == mpX.begin()){
            dis += caldis(it,it3);
        }else if(it3 == mpX.end()){
            it2--;
            dis += caldis(it,it2);
        }else{
            it2--;
            dis += caldis(it,it2)+caldis(it,it3)-caldis(it2,it3);
        }
        if(dis<minC) minC = dis;
    }
    printf("%lld\n",minC);
}
