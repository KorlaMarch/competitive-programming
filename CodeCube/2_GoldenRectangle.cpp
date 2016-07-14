#include "stdio.h"
#include "algorithm"

int n,i,x,y;
int w[20];
std::pair<int,int> bq[20],pq[20];

void prc(char c, int t){
    //printf("CALL %c %d\n",c,t);
    for(;t>0;t--) putchar(c);
}

void recur(int n){
    int i,j;
    //printf(":%d\n",y);
    if(n == 0) return;
    if(n%4==0){
        bq[y++] = std::make_pair(n,w[n]);
        recur(n-1);
        y--;
    }else if(n%4==1){
        for(i = 0; i < w[n]; i++){
            for(j = 0; j<y; j++) prc(bq[j].first+'A'-1,bq[j].second);
            prc(n+'A'-1,w[n]);
            for(j = x-1; j>=0; j--) prc(pq[j].first+'A'-1,pq[j].second);
            printf("\n");
        }
        recur(n-1);
    }else if(n%4==2){
        pq[x++] = std::make_pair(n,w[n]);
        recur(n-1);
        x--;
    }else{
        recur(n-1);
        for(i = 0; i < w[n]; i++){
            for(j = 0; j<y; j++) prc(bq[j].first+'A'-1,bq[j].second);
            prc(n+'A'-1,w[n]);
            for(j = x-1; j>=0; j--) prc(pq[j].first+'A'-1,pq[j].second);
            printf("\n");
        }
    }
}

int main(){
    scanf("%d",&n);
    w[1] = 1;
    w[2] = 1;
    for(i = 3; i < 20; i++){
        w[i] = w[i-1]+w[i-2];
        //printf("%d\n",w[i]);
    }
    recur(n);
}
