#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define SIZE 10

int main(){
    int n,i;
    char c;
    int a[SIZE];
    srand(time(NULL));
    for(i = 0; i < SIZE; i++){
        a[i] = rand()%10;
    }
    printf("A is:\t");
    for(i = 0; i < SIZE; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    scanf(" %c%d", &c, &n);
    if(c == 'R'){
        n = SIZE-n;
    }
    printf("After:\t");
    for(i = 0; i < SIZE; i++){
        printf("%d ",a[(n+i)%10]);
    }
}
