#include "stdio.h"
#include "algorithm"

int main(){
    int a,k,i,j;
    bool winner[100001];
    int coin[11];
    scanf("%d%d", &a, &k);
    for(i = 0; i < a; i++){
        scanf("%d", &coin[i]);
    }
    std::sort(coin,coin+a);
    for(i = 0; i < 100001; i++){
        winner[i] = false;
        for(j = 0; j < a && coin[j] <= i && !winner[i]; j++){
            winner[i] = !winner[i-coin[j]];
        }
    }
    for(i = 0; i < k; i++){
        scanf("%d", &j);
        printf("%c ", winner[j] ? 'X' : 'Y');
    }
}
