#include "stdio.h"
int q,x,y,d,i,j,c,s;
int diviC[1000001];
int prime[80000];
char seive[1000001];

void genPrime(int lim){
    int i,j;
    for(i = 2,s = 0; i <= lim; i++){
        if(!seive[i]){
            prime[s++] = i;
            for(j = i+i; j <= lim; j += i) seive[j] = 1;
        }
    }
}

void findDiv(int pp, long long num, int div, int pc){
    int i,j=div*(pc+1);
    diviC[num] = j;
    if(num*prime[pp]<=1000000) findDiv(pp, num*prime[pp],div,pc+1);
    for(i = pp+1; i < s && num*prime[i]<=1000000; i++){
        findDiv(i,num*prime[i],j,1);
    }
}

int main(){
    genPrime(1000000);
    findDiv(0,1,1,0);
    scanf("%d",&q);
    for(i = 0; i < q; i++){
        scanf("%d %d %d", &x, &y, &d);
        for(j=x,c=0; j<=y; j++){
            if(diviC[j]==d) c++;
        }
        printf("%d\n", c);
    }
}
