#include "stdio.h"
int n,m,k,i,j,x,mx,co;
int box[1000][2][50],en[1000],p[50];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            scanf("%d",box[i][0]+j);
        }
        for(j = 0; j < k; j++){
            scanf("%d",&x);
            if(x<box[i][0][j]){
                box[i][1][j] = box[i][0][j];
                box[i][0][j] = x;
            }else{
                box[i][1][j] = x;
            }
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < k; j++){
            scanf("%d",p+j);
        }
        for(j = 0; j < n; j++){
            for(x = 0; x < k && (box[j][0][x]<=p[x]&&box[j][1][x]>=p[x]); x++);
            if(x==k) en[j]++;
        }
    }
    for(i = 0; i < n; i++){
        if(en[i]>mx){
            mx = en[i];
            co = 1;
        }else if(en[i]==mx) co++;
    }
    printf("%d\n",co);
    for(i = 0; i < n; i++){
        if(en[i]==mx) printf("%d ", i+1);
    }
}
