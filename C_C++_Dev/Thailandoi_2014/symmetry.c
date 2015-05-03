#include "stdio.h"

int main(){
    int n,t;
    int i,j,k,in;
    int maxV,maxP,s;
    scanf("%d", &t);
    for(k = 0; k < t; k++){
        scanf("%d", &n);
        maxP = -1;
        for(i = maxV = s = 0; i < n; i++){
            scanf("%d", &in);
            if(!in){
                s++;
            }else{
                if(s%2 && s>maxV){
                    maxV = s;
                    maxP = (i-s-1+i)/2;
                }
                s = 0;
            }
        }
        if(s%2 && s>maxV){
            maxV = s;
            maxP = (i-s-1+i)/2;
        }
        printf("%d\n", maxP);
    }
}
