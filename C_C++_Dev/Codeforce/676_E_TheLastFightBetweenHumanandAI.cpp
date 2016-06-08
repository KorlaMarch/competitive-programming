#include "stdio.h"

#define LIM 1000000001

int n,k,i,vc;
long long a[100005];
bool isV[100005];
int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i <= n; i++){
        if(scanf("%I64d",&a[i])){
            isV[i] = true;
            vc++;
        }else{
            scanf(" ?");
            isV[i] = false;
        }
    }
    if(k==0){
        if(isV[0]){
            if(a[0]==0) printf("Yes\n");
            else printf("No\n");
        }else{
            if(vc%2) printf("Yes\n");
            else printf("No\n");
        }
    }else{
        if(vc==n+1){
            for(i = n; i > 0; i--){
                a[i-1] += k*a[i];
                if(a[i-1]>LIM||a[i-1]<-LIM){
                    a[0] = 1; break;
                }
            }
            if(a[0]==0) printf("Yes\n");
            else printf("No\n");
        }else{
            if(n%2) printf("Yes\n");
            else printf("No\n");
        }
    }
}
