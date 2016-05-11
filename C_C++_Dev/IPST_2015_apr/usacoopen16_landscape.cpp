#include "stdio.h"
#include "vector"
#include "algorithm"
#include "set"

int n,x,y,z,i,j;
long long sum;
int a[100005],b[100005];
std::multiset<long long> addcost,recost;
int main(){
    scanf("%d%d%d%d",&n,&x,&y,&z);
    for(i = 1; i <= n; i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(i = 1; i <= n; i++){
        //printf("i:%d\n",i);
        if(a[i]>b[i]){
            //remove -> use y unit / z unit
            while(a[i]!=b[i]){
                if(!addcost.empty()&&z*i-*addcost.rbegin()<y){
                    sum += z*i-*addcost.rbegin();
                    recost.insert(2*z*i-*addcost.rbegin());
                    addcost.erase(--addcost.end());
                }else{
                    sum += y;
                    recost.insert(y+z*i);
                }
                //printf("1 : %d\n",sum);
                a[i]--;
            }
        }else{
            //add -> use x unit / z unit
            while(a[i]!=b[i]){
                if(!recost.empty()&&z*i-*recost.rbegin()<x){
                    sum += z*i-*recost.rbegin();
                    addcost.insert(2*z*i-*recost.rbegin());
                    recost.erase(--recost.end());
                }else{
                    sum += x;
                    addcost.insert(x+z*i);
                }
                //printf("2 : %d\n",sum);
                a[i]++;
            }
        }
    }
    printf("%lld\n",sum);
}
