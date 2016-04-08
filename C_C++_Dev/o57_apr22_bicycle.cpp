#include "stdio.h"

int n,m,d,i,j;
int avgC[100005][3];
int avgS[100005][3];
int di[100005];
int main(){
    scanf("%d%d%d",&n,&m,&d);
    avgC[0][0] = avgC[0][1] = avgC[0][2] = n;
    avgS[0][0] = avgS[0][1] = avgS[0][2] = d;
    for(i = 1; i <= m; i++){
        scanf("%d",&di[i]);
        for(j = 0; j < 3; j++){
            if(j&&(avgS[i-1][j-1]+di[i])/(double)(avgC[i-1][j-1]+1)>avgS[i-1][j]/(double)avgC[i-1][j]&&
               (avgS[i-1][j-1]+di[i])/(double)(avgC[i-1][j-1]+1)>avgS[i][j-1]/(double)avgC[i][j-1]){
                //select
                avgC[i][j] = avgC[i-1][j-1]+1;
                avgS[i][j] = avgS[i-1][j-1]+di[i];
            }else if(j&&avgS[i][j-1]/(double)avgC[i][j-1]>avgS[i-1][j]/(double)avgC[i-1][j]){
                //use old
                avgC[i][j] = avgC[i][j-1];
                avgS[i][j] = avgS[i][j-1];
            }else{
                //not select
                avgC[i][j] = avgC[i-1][j];
                avgS[i][j] = avgS[i-1][j];
            }
        }
    }
    printf("%d\n",avgC[m][2]);

}
