#include "stdio.h"

char used[13],offset_l[30],offset_r[30];

int count_w(int n, int m){
    int sum = 0,i;
    if(m>=n){
        return 1;
    }
    for(i = 0; i < n; i++){
        if(!used[i] && !offset_l[i-m+15] && !offset_r[i+m]){
            used[i] = offset_l[i-m+15] = offset_r[i+m] = 1;
            sum += count_w(n,m+1);
            used[i] = offset_l[i-m+15] = offset_r[i+m] = 0;
        }
    }
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n", count_w(n,0));
    return 0;
}
