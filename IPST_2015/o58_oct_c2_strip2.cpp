#include "stdio.h"
int n,m,w,k,i,j,x1,y1,x2,y2;
int fen[31][102001];
int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
void addFen(int index,int x,int v){
    for(int i = x;i<=w;i+=(i&-i)){
        fen[index][i] += v;
    }
}
int getFen(int index,int x){
    int sum = 0;
    for(int i=x;i>0;i-=(i&-i)){
        sum += fen[index][i];
    }
    return sum;
}
int main(){
    w = 102000;
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < n; i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1++,x2++,y1++,y2++;
        for(j = -15; j <= 15; j++){
            if(j<0){
                if(x1-j<y2){
                    addFen(j+15,max(x1,y1+j),1);
                    addFen(j+15,min(x2+1,y2+j+1),-1);
                    printf("J = %d : SE %d %d\n",j,x1,min(x2+1,y2+j+1));
                }
            }else{
                if(y1+j<=x2){
                    addFen(j+15,max(x1,y1+j),1);
                    addFen(j+15,min(x2+1,y2+j+1),-1);
                    printf("J = %d : SE %d %d\n",j,max(x1,y1+j),min(x2+1,y2+j+1));
                }
            }
        }
    }
    for(i = 0; i < m; i++){
        scanf("%d%d",&x1,&y1);
        x1++,y1++;
        printf("%d\n",getFen(x1-y1+15,x1));
    }
}
