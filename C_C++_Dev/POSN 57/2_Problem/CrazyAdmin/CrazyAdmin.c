#include "stdio.h"
int m,o,i,min;
int u[100];
int dyn[20][100];

void findMin(int d, int p, int mx){
    int i,sum=0;
    printf("NODE:%d %d %d\n", d,p,mx);
    if(d>m&&p>=o){
        if(mx < min) min = mx;
        return;
    }else if(p>=o||d>m||mx>) return;
    findMin(d+1,p,mx);
    for(i = p; i < o && sum < min; i++){
        sum += u[i];
        if(sum>mx) mx = sum;
        findMin(d+1,i+1,mx);
    }
}
int main(){

    scanf("%d%d", &m,&o);
    for(i = 0; i < o; i++){
        scanf("%d", &u[i]);
    }
    min = 99999999;
    findMin(0,0,0);
    printf("%d\n",min);
}
