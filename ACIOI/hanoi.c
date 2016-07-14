/*
LANG: C
TASK: SS_006_B_hanoi
*/
#include "stdio.h"

void hanoi(int n,int s,int m,int d){
    if(n<=0) return;
    hanoi(n-1,s,d,m);
    printf("%d %c %c\n",n,s+'A',d+'A');
    hanoi(n-1,m,s,d);
}

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n,0,1,2);
}
