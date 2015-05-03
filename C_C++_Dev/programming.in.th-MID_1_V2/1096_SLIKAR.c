#include "stdio.h"
int n,i;
char pic[512][513];

int getBC(int x, int y, int n1, int n2){
    int i,j,c;
    for(i=x,c=0; i < n1; i++){
        for(j = y; j < n2; j++){
            if(pic[i][j]=='1') c++;
        }
    }
    return c;
}

int paint(int x, int y, int n){
    int max,min,maxP,minP,c,i,j,n2=n/2;
    if(n<=1) return 0;
    max=min=getBC(x,y,n2+x,n2+y);
    maxP=minP=0;
    c = getBC(x,n2+y,n2+x,n+y);
    if(c>max) max = c,maxP = 1;
    if(c<min) min = c,minP = 1;
    c = getBC(n2+x,y,n+x,n2+y);
    if(c>max) max = c,maxP = 2;
    if(c<min) min = c,minP = 2;
    c = getBC(n2+x,n2+y,n+x,n+y);
    if(c>max) max = c,maxP = 3;
    if(c<min) min = c,minP = 3;
    if(minP==maxP) minP=1;
    c = n2*n2-max+min;
    printf("n:%d X:%d Y:%d =%d %d %d %d = %d\n",n,x,y,max,maxP,min,minP,c);
    if(maxP!=0&&minP!=0) c += paint(x,y,n/2);
    if(maxP!=1&&minP!=1) c += paint(x,n2+y,n/2);
    if(maxP!=2&&minP!=2) c += paint(n2+x,y,n/2);
    if(maxP!=3&&minP!=3) c += paint(n2+x,n2+y,n/2);
    return c;
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %s", pic[i]);
    }
    printf("%d\n", paint(0,0,n));
}
