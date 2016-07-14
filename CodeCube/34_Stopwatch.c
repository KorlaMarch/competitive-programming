#include "stdio.h"
int t,n,i,j,x,lf;
char isD[10],str[9];
int mp[10];

int main(){
    for(scanf("%d",&t); t>0; t--){
        scanf("%d",&n);
        for(i = 0; i < 10; i++) isD[i] = 0;
        for(i = 0; i < n; i++){
            scanf("%d",&x);
            isD[x] = 1;
        }
        for(i=j=0; i < 10; i++){
            for(;isD[i];i++);
            mp[i] = j++;
        }
        for(i=lf=0; i < 6; i++) if(!isD[i]) lf++;
        scanf(" %s",str);
        n = 10-n;
        for(i = 0; str[i]; i++) if(str[i]>='0'&&str[i]<='9') str[i] = mp[str[i]-'0'];
        x = str[7]+str[6]*n+str[4]*n*n+str[3]*n*n*n+str[1]*n*n*n*lf+str[0]*n*n*n*n*lf;
        printf("%02d:%02d:%02d\n",x/6000,x%6000/100,x%100);
    }
}
