#include "stdio.h"

int main(){
    int stc[3] = {};
    char sign[2] = {'+','='};
    int i,sum;
    char c;
    for(i = 0; i < 3; i++){
        while((c = getchar()) == '|'){
            stc[i]++;
        }
    }
    sum = stc[0]+stc[1];
    if(sum > stc[2]){
        if(sum-stc[2] != 2){
            stc[0] = -1;
        }else if(stc[0] > 1){
            stc[0]--;
            stc[2]++;
        }else{
            stc[1]--;
            stc[2]++;
        }
    }else if(sum < stc[2]){
        if(stc[2]-sum != 2){
            stc[0] = -1;
        }else{
            stc[2]--;
            stc[0]++;
        }
    }

    if(stc[0] != -1){
        for(i = 0; i < 3; i++){
            while(stc[i] > 0){
                putchar('|');
                stc[i]--;
            }
            if(i < 2){
                putchar(sign[i]);
            }
        }
        printf("\n");
    }else{
        printf("Impossible\n");
    }
}
