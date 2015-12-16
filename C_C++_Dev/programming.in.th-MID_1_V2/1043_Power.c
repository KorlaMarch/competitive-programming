#include "stdio.h"
#include "math.h"
int n,i,j,y,sq,p,g,c;
char isP[10105];
int prime[4000];

int gcd(int a, int b){
    int t;
    if(a==0) return b;
    else if(b==0) return a;
    else{
        if(a<=b){
            t = a;
            a = b;
            b = t;
        }
        while(b){
            t = b;
            b = a%b;
            a = t;
        }
        return a;
    }
}

int main(){
    prime[p++] = 2;
    for(i = 3; i <= 10100; i += 2){
        if(!isP[i]){
            prime[p++] = i;
            for(j = i+i; j <= 10100; j += i){
                isP[j] = 1;
            }
        }
    }
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&y);
        for(j=g=0; y>1 && j<p; j++){
            if(y%prime[j]==0){
                for(c=0;y%prime[j]==0;c++,y/=prime[j]);
                g = gcd(g,c);
            }
        }
        if(g<=1) printf("NO\n");
        else printf("%d\n",g);
    }
}
