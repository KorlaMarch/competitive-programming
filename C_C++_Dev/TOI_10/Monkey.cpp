#include "stdio.h"
#include "algorithm"
typedef struct{
    int p,h;
}stick;

bool cmp(stick a, stick b){
    return a.h<b.h?true:false;
}

int m,n,k,s,i,j,t,p;
char c;
stick st[1000000];
int bana[200000];
char canR[200001];
int minH[200000];

void useST(int p,int h){
    if(canR[p]==1){
        if(p>0&&!canR[p-1]){
            canR[p-1] = 2;
            minH[p-1] = h;
        }
        if(p+1<n&&!canR[p+1]){
            canR[p+1] = 2;
            minH[p+1] = h;
        }
    }
}

int main(){
    scanf("%d%d%d",&m,&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d", &bana[i]);
    }
    for(i = 0; i < k; i++){
        scanf("%d %d",&st[i].p,&st[i].h);
    }
    scanf("%d",&s);
    std::sort(st,st+k,cmp);
    canR[s-1] = 1;
    useST(s-1,1);
    for(i = 0; i < k; i++){
        p = st[i].p;
        c = canR[p-1];
        useST(p-1,st[i].h+1);
        useST(p,st[i].h+1);
        if(minH[p-1]<=st[i].h&&minH[p]<=st[i].h){
            c = canR[p-1];
            canR[p-1] = canR[p];
            canR[p] = c;
        }else if(minH[p-1]<=st[i].h){
            if(canR[p-1]==1||canR[p]!=1) canR[p] = canR[p-1];
            canR[p-1] = 0;
        }else if(minH[p]<=st[i].h){
            if(canR[p]==1||canR[p-1]!=1) canR[p-1] = canR[p];
            canR[p] = 0;
        }
        useST(p-1,st[i].h+1);
        useST(p,st[i].h+1);
    }
    for(i=p=0; i < n; i++){
        if((canR[i]||canR[i-1]==1||canR[i+1]==1)&&bana[i]>p){
            p = bana[i];
            t = canR[i];
        }
    }
    printf("%d\n",p);
    if(t == 1) printf("NO\n");
    else printf("USE\n");
}
