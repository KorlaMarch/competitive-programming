#include "stdio.h"
#include "math.h"
typedef struct{
    int x,y;
}pos;
float dis(pos a, pos b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int n,q,k,i,j,minP;
float minDis,d;
int seq[1000];
char isV[1000];
pos a[1000];
pos p;

void calSeq(int p,int t){
    float minDis=30000.0,d;
    int i,minP=0;
    isV[p] = 1;
    seq[p] = t;
    if(t==n-1) return;
    for(i = 0; i < n; i++){
        if(!isV[i]){
            d = dis(a[p],a[i]);
            if(d<minDis){
                minDis = d;
                minP = i;
            }
        }
    }
    calSeq(minP,t+1);
}
int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i < n; i++){
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    calSeq(0,0);
    for(i = 0; i < n; i++){
        printf("%d ", seq[i]);
    }
    printf("\n");
    for(i = 0; i < q; i++){
        scanf("%d %d %d",&p.x,&p.y,&k);
        for(j = 0,minDis = 30000.0; j < n; j++){
            d = dis(p,a[j]);
            if(d<minDis){
                minDis = d;
                minP = j;
            }
        }
        printf("min P = %d\n",minP);
        if(seq[k-1]>=seq[minP]) printf("%d\n", (seq[k-1]-seq[minP]));
        else printf("I:%d\n", seq[k-1]+n-seq[minP]);
    }
}
