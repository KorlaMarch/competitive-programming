#include "stdio.h"
#include "algorithm"

int n,q,k,i,j,oj,p,mx1,mx2,mn,mx3,y,bmx;
int x[100005];
int s[100005];
int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i < n; i++){
        scanf("%d",&x[i]);
    }
    std::sort(x,x+n);
    for(y = 0; y < q; y++){
        scanf("%d",&k);
        for(j = 0; j < k; j++){
            scanf("%d",&s[j]);
        }
        s[k] = -2000000005;
        s[k+1] = 2000000005;
        std::sort(s,s+k+2);
        mx1 = mx2 = mx3 = -2000000005;
        for(i = 0, j = 0; i < k+1; i++){
            //printf("i : %d (%d %d)\n",i,s[i],s[i+1]);
            mn = -2000000005;
            for(oj = j; j < n && x[j] <= s[i+1]; j++){
                mn = std::max(mn,std::min(s[i+1]-x[j],x[j]-s[i]));
                //printf("J:%d %d %d\n",s[i],x[j],s[i+1]);
            }
            if(mn>=mx1){
                mx2 = mx1;
                mx1 = mn;
            }else if(mn>mx2){
                mx2 = mn;
            }
            for(p = oj; oj < j; oj++){
                for(; p < j; p++){
                    mn = std::min(std::min(s[i+1]-x[oj],x[oj]-s[i])+std::min(s[i+1]-x[p],x[p]-s[i]),x[p]-x[oj]);
                    if(mn>mx3) mx3 = mn;
                }
            }
        }
        //printf("%d %d %d\n",mx1,mx2,mx3);
        printf("%d\n",std::max(mx1+mx2,mx3));
    }
}
