#include "stdio.h"

int x;
bool isNPrime[1000005];
int factor[1000005];

int main(){
    for(int i = 2; i <= 1000005; i++){
        if(!isNPrime[i]){
            for(int j = i+i; j <= 1000005; j += i){
                isNPrime[j] = true;
            }
        }
    }
    printf("Enter number? ");
    scanf("%d",&x);
    //find prime factor
    for(int i = 2; i <= x; i++){
        if(!isNPrime[i]){
            while(x%i==0){
                factor[i]++;
                x /= i;
            }
        }
    }
}

