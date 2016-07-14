#include "stdio.h"

int main(){
    int i,j,k,s,mi,m;
    for(m=mi=0,i=1; i <= 5; i++){
        for(j = s = 0; j < 4; j++){
            scanf("%d", &k);
            s += k;
        }
        if(s>m){
            m = s;
            mi = i;
        }
    }
    printf("%d %d\n", mi, m);
}
