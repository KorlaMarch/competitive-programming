#include "stdio.h"
typedef struct{
    short d,m;
}day;
day cmp(day a, day b){
    return a.d==b.d?(a.m<b.m?a:b):(a.d<b.d?a:b);
}
int m,n,i,j;
short a[1000],b[1000];
day minD[1001][1001];
day plusM(day d, short mi){
    if(d.m+mi>m){
        d.d++;
        d.m = mi;
    }else{
        d.m += mi;
    }
    return d;
}
int main(){
    scanf("%d%d",&m,&n);
    for(i = 0; i < n; i++){
        scanf("%hd",a+i);
    }
    for(i = 0; i < n; i++){
        scanf("%hd",b+i);
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            if(i&&j) minD[i][j] =  cmp(plusM(minD[i-1][j],a[i-1]),plusM(minD[i][j-1],b[j-1]));
            else if(i) minD[i][j] =  plusM(minD[i-1][j],a[i-1]);
            else if(j) minD[i][j] =  plusM(minD[i][j-1],b[j-1]);
        }
    }
    printf("%d\n%d\n",minD[n][n].d+1,minD[n][n].m);
}
