#include "stdio.h"

int findMid(int n){
    int i;
    for(i = 1; n > 0; i++) n -= i;
    if(--i % 2 == 0){
        i--;
    }
    return i;
}

void printSpace(int n){
    while(n-- > 0){
        printf(" ");
    }
}

int main(){
    int n,l,t,i,j,m;
    char c;
    scanf("%d", &n);
    m = findMid(n);
    printf("mid = %d\n",m);
    for(i = 0,l = 0; l < n; i++){
        if(i % 2){
            printSpace(m-1);
            for(j = 0; j <= i && l < n; j++,l++){
                putchar('A'+l%26);
            }
        }else{
            for(j = m-1; j >=0; j--){
                if(j <= i && n-l > j){
                    putchar('A'+(l+j)%26);
                }else{
                    putchar(' ');
                }
            }
            l += i+1;
        }
        printf("\n");
    }

}
