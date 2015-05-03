#include "stdio.h"

int main(){
    int i,n,a[3] = {};
    char c;
    scanf("%d ",&n);
    for(i=0; i<n; i++){
        c = getchar()-'A';
        if(i%3==c) a[0]++;
        if((i%2?(i/2)%2*2:1)==c) a[1]++;
        if((i/2%3+2)%3==c) a[2]++;
    }
    for(i = 1, n = a[0]; i < 3; i++){
        if(a[i] > n) n = a[i];
    }
    printf("%d\n",n);
    if(a[0] == n) printf("Adrian\n");
    if(a[1] == n) printf("Bruno\n");
    if(a[2] == n) printf("Goran\n");
}
