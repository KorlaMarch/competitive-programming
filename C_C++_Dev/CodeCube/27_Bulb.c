#include "stdio.h"
int n,i,min;
char bs[20];
void click(int d){
    if(d) bs[d-1] = !bs[d-1];
    bs[d] = !bs[d];
    if(d+1<n) bs[d+1] = !bs[d+1];
}
void recur(int d, int cl){
    int i;
    if(n==d){
        for(i = 0; i < n; i++){
            if(bs[i]) break;
        }
        if(i==n&&cl<min) min = cl;
    }else{
        recur(d+1,cl);
        if((d&&bs[d-1])||!d){
            click(d);
            recur(d+1,cl+1);
            click(d);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",bs+i);
    }
    min = n+1;
    recur(0,0);
    printf("%d\n",min>n?-1:min);
}
