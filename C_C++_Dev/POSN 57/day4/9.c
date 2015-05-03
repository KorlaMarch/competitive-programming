#include "stdio.h"
#include "conio.h"

int main(){
    int n,i,j,k;
    int moun[20],max = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &moun[i]);
        if(moun[i] > max){
            max = moun[i];
        }
    }

    for(i = max-1; i >= 0; i--){
        for(j = 0; j < n; j++){
            for(k = 0; k < moun[j]*2-1; k++){
                if(k>=i&&k<moun[j]*2-1-i){
                    putchar('*');
                }else{
                    putchar(' ');
                }
            }
        }
        printf("\n");
    }
    getch();
}
