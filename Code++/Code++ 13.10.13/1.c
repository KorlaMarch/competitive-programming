#include <stdio.h>
#include <math.h>

int findedP[1000000];
int pointer = 0;

int checkPrime(int n){
    int x;
    int c = sqrt(n);
    if(n % 2 == 0 && n != 2){
        return 0;
    }else{
        if(pointer > 0){
            for(x = 0; findedP[x] <= c; x++){
                if(n % findedP[x] == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    int n, x;

    int ord = 1;
    scanf("%d", &n);
    if(checkPrime(n) == 0){
        printf("-1\n");
    }else{
        for(x = 3; x <= n; x += 2){
            if(checkPrime(x)){
                //printf("Find P %d\n", x);
                findedP[pointer] = x;
                //printf("%d ", findedP[pointer] - findedP[pointer - 1]);
                pointer++;
                ord++;
            }
            //printf("loop %d\n", x);
        }
        printf("%d\n", ord);
    }

    return 0;
}
