#include "stdio.h"

int set[100];
int mark[100] = {};
int n;

int findSubset(int sum, int mpos, int d){
    int i,j;
    if(sum > d){
        return 0;
    }else if(sum == d){
        return 1;
    }else{
        for(i = mpos; i < n; i++){
            mark[i] = 1;
            if(findSubset(sum+set[i], i+1, d)){
                return 1;
            }else{
                mark[i] = 0;
            }
        }
        return 0;
    }
}

int main(){
    int d, i;
    scanf("%d %d", &n, &d);
    for(i = 0; i < n; i++){
        scanf("%d", &set[i]);
    }

    if(findSubset(0,0,d)){
        for(i = 0; i < n; i++){
            if(mark[i]){
                printf("%d ", set[i]);
            }
        }
    }else{
        printf("No solution\n");
    }
}
