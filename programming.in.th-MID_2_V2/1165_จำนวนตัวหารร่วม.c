#include "stdio.h"
#include "math.h"
long long int gcd(long long int a, long long int b){
    long long int t;
    if(a<b){
        t = a;
        a = b;
        b = t;
    }
    while(a%b){
        t = a%b;
        a = b;
        b = t;
    }
    return b;
}

int main(){
    int d,i,j,sq,div;
    long long int g,x;
    scanf("%d %lld",&d,&g);
    for(i = 1; i < d; i++){
        scanf("%lld",&x);
        g = gcd(g,x);
    }
    if(g==1){
        printf("1\n");
    }else{
        sq = ((int)sqrt(g))+1;
        for(i = 2, div = 1; i < sq; i++){
            for(j = 0; g%i==0; j++) g /= i;
            div *= j+1;
        }
        if(div == 1) printf("2\n");
        else printf("%d\n", div);
    }
}
