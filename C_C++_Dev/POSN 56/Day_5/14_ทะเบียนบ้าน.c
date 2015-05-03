#include <stdio.h>

int main(){
    int n,m,x;
    int num[10] = {0};
    printf("N : "); scanf("%d", &n);
    printf("M : "); scanf("%d", &m);
    for(x = n; x <= m; x++){
        //แยกหลัก
        if(x >= 100){
            num[x/100]++;
        }

        if(x >= 10){
            num[(x/10)%10]++;
        }

        if(x >= 1){
            num[x%10]++;
        }
    }

    for(x = 0; x < 10; x++){
        printf("using %d total = %d\n", x, num[x]);
    }
}
