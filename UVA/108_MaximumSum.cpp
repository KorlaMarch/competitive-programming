#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n;
int a[105][105];
int mx = -INF;

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
            a[i][j] = a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int x = i; x <= n; x++){
                for(int y = j; y <= n; y++){
                    mx = std::max(mx,a[x][y]-a[x][j-1]-a[i-1][y]+a[i-1][j-1]);
                }
            }
        }
    }

    printf("%d\n",mx);


}
