#include "stdio.h"
#include "vector"
#include "algorithm"
#include "set"

int n,x,y,z,i,j,k,sum,mnc,mxA,mxR;
int a[100005],b[100005];
std::vector<int> addcost[100005];
std::vector<int> recost[100005];

int main(){
    scanf("%d%d%d%d",&n,&x,&y,&z);
    for(i = 1; i <= n; i++){
        scanf("%d%d",&a[i],&b[i]);
        sum += b[i]-a[i];
    }
    if(z==0){
        if(sum>0) printf("%d\n",sum*x);
        else printf("%d\n",-sum*y);
    }else{
        sum = 0;
        for(i = 1; i <= n; i++){
            //printf("i:%d\n",i);
            if(a[i]>b[i]){
                //remove -> use y unit / z unit
                while(a[i]!=b[i]){
                    mnc = y;
                    k = 0;
                    for(j = i-1; j > 0 && z*(i-j)-mxA<mnc; j--){
                        if(!addcost[j].empty()&&z*(i-j)-addcost[j].back()<mnc){
                            mnc = z*(i-j)-addcost[j].back();
                            k = j;
                        }
                    }
                    sum += mnc;
                    if(k) addcost[k].pop_back();
                    recost[i].push_back(mnc);
                    a[i]--;
                }
                if(!recost[i].empty()){
                    std::sort(recost[i].begin(),recost[i].end());
                    if(recost[i].back()>mxR) mxR = recost[i].back();
                }
            }else{
                //add -> use x unit / z unit
                while(a[i]!=b[i]){
                    mnc = x;
                    k = 0;
                    for(j = i-1; j > 0 && z*(i-j)-mxR<mnc; j--){
                        if(!recost[j].empty()&&z*(i-j)-recost[j].back()<mnc){
                            mnc = z*(i-j)-recost[j].back();
                            k = j;
                        }
                    }
                    sum += mnc;
                    if(k) recost[k].pop_back();
                    addcost[i].push_back(mnc);
                    a[i]++;
                }
                if(!addcost[i].empty()){
                    std::sort(addcost[i].begin(),addcost[i].end());
                    if(addcost[i].back()>mxA) mxA = addcost[i].back();
                }
            }
        }
        printf("%d\n",sum);
    }
}
