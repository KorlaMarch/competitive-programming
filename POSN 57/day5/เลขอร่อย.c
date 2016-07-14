#include "stdio.h"

int main(){
    char isN[1000] = {};
    int n,i;
    scanf("%d", &n);

    isN[4] = 1;
    isN[6] = 1;
    isN[9] = 1;
    isN[20] = 1;

    for(i = 4; i <= n; i++){
        if((i > 4 && isN[i-4]) ||
           (i > 6 && isN[i-6]) ||
           (i > 9 && isN[i-9]) ||
           (i > 20 && isN[i-20])){
            isN[i] = 1;

        }
        if(isN[i]) printf("%d\n", i);
    }
}
