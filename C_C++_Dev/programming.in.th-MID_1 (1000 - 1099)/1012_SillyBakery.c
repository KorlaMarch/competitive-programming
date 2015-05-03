#include "stdio.h"
#include "math.h"

int main(){
    int a,b,c,d,e;
    int n, i;
    float sum = 0.0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
        sum += a+0.75*b+0.50*c+0.25*d+0.125*e;
    }
    printf("%d\n", (int)ceil(sum));
}
