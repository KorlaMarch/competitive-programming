#include "stdio.h"
/*
First Small dataset

T = 1.
R = 100.
N = 3.
M = 5.
K = 7.
*/
int t,i,j,x,y,r,n,m,k,num,co,tc,mx;
int nc[20][20];
int main(){
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #%d: \n",i);
        for(x = 0; x < r; x++){
            co = 0;
            mx = 0;
            for(j = 0; j < k; j++){
                scanf("%d",&num);
                for(y = 2; y <= m; y++){
                    nc[j][y] = 0;
                    while(num%y==0){
                        nc[j][y]++;
                        num /= y;
                    }
                }
            }
            for(j=mx=0; j < k; j++){
                if(nc[j][3]>mx) mx = nc[j][3];
            }
            for(y = 0; y < mx; y++){
                co++;
                putchar('3');
            }

            for(j=mx=0; j < k; j++){
                if(nc[j][5]>mx) mx = nc[j][5];
            }
            for(y = 0; y < mx; y++){
                co++;
                putchar('5');
            }

            for(j=mx=0; j < k; j++){
                if(nc[j][2]>mx) mx = nc[j][2];
            }
            for(;mx>n-co;mx-=2){
                co++;
                putchar('4');
            }
            for(;co<n;co++) putchar('2');
            printf("\n");
        }
    }
}
