#include "stdio.h"

int main(){
    int num[41];
    int v[31];
    int k,i,j,n,m,sum;
    v[0] = 1;
    for(i = 1; i < 31; i++){
        v[i] = v[i-1]*2;
    }
    scanf("%d", &k);
    for(j = 0; j < k; j++){
        scanf("%d%d", &m, &n);
        num[0] = n%10;
        sum = n%10;
        m--;
        for(i = 1; v[i] <= m; i++){
            num[i] = (num[i-1]*num[i-1])%10;
        }
        /*for(i = 0; v[i] <= m; i++){
            printf("%d ", num[i]);
        }*/
        for(i = 0; v[i] <= m; i++);
        for(i--; i >= 0; i--){
            if(m >= v[i]){
                m -= v[i];
                sum *= num[i];
                sum %= 10;
            }
        }
        printf("%d\n", sum);
    }
}
