#include "stdio.h"
int abs(int n){
    return n<0?n*-1:n;
}
int main(){
    int i,j,k,n;
    float a,m;
    int t[100][2];
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d", &t[i][0], &t[i][1]);
    }
    for(i=0,m=0.0; i<n; i++){
        for(j=i+1; j<n; j++){
            for(k=j+1;k<n; k++){
                a = abs(t[i][0]*t[j][1]+t[j][0]*t[k][1]+t[k][0]*t[i][1]
                    -t[j][0]*t[i][1]-t[k][0]*t[j][1]-t[i][0]*t[k][1])*0.5;
                if(a>m) m = a;
            }
        }
    }
    printf("%.3f\n",m);
}
