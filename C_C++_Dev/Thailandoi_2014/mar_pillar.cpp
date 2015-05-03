#include "stdio.h"
int maxL,maxC;
int t,i,k,n,s,tmp,st;
int h[50000];
void findMax(int i, int st,int a, int b){
    int j = i;
    for(;i<n&&h[i+a]-h[i+b]>0&&h[i+a]-h[i+b]<3; i++) st++;
    if(st>maxL||(st==maxL&&j<maxC)){
        maxL = st;
        maxC = j;
    }
}
void ans(int a, int b, int c, int d){
    for(i=1,s=1,st=-1; i < n; i++){
        if(h[i+a]-h[i+b]>0&&h[i+a]-h[i+b]<3) s++;
        else{
            if(st!=-1&&(s+1>maxL||(s+1==maxL&&st<maxC))){
                maxL = s+1; maxC = st;
            }
            tmp = h[i];
            h[i] = h[i-1]+c; findMax(i,s,a,b);
            h[i] = h[i-1]+d; findMax(i,s,a,b);
            h[i] = tmp;
            s = 1;
            st = i-1;
        }
    }
    if(st!=-1&&(s+1>maxL||(s+1==maxL&&st<maxC))){
        maxL = s+1; maxC = st;
    }else if(s>maxL){
        maxL = s;
        maxC = 0;
    }
}
int main(){
    scanf("%d",&t);
    for(k = 0; k < t; k++){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d", &h[i]);
        }
        maxL=maxC=0;

        if(n>1){
            tmp = h[0];
            h[0] = h[1]-1; findMax(1,1,0,-1);
            h[0] = h[1]+1; findMax(1,1,-1,0);
            maxC = 0;
            h[0] = tmp;
        }
        ans(0,-1,1,2);
        ans(-1,0,-1,-2);
        printf("%d %d\n", maxL, maxC);
    }
}
