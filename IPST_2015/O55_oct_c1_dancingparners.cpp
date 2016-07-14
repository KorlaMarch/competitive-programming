#include "stdio.h"
#define INF 1000000000
struct dance{
    int h,s;
};
int max(int a, int b){
    return a>b?a:b;
}
int n,i,j,k,h,s,x,lm;
dance a[100001],b[100001];
int mx[100001];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&a[i].h,&a[i].s);
        mx[i] = -INF;
    }
    for(i = 0; i < n; i++){
        scanf("%d%d",&b[i].h,&b[i].s);
    }
    lm = max(a[n-1].h,b[n-1].h);
    x = -INF;
    for(i=j=k=0; i <= lm; i++){
        x--;
        while(b[j].h == i){
            if(b[j].s>x) x = b[j].s;
            j++;
        }
        while(a[k].h == i){
            mx[k] = a[k].s+x;
            k++;
        }
    }
    x = -INF;
    for(i=lm,j=k=n-1; i > 0; i--){
        x--;
        while(b[j].h == i){
            if(b[j].s>x) x = b[j].s;
            j--;
        }
        while(a[k].h == i){
            if(a[k].s+x>mx[k]) mx[k] = a[k].s+x;
            k--;
        }
    }
    for(i = 0; i < n; i++){
        printf("%d\n",mx[i]);
    }
}
