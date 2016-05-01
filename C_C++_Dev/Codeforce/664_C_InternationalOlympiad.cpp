#include "stdio.h"

int n,i,j;
long long v,ly,t;

int main(){
    for(scanf("%d",&n); n > 0; n--){
        scanf(" IAO'%I64d",&v);
        ly = 1988;
        for(i = 0,t = 10; ; t *= 10, i++){
            if(v%t>ly%t) ly = ly-ly%t+v%t;
            else ly = ly-ly%t+v%t+t;
            if(v%t==v) break;
        }
        printf("%I64d\n",ly);
    }
}
