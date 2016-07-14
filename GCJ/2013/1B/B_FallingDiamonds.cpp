#include "stdio.h"
#include "vector"
#include "algorithm"

int t,k,n,x,y,i,j,s;
std::vector<double> pascal[10001];
double sum;
int main(){
    scanf("%d",&t);

    //generate pascal
    pascal[0].push_back(1);
    for(i = 1; i <= 10000; i++){
        pascal[i].push_back(0.5*pascal[i-1][0]);
        for(j = 1; j < i; j++){
            pascal[i].push_back(0.5*(pascal[i-1][j-1]+pascal[i-1][j]));
        }
        pascal[i].push_back(0.5*pascal[i-1][i-1]);
    }

    for(k = 1; k <= t; k++){
        scanf("%d%d%d",&n,&x,&y);
        x = abs(x);
        for(s = 0; 1+4*s <= n; s++) n -= 1+4*s;
        //printf(":%d %d\n",s,n);
        if((x+y)/2<s) printf("Case #%d: 1.000000\n",k);
        else if((x+y)/2>s||n==0||x==0) printf("Case #%d: 0.000000\n",k);
        else{
            sum = 0;
            for(i = 0; i <= n; i++){
                if(i+std::max(0,n-i-2*s)>=y+1){
                    sum += pascal[n][i];
                }
            }
            printf("Case #%d: %.6f\n",k,sum);
        }
    }
}
