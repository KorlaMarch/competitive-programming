#include "stdio.h"

int main(){
    int n,i,j,k,max;
    int hight[16];
    scanf("%d", &n);
    for(i = 0,max = 0; i < n; i++){
        scanf("%d", &hight[i]);
        if(hight[i] > max){
            max = hight[i];
        }
    }
    for(i = max-1; i >= 0; i--){
        for(j = 0; j < n; j++){
            for(k = 0; k < hight[j]*2; k++){
                if(i == k && i < hight[j]){
                    printf("/");
                }else if(k == hight[j]*2-1-i && i < hight[j]){
                    printf("\\");
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
