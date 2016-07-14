#include "stdio.h"
typedef struct{
    int x1,y1,x2,y2;
}rec;
int min(int a,int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    int n,m,i,j,c;
    rec f[1000];
    rec p;
    scanf("%d %d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d", &f[i].x1,&f[i].y1,&f[i].x2,&f[i].y2);
    }
    for(i = 0; i < m; i++){
        scanf("%d %d %d %d",&p.x1,&p.y1,&p.x2,&p.y2);
        for(j=c=0; j < n; j++){
            if(max(0,min(f[j].x2,p.x2)-max(f[j].x1,p.x1))*max(0,min(f[j].y1,p.y1)-max(f[j].y2,p.y2))) c++;
        }
        printf("%d\n", c);
    }
}
