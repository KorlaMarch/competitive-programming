#include "stdio.h"
int t,x,k,l,s,i,j,bc,max;
char st[101],kt[101],ran[101];

int powI(int n, int r){
    return r?powI(n,r-1)*n:1;
}

void bf(int d){
    int i,j,y;
    if(d>=s){
        for(i=y=0; i+l<=s; i++){
            for(j = i; j < i+l; j++){
                if(ran[j]!=st[j-i]) break;
            }
            if(j==i+l) y++;
        }
        bc += y;
        if(y>max) max=y;
    }else{
        for(i = 0; i < k; i++){
            ran[d] = kt[i];
            bf(d+1);
        }
    }
}

int main(){
    scanf("%d",&t);
    for(x = 1; x <= t; x++){
        scanf("%d %d %d %s %s",&k,&l,&s,kt,st);
        bc = 0;
        max = 0;
        bf(0);
        printf("Case #%d: %.6f\n",x,max-bc/(double)powI(k,s));
    }
}
