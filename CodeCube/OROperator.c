#include "stdio.h"
int n,k,i;
long long int s,sum,min;
int num[2015];
long long int getMin(int i, int d, long long int v){
    long long int s,r,min=-1;
    if(d==1){
        for(s = 0; i < n; i++) s += num[i];
        //printf("RE\n");
        return v|s;
    }
    for(s = 0; i <= n-d; i++){
        s += num[i];
        //printf("\tCALL %d %d %d\n",i,d,s);
        r = getMin(i+1,d-1,v|s);
        if(r < min || min == -1){
            //printf("min = %d : %d %d\n",i,r,s);
            min = r;
        }
    }
    return min;
}
int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d",num+i);
    }
    min = -1;
    if(k==1){
        for(i=0,min=0; i < n; i++){
            min += num[i];
        }
    }else{
        for(i = 0; i <= n-k; i++){
            sum += num[i];
            //printf("\tCALL %d %d %d\n",i,k,sum);
            s = getMin(i+1,k-1,sum);
            if(s < min || min == -1){
                //printf("min = %d : %d %d\n",i,s,sum);
                min = s;
            }
        }
    }
    printf("%lld\n",min);
}
