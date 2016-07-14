#include "stdio.h"
int preCount[1001][1001];
int t,r,c;
void setZ(int x, int y, int n){
    int i,j;
    for(i = x+x+1,j = y+y+1; i<n && j<n; i+=x+1,j+=y+1){
        preCount[i][j] = -1;
    }
}
void preCal(int n){
    int i,j,k,c;
    preCount[0][0] = 1;
    setZ(0,0,n);
    for(i=0,j=1,c=2; j < n;){
        for(i=0; j>=0;i++,j--){
            if(!preCount[i][j]){
                preCount[i][j] = c++;
                setZ(i,j,n);
            }
        }
        for(j=0; i>=0;i--,j++){
            if(!preCount[i][j]){
                preCount[i][j] = c++;
                setZ(i,j,n);
            }
        }
    }
}

int main(){
    int i,j;
    preCal(900);
    for(scanf("%d",&t);t>0;t--){
        scanf("%d%d",&r,&c);
        printf("%d\n",preCount[r-1][c-1]);
    }
}
