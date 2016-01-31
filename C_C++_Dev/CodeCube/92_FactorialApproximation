#include "stdio.h"
#include "math.h"

int i,j,q,n,c;
int p[10000];
double logp[10000];
double slog[100005];
char isP[100005];

int main(){
    isP[2] = 0;
    p[c++] = 2;
    for(i = 3; i <= 100000; i += 2){
        if(!isP[i]){
            p[c++] = i;
            for(j = i+i; j <= 100000; j += i){
                isP[j] = 1;
            }
        }
    }
    for(i = 0; i < c; i++){
        logp[i] = log10((double)p[i]);
    }
    for(i = 1; i <= 100000; i++){
        for(j = 0; j < c && i*p[j] <= 100000; j++){
            slog[i*p[j]] = slog[i]+logp[j];
        }
        slog[i] += slog[i-1];
    }
    scanf("%d",&q);
    for(i = 0; i < q; i++){
        scanf("%d",&n);
        printf("%d\n",(int)slog[n]+1);
    }
}
