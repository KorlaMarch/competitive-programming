#include "stdio.h"

int main(){
    int t,smax,i,k,f,cu;
    char c;
    scanf("%d", &t);
    for(k = 1; k <= t; k++){
        scanf("%d ", &smax);
        for(i=cu=f=0; i<=smax; i++){
            c = getchar()-'0';
            if(c){
                if(cu<i){
                    f += i-cu;
                    cu = i;
                }
                cu += c;
            }
        }
        printf("Case #%d: %d\n", k, f);
    }
}
