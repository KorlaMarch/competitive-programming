#include "stdio.h"
#include "algorithm"
typedef struct{
    int a,b;
}tela;
tela T[1000000];
char rock[500000];
char can[500001];
bool cmp(tela a, tela b){
    return a.a<=b.a?true:false;
}
int main(){
    int n,m,k,i,x,y,mx;
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < m; i++){
        scanf("%d%d", &T[i].a, &T[i].b);
    }
    for(i = 0; i < k; i++){
        scanf("%d", &x);
        rock[x-1] = 1;
    }
    std::sort(T,T+m,cmp);

    for(i=0,can[0]=1,x=y=0; i<n; i++){
        if(can[i]){
            while(x<m&&T[x].a<=i) x++;
            while(x<m&&T[x].a==i+1){
                can[T[x].b-1]=1;
                x++;
            }
            if(!rock[i]) can[i+1] = 1;
            mx = i;
        }
    }
    if(mx+1==n) printf("1\n");
    else printf("0 %d\n",mx+1);
}
