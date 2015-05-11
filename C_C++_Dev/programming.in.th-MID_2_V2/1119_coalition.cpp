#include "stdio.h"
#include "algorithm"

typedef struct{
    int i,m;
}pak;
bool cmp(pak a, pak b){
    return a.m>b.m?true:false;
}

int n,i,all,x,p;
pak a[300000];
int qs[300000];
int ans[300000];

int bs(int d){
    int i=0,j=n-1,m;
    while(i<=j){
        m = (i+j)/2;
        if(qs[m]==d){
            j = m-1;
            break;
        }else if(d<qs[m]) j = m-1;
        else i = m+1;
    }
    return j+1;
}

int main(){
    scanf("%d",&n);
    for(i=all=0; i < n; i++){
        a[i].i = i;
        scanf("%d", &a[i].m);
        all += a[i].m;
    }
    std::sort(a,a+n,cmp);
    qs[0] = a[0].m;
    for(i = 1; i < n; i++){
        qs[i] = qs[i-1]+a[i].m;
    }
    all = all/2+1;
    p = bs(all)-1;
    for(i = 0; i < n; i++){
        x = bs(all-a[i].m);
        if(i < x){
            ans[a[i].i] = p;
        }else{
            ans[a[i].i] = x;
        }
    }
    for(i = 0; i < n; i++) printf("%d\n",ans[i]+1);
}
