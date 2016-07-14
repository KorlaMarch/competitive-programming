#include "stdio.h"

int main(){
    int s,l,i,pa,pb,x;
    scanf("%d",&pa);
    pb = pa;
    for(i=0,s=1,l=2; pa>0&&pb>0; i++){
        scanf("%d",&x);
        if(x%2){
            if(l==1) s++;
            else s=1;
            pb -= s>=3?3:1;
        }else{
            if(l==0) s++;
            else s=1;
            pa -= s>=3?3:1;
        }
        l = x%2;
    }
    printf("%d\n%d\n",pa>0?1:0,x);
}
