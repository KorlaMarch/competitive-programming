#include "stdio.h"
#include "limits.h"

int main(){
    int min = INT_MAX,minP,max = 0,maxP,n,i,t;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &t);
        if(t < min){
            min = t;
            minP = i;
        }else if(t > max){
            max = t;
            maxP = i;
        }
    }
    printf("%d %d\n", minP+1, maxP+1);
}
