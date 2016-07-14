#include "stdio.h"

int n,i,j,oc,sn,ai,bi;
int a[1005];
bool isNP[2000005];
bool isF;
int main(){
    isNP[1] = true;
    for(i = 2; i <= 2000000; i++){
        if(!isNP[i]){
            for(j = i+i; j <= 2000000; j += i){
                isNP[j] = true;
            }
        }
    }
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            oc++;
        }else if(!isNP[a[i]+1]) sn = a[i];
    }
    for(i = 0; i < n && !isF; i++){
        for(j = i+1; j < n; j++){
            if(!isNP[a[i]+a[j]]){
                ai = a[i];
                bi = a[j];
                isF = true;
                break;
            }
        }
    }
    if(oc+(sn!=0)<2&&!isF){
        printf("1\n%d",a[0]);
    }else if(oc+(sn!=0)>=2||!isF){
        printf("%d\n",oc+(sn!=0));
        for(i = 0; i < oc; i++) printf("1 ");
        if(sn) printf("%d ",sn);
    }else if(isF){
        printf("%d\n%d %d\n",2,ai,bi);
    }
    printf("\n");
}
