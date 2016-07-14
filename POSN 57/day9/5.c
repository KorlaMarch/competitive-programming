#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int findQuickSum(int sum[],int i,int j){
    if(i == 0){
        return sum[j];
    }else if(i > j){
        return 0;
    }else{
        return sum[j]-sum[i-1];
    }
}

int main(){
    int i,j,x;
    int weight[100];
    int sum[100];

    srand(time(NULL));
    for(i = 0; i < 100; i++){
        weight[i] = 10;
    }
    weight[rand()%100] = 6;
    //quick sum
    sum[0] = weight[0];
    for(i = 1; i < 100; i++){
        sum[i] = sum[i-1]+weight[i];
    }
    i = 0, j = 99;
    while(i != j){
        x = (i+j)/2;
        //printf("%d %d %d sum= %d %d %d %d\n",i,j,x,findQuickSum(sum,i,x),findQuickSum(sum,x+1,j),(x-i+1),(j-x));
        if(findQuickSum(sum,i,x)/(x-i+1) < findQuickSum(sum,x+1,j)/(j-x)){
            j = x;
        }else{
            i = x+1;
        }
    }

    printf("Fake coin is at %d (wight %d)\n", i, weight[i]);
}
