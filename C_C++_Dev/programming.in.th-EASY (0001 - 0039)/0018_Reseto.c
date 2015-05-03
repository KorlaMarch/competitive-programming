#include <stdio.h>

int findedP[1000];
int PIndex = 0;


// 0 is P
//1 is พหุคูณของ P
// 2 is ไม่เป็นอะไรเลย
int checkP(int n){
    int x;
    for(x = 0; x < PIndex; x++){
        if(n % findedP[x] == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, k, x, y, count = 0;

    scanf("%d%d", &n, &k);
    for(x = 2; x <= n; x++){
        if(checkP(x)){
            count++;
            if(count == k){
                printf("%d", x);
                return 0;
            }
            for(y = 2; y <= n; y++){

                if(y % x == 0 && checkP(y) && y != x){
                    //printf("enter x = %d y = %d c = %d\n", x, y, count);
                    count++;
                    if(count == k){
                        printf("%d", y);
                        return 0;
                    }
                }
            }
            findedP[PIndex] = x;
            PIndex++;
        }
    }
    return 0;
}
