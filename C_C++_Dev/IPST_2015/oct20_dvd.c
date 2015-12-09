#include "stdio.h"
int n,k,i,q,a,b,tmp,co,mx,mn;
int dv[100500],leave[100500],segMX[500000],segMN[500000];
int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
void makeTree(int i,int x,int y){
    if(x==y){
        leave[co] = i;
        segMX[i] = segMN[i] = co;
        co++;
    }else{
        makeTree(i*2+1,x,x+(y-x)/2);
        makeTree(i*2+2,x+(y-x)/2+1,y);
        segMX[i] = max(segMX[i*2+1],segMX[i*2+2]);
        segMN[i] = min(segMN[i*2+1],segMN[i*2+2]);
    }
}
void updateSeg(int i){
    segMX[i] = max(segMX[i*2+1],segMX[i*2+2]);
    segMN[i] = min(segMN[i*2+1],segMN[i*2+2]);
    if(i) updateSeg((i-1)/2);
}
int intersect(int x, int y, int a, int b){
    return (x>=a&&x<=b)||(y>=a&&y<=b)||(a>=x&&a<=y)||(b>=x&&b<=y);
}
void getMinMax(int i, int x, int y, int a, int b){
    if(x>=a&&y<=b){
        if(segMN[i]<mn) mn = segMN[i];
        if(segMX[i]>mx) mx = segMX[i];
    }else{
        if(x!=y){
            if(intersect(x,x+(y-x)/2,a,b)) getMinMax(i*2+1,x,x+(y-x)/2,a,b);
            if(intersect(x+(y-x)/2+1,y,a,b)) getMinMax(i*2+2,x+(y-x)/2+1,y,a,b);
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        dv[i] = i;
    }
    co = 0;
    makeTree(0,0,n-1);
    for(i = 0; i < k; i++){
        scanf("%d%d%d",&q,&a,&b);
        if(q){
            mx = 0;
            mn = n;
            getMinMax(0,0,n-1,a,b);
            if(mn==a&&mx==b) printf("YES\n");
            else printf("NO\n");
        }else{
            tmp = dv[a];
            dv[a] = dv[b];
            dv[b] = tmp;
            segMN[leave[a]] = segMX[leave[a]] = dv[a];
            segMN[leave[b]] = segMX[leave[b]] = dv[b];
            updateSeg((leave[a]-1)/2);
            updateSeg((leave[b]-1)/2);
        }
    }
}
