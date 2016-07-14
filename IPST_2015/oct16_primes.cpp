#include "stdio.h"
#include "vector"
int n,d,i,j,ptr;
char isPrime[100010];
int p[9000];
char s[5][5];
int getSum(int n){
    int sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int checkT(int x, int y, int cx, int cy, int p, int sum){
    if(x>=5||y>=5||x<0||y<0){
        return (n==sum)&&(!isPrime[p])&&(p>=10000);
    }else{
        return checkT(x+cx,y+cy,cx,cy,p*10+s[x][y],sum+s[x][y]);
    }
}
void listP(int d){
    if(d>=5){
        /*printf("%d %d %d %d %d %d\n",checkT(0,1,1,0,0,0),
           checkT(0,2,1,0,0,0),
           checkT(0,3,1,0,0,0),
           checkT(0,4,1,0,0,0),
           checkT(0,0,1,1,0,0),
           checkT(4,0,-1,1,0,0));*/
        if(checkT(4,0,0,1,0,0)&&
           checkT(0,1,1,0,0,0)&&
           checkT(0,2,1,0,0,0)&&
           checkT(0,3,1,0,0,0)&&
           checkT(0,4,1,0,0,0)&&
           checkT(0,0,1,1,0,0)&&
           checkT(4,0,-1,1,0,0)){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    putchar(s[i][j]+'0');
                }
                putchar('\n');
            }
            //printf("\n");
        }
        return;
    }else{
        if(d==4){
            s[4][1] = n-(s[3][1]+s[2][1]+s[1][1]+s[0][1]);
            s[4][2] = n-(s[3][2]+s[2][2]+s[1][2]+s[0][2]);
            s[4][3] = n-(s[3][3]+s[2][3]+s[1][3]+s[0][3]);
            s[4][4] = n-(s[3][4]+s[2][4]+s[1][4]+s[0][4]);
            if(s[4][1]>=0&&s[4][2]>=0&&s[4][3]>=0&&s[4][4]>=0
               &&s[4][1]<=9&&s[4][2]<=9&&s[4][3]<=9&&s[4][4]<=9
               &&s[4][1]%2&&s[4][2]%2&&s[4][3]%2&&s[4][4]%2){
                listP(5);
            }
        }else{
            for(int i = 0; i < ptr; i++){
                if(p[i]/10000==s[d][0]){
                    s[d][4] = p[i]%10;
                    s[d][3] = (p[i]/10)%10;
                    s[d][2] = (p[i]/100)%10;
                    s[d][1] = (p[i]/1000)%10;
                    listP(d+1);
                }
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&d);
    for(i = 2; i < 100000; i++){
        if(!isPrime[i]){
            if(i>=10000&&getSum(i)==n){
                p[ptr++] = i;
                //printf("P : %d %d\n",i,getSum(i));
            }
            for(j = i+i; j < 100000; j += i){
                isPrime[j] = 1;
            }
        }
    }

    //printf("%d\n",ptr);
    /*s[0][0] = 1; s[0][1] = 1; s[0][2] = 3; s[0][3] = 5; s[0][4] = 1;
    s[1][0] = 1; s[1][1] = 4; s[1][2] = 0; s[1][3] = 3; s[1][4] = 3;
    s[2][0] = 3; s[2][1] = 0; s[2][2] = 3; s[2][3] = 2; s[2][4] = 3;
    s[3][0] = 5; s[3][1] = 3; s[3][2] = 2; s[3][3] = 0; s[3][4] = 1;
    s[4][0] = 1; s[4][1] = 3; s[4][2] = 3; s[4][3] = 1; s[4][4] = 3;*/

    for(i = 0; i < ptr; i++){
        if(p[i]/10000==d){
            s[4][0] = p[i]%10;
            s[3][0] = (p[i]/10)%10;
            s[2][0] = (p[i]/100)%10;
            s[1][0] = (p[i]/1000)%10;
            s[0][0] = p[i]/10000;
            if((p[i]/1000)%10 == 0&&(p[i]/100)%10 == 0&&(p[i]/10)%10 == 0&&p[i]%10 == 0)
                continue;
            for(j = 0; j < ptr; j++){
                if(p[j]/10000==d&&(p[j]/1000)%10&&(p[j]/100)%10&&(p[j]/10)%10&&p[j]%10){
                    s[0][4] = p[j]%10;
                    s[0][3] = (p[j]/10)%10;
                    s[0][2] = (p[j]/100)%10;
                    s[0][1] = (p[j]/1000)%10;
                    listP(1);
                }
            }
        }
    }
}
