#include <stdio.h>
#include <math.h>

unsigned long long int facTo(int from, int to){
    if(from <= to){
        return from;
    }
    return (unsigned long long int)from * facTo(from - 1, to);
}

int main(){
    int n;
    scanf("%d", &n);
    if(n % 2 == 1){
        n++;
    }
    if(facTo(n/2, 1) % (n/2 + 1) != 0){
        printf("%llu", facTo(n, n/2 + 1) / facTo(n/2, 1));
    }else{
        printf("%llu", facTo(n, n/2 + 2) / (facTo(n/2, 1) / (n/2 + 1)));
    }

}
