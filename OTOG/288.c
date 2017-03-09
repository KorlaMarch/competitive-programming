#include "stdio.h"

int main(){
    int n,i;
    int a[30] = {7,-2,-2};
    scanf("%d", &n);
    for(i = 3; i < n; i++){
        a[i] = a[i-2]*3+a[i-3]*4;
    }
    printf("%d\n", a[n-1]);
}
