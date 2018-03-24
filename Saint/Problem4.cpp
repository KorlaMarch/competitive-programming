#include "stdio.h"

int n,k;
int numList[1000];

void printRecur(int d, int lastNum){
    if(d>=k){
        //print the whole list
        for(int i = 0; i < k; i++){
            printf("%d ", numList[i]);
        }
        printf("\t");
    }else{
        for(int i = lastNum+1; i <= n; i++){
            numList[d] = i;
            printRecur(d+1, i);
        }
    }
}

int main(){
    printf("Enter N and K? ");
    scanf("%d%d",&n,&k);
    printRecur(0,0);
}
