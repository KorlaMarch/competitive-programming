#include "stdio.h"

int main(){
    int n,m,t,i,a,b;
    int ar[100000];

    scanf("%d%d", &n, &m);

    for(i = 0; i < n; i++){
        scanf("%d", &ar[i]);
    }

    for(i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        t = ar[a-1];
        ar[a-1] = ar[b-1];
        ar[b-1] = t;
    }

    for(i = 0; i < n; i++){
        printf("%d ", ar[i]);
    }
}
