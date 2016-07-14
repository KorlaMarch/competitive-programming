#include "stdio.h"

int k,a,b;
char s[300];
void printR(int d){
    int i;
    if(a>=k||b>=k){
        for(i = 0; i < d; i++){
            if(s[i]==1) putchar('W');
            else putchar('L');
            putchar(' ');
        }
        putchar('\n');
    }else{
        s[d] = 1;
        a++;
        printR(d+1);
        a--;
        s[d] = 0;
        b++;
        printR(d+1);
        b--;
    }
}
int main(){
    scanf("%d%d%d",&k,&a,&b);
    printR(0);
}
