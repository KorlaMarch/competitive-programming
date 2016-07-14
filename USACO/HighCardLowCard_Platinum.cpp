#include "stdio.h"
#include "set"
#include "algorithm"

int n,i,j,k,hc,lc,mx,ins;
int el[50001],be[50001];
char isP[100010];
int match[100010],rmatch[100010];
std::set<int> su1,su2,sl1,sl2,fu1,fu2,fl1;
std::set<int>::iterator it;
int main(){
    //freopen("cardgame.in","r",stdin);
    //freopen("cardgame.out","w",stdout);
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&el[i]);
        isP[el[i]] = 1;
        sl1.insert(el[i]);
    }

    for(i=0,k=1; i < n; k++){
        if(!isP[k]){
            be[i++] = k;
            sl2.insert(k);
        }
    }
    for(std::set<int>::iterator i=sl1.begin(),j=sl2.begin(); i!=sl1.end()&&j!=sl2.end();){
        if(*j<*i){
            su1.insert(*i);
            su2.insert(*j);
            i = sl1.erase(i);
            j = sl2.erase(j);
            lc++;
        }else i++;
    }
    for(i = 0; i < n; i++){
        //del back
        if(su1.count(el[i]])){
            it = sl1.upper_bound(el[i]);
            if(it==sl1.end()){
                //sl2.insert(su2.rbegin());
                ins = *su2.rbegin();
                su2.erase(*su2.rbegin());
                lc--;
            }else{
                su1.insert(*it);
                sl1.erase(it);
            }
            su1.erase(el[i]);
        }else sl1.erase(el[i]);

        //add front

        el[i]
        if(){

        }

        if(hc+lc>mx) mx = hc+lc;
    }
    printf("%d\n",mx);
    return 0;
}
