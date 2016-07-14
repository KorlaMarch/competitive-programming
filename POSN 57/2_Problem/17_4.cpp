#include "stdio.h"
#include "algorithm"
int gcd(int a, int b){
    int t;
    while(a%b){
        t = a%b;
        a = b;
        b = t;
    }
    return b;
}
int main(){
    int n,k,m,i,j,sum;
    int v[100];
    scanf("%d",&n);
    for(k = 0; k < n; k++){
        scanf("%d", &m);
        for(i = 0; i < m; i++){
            scanf("%d",&v[i]);
        }
        std::sort(v,v+m);

        for(i=sum=0; i < m; i++){
            for(j = i+1; j < m; j++){
                sum += gcd(v[j],v[i]);
            }
        }
        printf("%d\n", sum);
    }
}
