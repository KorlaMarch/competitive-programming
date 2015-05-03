#include <stdio.h>
#include <conio.h>

int main(){
    int num;
    int x,y,z;
    int max, mid;
    int mounH[20];
    printf("Number of mountain : ");
    scanf("%d", &num);

    printf("Mountain 1 Hight : "); scanf("%d", &mounH[0]);
    max = mounH[0];
    for(x = 1; x < num; x++){
        printf("Mountain %d Hight : ", x + 1); scanf("%d", &mounH[x]);
        if(mounH[x] > max){
            max = mounH[x];
        }
    }
    for(x = max - 1; x >= 0; x--){
        printf("|");
        for(y = 0; y < num; y++){
            mid = mounH[y] - 1;
            for(z = 0; z < mounH[y]*2; z++){
                if(mounH[y] > x){
                    if(x == z){
                        printf("/");
                    }else if(z + 1 == mounH[y]*2 - x){
                        printf("\\");
                    }else{
                        printf(" ");
                    }
                }else{
                    printf(" ");
                }

            }
        }
        printf("|\n");
    }
    getch();
    return 0;
}
