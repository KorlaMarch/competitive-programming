#include "stdio.h"
unsigned int num[1000];
int n,i,j;
unsigned long long int way;
int main(){

    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &j);
        num[j]++;
    }
    for(i = 0; i < 1000; i++) way += num[i]*(unsigned long long int)(num[i]-1)/2;
    for(i = 0; i < 1000; i++){
        if(num[i]) for(j = i+1; j < 1000; j++){
            if(i%10==j%10) way += num[i]*num[j];
        }
    }
    for(i = 0; i < 1000; i++){
        if(num[i]) for(j = i+1; j < 1000; j++){
            if(i%10!=j%10&&i/10%10==j/10%10) way += num[i]*num[j];
        }
    }
    for(i = 0; i < 1000; i++){
        if(num[i]) for(j = i+1; j < 1000; j++){
            if(i%10!=j%10&&i/10%10!=j/10%10&&i/100==j/100) way += num[i]*num[j];
        }
    }
    printf("%llu\n", way);
}
