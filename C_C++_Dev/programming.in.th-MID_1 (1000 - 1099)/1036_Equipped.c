#include "stdio.h"

int price[256];

int input_binary(int k){
    int i,j,x;
    for(i=j=0; i < k; i++){
        j = j << 1;
        scanf("%d", &x);
        j = j|x;
    }
    return j;
}

int pow(int n, int r){
    if(r <= 0) return 1;
    return n*pow(n,r-1);
}

int main(){
    int n,k;
    int i,j,w,p;

    scanf("%d%d",&n,&k);
    for(i = 0; i < 256; i++) price[i] = 9999999;
    for(i = 0; i < n; i++){
        scanf("%d", &w);
        p = input_binary(k);
        if(w < price[p]) price[p] = w;
    }
    k = pow(2,k);
    for(i = 1; i < k; i++){
        for(j = 0; j < i; j++){
            for(w = 0; w < j; w++){

                if((w|j) == i &&  price[w]+price[j] < price[i]){
                    //printf("cmp %d|%d=%d==%d %d\n",w,j,w|j,i,price[w]+price[j]);
                    price[i] = price[w]+price[j];
                }
            }
        }
        //printf("p[%d] = %d\n", i,price[i]);
    }
    printf("%d\n", price[k-1]);
}
