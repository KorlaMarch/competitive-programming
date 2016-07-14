#include "stdio.h"
#include "algorithm"

int T,k,n,i,j,c,sum;
int xi[3000];
int yi[3000];
int d[3000];

int pow(int x){
    return x*x;
}

int main(){
    scanf("%d",&T);
    for(k = 1; k <= T; k++){
        sum = 0;
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d%d",&xi[i],&yi[i]);
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                d[j] = pow(xi[i]-xi[j])+pow(yi[i]-yi[j]);
            }
            std::sort(d,d+n);
            for(j = 1,c=1; j < n; j++){
                if(d[j]==d[j-1]){
                    c++;
                }else{
                    //printf("%d %d : %d\n",i,d[j-1],c);
                    sum += c*(c-1)/2;
                    c=1;
                }
            }
            //printf("%d %d : %d\n",i,d[j-1],c);
            sum += c*(c-1)/2;
        }
        printf("Case #%d: %d\n",k,sum);
    }
}
