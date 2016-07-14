#include "stdio.h"
int num[5];
int i,isSort,t;
void printA(){
    int i;
    for(i = 0; i < 5; i++) printf("%d ", num[i]);
    printf("\n");
}
int main(){
    for(i = 0; i < 5; i++){
        scanf("%d", &num[i]);
    }
    while(!isSort){
        isSort = 1;
        for(i = 0; i < 4; i++){
            if(num[i]>num[i+1]){
                t = num[i];
                num[i] = num[i+1];
                num[i+1] = t;
                printA();
                isSort = 0;
            }
        }
    }
}
