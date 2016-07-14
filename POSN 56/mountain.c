#include <stdio.h>

int main(){
    int num;
    int x,y,z;
    int max, mid;
    scanf("%d", &num);

    int mounH[num];

    scanf("%d", &mounH[0]);
    max = mounH[0];
    for(x = 1; x < num; x++){
        scanf("%d", &mounH[x]);
        if(mounH[x] > max){
            max = mounH[x];
        }
    }

    for(x = max - 1; x >= 0; x--){
        //printf("|");
        for(y = 0; y < num; y++){
            mid = mounH[y] - 1;
            for(z = 0; z < mounH[y]*2; z++){
                if(mounH[y] > x){
                    if(x == z){
                        printf("/");
                    }else if(z + 1 == mounH[y]*2 - x){
                        printf("\\");
                    }else{
                        printf(".");
                    }
                }else{
                    printf(" ");
                }

            }
        }
        printf("\n");
    }
}
