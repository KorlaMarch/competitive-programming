#include "stdio.h"

typedef struct{
    int d;
    int m;
}time;

time minT(time a, time b){
    if(a.d == b.d){
        return a.m < b.m ? a : b;
    }else{
        return a.d < b.d ? a : b;
    }
}

time plusT(time a, int t, int lim){
    if(a.m+t > lim){
        a.d++;
        a.m = t;
    }else{
        a.m += t;
        /*if(a.m == lim){
            a.d++;
            a.m = 0;
        }*/
    }
    return a;
}

int main(){
    int m,n;
    int i,j;
    time t;
    time num[2][1001];
    int input[2][1001];
    scanf("%d%d",&m,&n);
    t.d = 0;
    t.m = 0;
    for(i = 0; i < 2; i++){
        for(j = 0; j <= n; j++){
            num[i][j] = t;
        }
    }
    for(i = 0; i < 2; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &input[i][j]);
        }
    }
    //printf("\n");
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            if(i > 0 && j > 0){
                num[i%2][j] = minT(plusT(num[(i+1)%2][j], input[1][i-1], m),plusT(num[i%2][j-1], input[0][j-1], m));
            }else if(i > 0){
                num[i%2][j] = plusT(num[(i+1)%2][j], input[1][i-1], m);
            }else if(j > 0){
                num[i%2][j] = plusT(num[i%2][j-1], input[0][j-1], m);
            }
            //printf("%d(%d) ",num[i%2][j]);
        }
        //printf("\n");
    }
    printf("%d\n%d\n", num[n%2][n].d+1, num[n%2][n].m);
}
