#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int min(int a, int b){
    return a<b?a:b;
}
int tMin[70000],tMax[70000],count[70000];
int n,q,a,b,s,e,i;
void scanTree(int p, int i, int j){
    if(i==j){
        scanf("%d",&tMax[p]);
        tMin[p] = tMax[p];
        count[p] = 1;
    }else{
        scanTree(p*2+1,i,(j-i+1)/2-1+i);
        scanTree(p*2+2,(j-i+1)/2+i,j);
        tMin[p] = min(tMin[p*2+1],tMin[p*2+2]);
        tMax[p] = max(tMax[p*2+1],tMax[p*2+2]);
        count[p] = count[p*2+1]+count[p*2+2];
    }
}
int getCount(int p, int i, int j){
    int sum=0;
    if(a>tMax[p]||b<tMin[p]||j<s||i>e) return 0;
    else if(s<=i&&e>=j&&a<=tMin[p]&&b>=tMax[p]) return count[p];
    else {
        sum += getCount(p*2+1,i,(j-i+1)/2-1+i);
        sum += getCount(p*2+2,(j-i+1)/2+i,j);
    }
    return sum;
}
int main(){
    scanf("%d%d",&n,&q);
    scanTree(0,0,n-1);
    for(i = 0; i < q; i++){
        scanf("%d%d%d%d",&s,&e,&a,&b);
        s--,e--;
        printf("%d ",getCount(0,0,n-1));
    }
}
