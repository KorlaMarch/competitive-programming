#include "stdio.h"

#define LIM 10000000

bool isNotPrime[LIM];
int maxNum[10];

bool isAllPrime(int n){
    for(; n > 0; n /= 10){
        if(isNotPrime[n]){
            return false;
        }
    }
    return true;
}

int countDigit(int n){
    int c = 0;
    for(; n > 0; n /= 10){
        c++;
    }
    return c;
}

int main(){
    // find prime
    for(int i = 2; i < LIM; i++){
        if(!isNotPrime[i]){
            //it is prime

            // cut out multiply
            for(int j = i+i; j < LIM; j += i){
                isNotPrime[j] = true;
            }

            // backward check
            if(isAllPrime(i)){
                maxNum[countDigit(i)] = i;
            }
        }
    }
    for(int i = 1; i <= 7; i++){
        printf("%d ",maxNum[i]);
    }
}
