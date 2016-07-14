#include "stdio.h"
int n,i,sum;
int num[1000001];
char c;
char lc[2];
int main(){
    scanf("%d ",&n);
    num[1] = 1;
    num[2] = 3;
    for(i = 3; i<=n; i++){
        num[i] = (num[i-1]+num[i-2])*2%2553;
        //printf("Num:%d %d\n",i,num[i]);
    }
    for(i=n,sum=1;i>0;i--){
        c = getchar();
        //printf("%d C= %c %d\n",i,c,sum);
        if(c=='R'&&!(lc[i%2]=='P'&&lc[(i+1)%2]=='P')){
            if(i>1&&lc[(i+1)%2]=='P') sum += num[i-1]*2;
            else sum += num[i];
        }else if(c=='S'){
            if((lc[i%2]=='P'&&lc[(i+1)%2]=='P')||(lc[i%2]=='R'&&lc[(i+1)%2]=='R')) sum += num[i];
            else if(i>1&&(lc[(i+1)%2]=='P'||lc[(i+1)%2]=='R')) sum += num[i]+num[i-1]*2;
            else sum += num[i]*2;
        }
        //printf("Sum = %d\n", sum);
        lc[i%2] = c;
        sum%=2553;
    }
    printf("%d\n",sum);
}
