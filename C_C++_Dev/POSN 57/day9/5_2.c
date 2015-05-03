#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define REAL 10
#define FAKE 6
#define FAKE_NUM 5

int findQuickSum(int sum[],int i,int j){
    if(i == 0){
        return sum[j];
    }else if(i > j){
        return 0;
    }else{
        return sum[j]-sum[i-1];
    }
}

int weight[100];
int sum[100];

void findFakeCoin(int i,int j){
    int x = (i+j)/2;
    if(i == j){
        printf("Fake coin is at %d (wight %d)\n", i, weight[i]);
        return;
    }

    if(findQuickSum(sum,i,x)/(x-i+1) != REAL &&  findQuickSum(sum,x+1,j)/(j-x) != REAL){
        findFakeCoin(i,x);
        findFakeCoin(x+1,j);
    }else if(findQuickSum(sum,i,x)/(x-i+1) != REAL){
        findFakeCoin(i,x);
    }else if(findQuickSum(sum,x+1,j)/(j-x) != REAL){
        findFakeCoin(x+1,j);
    }else{
        printf("No Fake coin\n", i, weight[i]);
    }
}

int main(){
    int i,j;
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        weight[i] = REAL;
    }

    for(i = 0; i < FAKE_NUM; i++){
        do{
            j = rand()%100;
        }while(weight[j] == FAKE);
        weight[j] = FAKE;
    }
    //quick sum
    sum[0] = weight[0];
    for(i = 1; i < 100; i++){
        sum[i] = sum[i-1]+weight[i];
    }

    findFakeCoin(0,99);

}
