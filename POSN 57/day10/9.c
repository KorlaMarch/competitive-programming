#include "stdio.h"

int findmid(int n){
    int i;
    for(i = 0; n > 0; i++) n -= i;
    return i%2 ? i-2 : i-1;
}

void print_space(int n){
    while(n > 0){
        putchar(' ');
        n--;
    }
}

int abz(int i){
    return i < 0 ? 0 : i;
}

int main(){
    int n;
    int m,i,j,l;
    scanf("%d", &n);
    m = findmid(n);
    printf("mid = %d\n", m);
    for(i = 0,l=0; l < n; i++){
        if(i%2){
            print_space(m-1);
            for(j = i-abz(i-n+l+1); j >= 0; j--){
                putchar((l+j)%26+'A');
            }
        }else{
            for(j = m-1; j >= 0; j--){
                if(j <= i && j < n-l){
                    putchar((l+i-j-abz(i-n+l+1))%26+'A');
                }else{
                    putchar(' ');
                }
            }
        }
        l += i+1;
        printf("\n");
    }

    for(;i > 0; i--){
        print_space(m-1);
        printf("A\n");
    }
}
