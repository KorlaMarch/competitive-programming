#include "stdio.h"
int n,i,j,k,l,n2,m;
char c;
long long int sum;
int en[4][10];

void scan(int i){
    scanf(" %c", &c);
    en[i][c-'0']++;
}
int min(int a, int b){
    return a<b?a:b;
}
int main(){
    scanf("%d", &n);
    n2 = n/2;
    for(i = 0; i < n2; i++){
        for(j = 0; j < n2; j++){ scan(0); scan(1); }
        for(j = 0; j < n2; j++){ scan(2); scan(3); }
    }
    for(i=j=k=l=9,sum=0; i >= 0;){
        if(en[0][i] <= 0) i--;
        if(en[1][j] <= 0) j--;
        if(en[2][k] <= 0) k--;
        if(en[3][l] <= 0) l--;

        m = min(min(en[0][i],en[1][j]),min(en[2][k],en[3][l]));
        sum += i*j*k*l*m;
        en[0][i] -= m;
        en[1][j] -= m;
        en[2][k] -= m;
        en[3][l] -= m;
    }
    printf("%d\n", sum);
}
