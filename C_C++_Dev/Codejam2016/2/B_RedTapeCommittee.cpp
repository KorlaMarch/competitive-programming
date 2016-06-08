#include "stdio.h"
#include "algorithm"

int t,n,k,i,j;
double ch;
double p[300];
bool isSe[300];
double calCh(int k){
    double f = 1.0;
    double li[2][205];
    int i,j,y;
    for(i = 0; i <= k; i++){
        li[0][i] = 0.0;
    }
    li[0][0] = 1.0;
    for(i = 0, y = 1; i < n; i++){
        if(isSe[i]){
            for(j = 0; j <= k/2; j++){
                li[y%2][j] = p[i]*li[(y-1)%2][j-1] + (1.0-p[i])*li[(y-1)%2][j];
            }
            y++;
        }
    }
    return li[(y-1)%2][k/2];
}
void select(int x, int c, int k){
    int i,j;
    if(x==n){
        if(c!=k) return;
        ch = std::max(ch,calCh(k));
    }else{
        isSe[x] = false;
        select(x+1,c,k);
        if(c<k){
            isSe[x] = true;
            select(x+1,c+1,k);
        }
    }
}

bool cmp(double a, double b){
    return abs(a-0.5)<abs(b-0.5);
}

int main(){
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%d%d",&n,&k);
        for(j = 0; j < n; j++){
            scanf("%lf",&p[j]);
            isSe[j] = false;
        }
        std::sort(p,p+n);
        //select(0,0,k);
        for(j = 0; j < k/2; j++){
            isSe[j] = isSe[n-j-1] = true;
        }
        ch = calCh(k);
        std::sort(p,p+n,cmp);
        for(j = 0; j < n; j++){
            if(j<k) isSe[j] = true;
            else isSe[j] = false;
        }
        ch = std::max(ch,calCh(k));
        printf("Case #%d: %.10f\n",i,ch);
    }
}

