#include "stdio.h"

int t,k,n;
long long num;
bool isD[10];

bool getD(long long x){
    int i;
    while(x!=0){
        isD[x%10] = true;
        x /= 10;
    }
    for(i = 0; i < 10; i++){
        if(!isD[i]) return false;
    }
    return true;
}

int main(){
    int i;
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        for(i = 0; i < 10; i++) isD[i] = false;
        scanf("%d",&n);
        if(n==0){
            printf("Case #%d: INSOMNIA\n",k);
            continue;
        }
        num = 0;
        for(i = 0; ; i++){
            num += n;
            if(getD(num)){
                printf("Case #%d: %d\n",k,num);
                break;
            }
        }
    }
}
