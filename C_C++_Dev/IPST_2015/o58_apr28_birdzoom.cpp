#include "stdio.h"
#include "set"

int n,k,q,i,j,h,e,x,mn;
std::set<int> bi;
std::multiset<int> l;
std::set<int>::iterator it,it2;
int v[15];
int getV(std::set<int>::iterator it){
    int j;
    for(j = 0; it != bi.end() && j <= k; j++,it++){
        v[j] = *it;
    }
    //printf("RE %d\n",j);
    return j;
}
int main(){
    scanf("%d%d%d",&n,&k,&q);
    k--;
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        bi.insert(x);
    }
    for(i = 0,it2 = bi.begin(); it2 != bi.end() && i < k; it2++,i++);
    for(it = bi.begin(); it2 != bi.end(); it++,it2++){
        //printf("\tFIRST %d\n",*it2-*it);
        l.insert(*it2-*it);
    }
    for(i = 0; i < q; i++){
        scanf("%d%d",&e,&x);
        if(e==1){
            //insert
            it = bi.insert(x).first;
            h = getV(it);
            for(j = 0; j <= k; j++,it--){
                //printf("J : %d\n",j);
                if(k-j+1<h){
                    //printf("ES %d %d %d\n",v[k-j+1]-*it,v[k-j+1],*it);
                    l.erase(l.lower_bound(v[k-j+1]-*it));
                }
                if(k-j<h){
                    //printf("IN %d %d %d\n",v[k-j]-*it,v[k-j],*it);
                    l.insert(v[k-j]-*it);
                }
                if(it==bi.begin()) break;
            }
        }else{
            //delete
            it = bi.lower_bound(x);
            h = getV(it);
            it = bi.erase(it);

            if(k<h) l.erase(l.lower_bound(v[k]-x));
            if(it!=bi.begin()){
                it--;
                for(j = 1; j <= k; j++,it--){
                    //printf("J : %d\n",j);
                    if(k-j+1<h){
                        //printf("IN %d %d %d\n",v[k-j+1]-*it,v[k-j+1],*it);
                        l.insert(v[k-j+1]-*it);
                    }
                    if(k-j<h){
                        //printf("ES %d %d %d\n",v[k-j]-*it,v[k-j],*it);
                        l.erase(l.lower_bound(v[k-j]-*it));
                    }
                    if(it==bi.begin()) break;
                }
            }
        }
        if(l.empty()) printf("-1\n");
        else printf("%d\n",*l.begin());
    }
}
