#include "stdio.h"

int main(){
    int n;
    int i,j,k;
    int max = 0;
    int st[100100] = {};

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &k);
        if(k > max){
            max = k;
        }
        st[k]++;
    }

    for(i = 0; i <= max; i++){
        if(st[i]){
            for(j = st[i] > 1 ? i : i+1; j+i <= max; j++){
                if(st[j] && i + j <= max){
                    printf("yes\n");
                    return 0;
                }
            }
        }
    }
    printf("no\n");
}
