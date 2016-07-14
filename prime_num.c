#include "stdio.h"
#include "math.h"

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void isDiv(int x, int d){
    printf("%d = %d(%d) + %d\n", x, d, x/d, x%d);
}

int main(){
    int x,i,sq;
    scanf("%d", &x);
    sq = (int)sqrt((double)x);
    printf("%d\n",sq);
    for(i = 0; prime[i] <= sq; i++){
        isDiv(x,prime[i]);
    }
}
