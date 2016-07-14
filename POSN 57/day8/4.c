#include "stdio.h"

int main(){
    int base,n,i;
    scanf("%d%d", &base, &n);
    for(i = 0; i < n; i++){
        if(i%base < 10){
            putchar('0'+i%base);
        }else{
            putchar('A'+i%base-10);
        }
    }
}
