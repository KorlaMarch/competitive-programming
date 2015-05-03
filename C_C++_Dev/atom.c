#include "stdio.h"

int main(){
    char c[] = {'s', 'p', 'd', 'f'};
    int maxA[] = {2,6,10,14};
    int sum[10] = {};
    int n,s;
    int i,j,k,x;
    scanf("%d", &n);
    for(i = 1, x = n; x;i++){
        for(j = i-2 < 0 ? 0 : i-2; j < i && x; j++){
            //printf("\tI : %d J : %d\n", i, j);
            for(k = 0; j-k >= 0 && x; k++){
                if(x-maxA[j-k] > 0){
                    printf("%d%c^%d ", i+k, c[j-k], maxA[j-k]);
                    x -= maxA[j-k];
                    sum[i+k-1] += maxA[j-k];
                }else{
                    printf("%d%c^%d ", i+k, c[j-k], x);
                    sum[i+k-1] += x;
                    x = 0;
                }
            }
            //printf("\n");
        }
    }
    printf("\n");
    for(i = 0, s = 0; sum[i] != 0; i++){
        printf("%d ", sum[i]);
        s += sum[i];
    }
    printf("\n%d", s);
}
