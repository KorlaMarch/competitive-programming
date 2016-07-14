#include "stdio.h"
#include "math.h"

int min_2(int a, int b){
    return a < b ? a : b;
}

int findSizeB(int n){
    return n/4+1;
}

int findSizeW(int n){
    return ((int)sqrt(n))+2;
}

int main(){
    int t,m,n;
    int i;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d%d", &n, &m);
        printf("%d\n", min_2(findSizeB(m),findSizeW(n)));
    }
}
