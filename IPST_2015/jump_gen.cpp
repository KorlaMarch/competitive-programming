#include "stdio.h"

int i;

int main(){
    printf("%d %d\n",30000,30000);
    for(i = 0; i < 30000; i++){
        printf("%d ",i*2+1);
    }
}
