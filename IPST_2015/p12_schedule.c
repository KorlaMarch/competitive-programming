#include "stdio.h"
typedef struct{
    int d,t;
}day;
int m,n,i,j;
int a[1005],b[1005];
day dyn[1005][1005];
day tmp1,tmp2;
int main(){
    scanf("%d%d",&m,&n);
    for(i = 1; i <= n; i++){
        scanf("%d",a+i);
    }
    for(i = 1; i <= n; i++){
        scanf("%d",b+i);
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            if(i){
                tmp1 = dyn[i-1][j];
                if(a[i]>tmp1.t){
                    tmp1.d++;
                    tmp1.t = m-a[i];
                }else tmp1.t -= a[i];
            }
            if(j){
                tmp2 = dyn[i][j-1];
                if(b[j]>tmp2.t){
                    tmp2.d++;
                    tmp2.t = m-b[j];
                }else tmp2.t -= b[j];
            }
            if(i==0&&j==0) continue;
            else if(i==0){
                dyn[i][j] = tmp2;
            }else if(j==0){
                dyn[i][j] = tmp1;
            }else{
                if(tmp1.d==tmp2.d) dyn[i][j] = tmp1.t>tmp2.t?tmp1:tmp2;
                else dyn[i][j] = tmp1.d<tmp2.d?tmp1:tmp2;
            }
        }
    }
    printf("%d\n%d\n",dyn[n][n].d,m-dyn[n][n].t);
}
