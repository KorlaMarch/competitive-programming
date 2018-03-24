#include "stdio.h"

int n,k;
bool isK[1000];

int main(){
    printf("Enter number of children, N? ");
    scanf("%d",&n);
    printf("Enter K? ");
    scanf("%d",&k);
    for(int i = 0; i < n; i++){
        isK[i] = false;
    }
    for(int i = 0, p = 0; i < n; i++){
        for(int j = 0; j < k;){
            p = p%n+1;
            if(!isK[p]){
                j++;
            }
        }
        isK[p] = true;
        printf("%d ",p);
    }
}
