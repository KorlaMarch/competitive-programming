#include "stdio.h"
#include "time.h"
#include "stdlib.h"

int i,j;

int main(){
    srand(time(NULL));
    printf("500 200\n");
    j = 0;
    for(i = 0; i < 500; i++){
        j = j+rand()%10000+1;
        printf("%d\n",j);
    }
}
