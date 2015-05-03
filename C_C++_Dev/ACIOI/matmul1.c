#include "stdio.h"

int main(){
    int m,n,p,i,j,k,sum;
    int a[100][100];
    int b[100][100];
    scanf("%d%d%d",&m,&n,&p);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<p;j++){
            scanf("%d", &b[i][j]);
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            for(k = sum = 0; k < n; k++){
                sum += a[i][k]*b[k][j];
            }
            printf("%d ", sum);
        }
        putchar('\n');
    }
}
