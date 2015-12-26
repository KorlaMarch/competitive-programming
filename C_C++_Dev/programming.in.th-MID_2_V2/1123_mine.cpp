#include "stdio.h"

int n,k,maxV;
int a[1005][1005];
int mx[1005][1005];
int sp[1005][1005];
int max(int a, int b){
    return a>b?a:b;
}
void solve(){
    int i,j,x;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(i = k; i <= n; i++){
        for(j = k; j <= n; j++){
            sp[i][j] = a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
        }
    }
    for(x = 2; x < k; x *= 2){
        for(i = k; i+x/2 <= n; i++){
            for(j = k; j+x/2 <= n; j++){
                sp[i][j] = max(max(sp[i][j],sp[i+x/2][j+x/2]),max(sp[i][j+x/2],sp[i+x/2][j]));
            }
        }
    }
    x /= 2;
    for(i = k; i <= n-k+1; i++){
        for(j = k;j <= n-k+1; j++){
            mx[i][j] += max(max(sp[i][j],sp[i+k-x][j+k-x]),max(sp[i][j+k-x],sp[i+k-x][j]));
        }
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int t = 0; t < 3; t++){
        solve();
    }
    for(int i = k; i <= n-k+1; i++){
        for(int j = k; j <= n-k+1; j++){
            if(mx[i][j]>maxV) maxV = mx[i][j];
        }
    }
    printf("%d\n",maxV);
}
