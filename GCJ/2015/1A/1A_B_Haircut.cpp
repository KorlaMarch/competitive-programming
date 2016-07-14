#include "stdio.h"
#include "queue"
#include "vector"
char isP[100001];
int plist[10001];
int maxP[10001];
int p;
typedef struct{
    int s,k;
    unsigned int t;
}bar;
typedef struct{
    bool operator()(bar a, bar b){
        if(a.t==b.t){
            return a.k>b.k?true:false;
        }else{
            return a.t>b.t?true:false;
        }
    }
}cmp;
void intiPrime(){
    int i,j;
    for(i = 2; i <= 100000; i++){
        if(!isP[i]){
            plist[p++] = i;
            for(j = i*2; j <= 100000; j += i) isP[j] = 1;
        }
    }
}
int main(){
    int t,k,b,n,i,j,c,x;
    long long int lcm;
    int m[1000];
    bar temp;
    std::priority_queue<bar,std::vector<bar>,cmp> q;
    intiPrime();
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d %d",&b, &n);
        for(i = 0; i < p; i++) maxP[i] = 0;
        for(i = 0; i < b; i++){
            scanf("%d", &m[i]);
            for(x=m[i],j=0; x != 1;j++){
                for(c=0; x%plist[j]==0; c++){
                    x /= plist[j];
                }
                if(c>maxP[j]) maxP[j] = c;

            }
        }
        printf("BN:%d %d\n", b,n);
        for(lcm=1,i=0; i < p; i++){
            for(j = 0; j < maxP[i]; j++)lcm *= plist[i];
            if(k>30&&maxP[i]) printf("LCM:%d %d %lld\n",i,maxP[i],lcm);
        }
        for(i=0,c=0; i < b; i++){
            c += lcm/m[i];
        }

        n %= c;
        if(n<=0) n = c;
        for(i = 0; i < b; i++){
            temp.t = 0;
            temp.s = m[i];
            temp.k = i;
            q.push(temp);
        }
        printf("n=%d %lld %d\n",n,lcm,c);
        for(; n>0; n--){
            temp = q.top();
            q.pop();
            c = temp.k;
            temp.t += temp.s;
            q.push(temp);
        }
        printf("Case #%d: %d\n", k, c+1);
        while(!q.empty()) q.pop();
    }
}
