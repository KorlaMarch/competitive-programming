#include "stdio.h"

int n,p,i;
double x,y,d1,d2;
int l[100005],r[100005];
int cl,cr;
double exp;
int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}

int isIntersert(int x1, int y1, int x2, int y2){
    if((x1>=x2&&x1<=y2)||(y1>=x2&&y1<=y2)||(x2>=x1&&x2<=y1)||(y2>=x1&&y2<=y1)){
        cl = min(x1,x2);
        cr = max(y1,y2);
        return 1;
    }else return 0;
}

int getP(int l, int r){
    int d = (r-l+1);
    if(d%p&&(l%p==0||l%p>(p-d%p)))return d/p+1;
    else return d/p;
}

int main(){
    scanf("%d%d",&n,&p);
    //printf("%d\n", getP(5,5));
    for(i = 0; i < n; i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    for(i = 0; i < n; i++){
        /*if(isIntersert(l[i],r[i],l[(i+1)%n],r[(i+1)%n])){
            exp += 2000.0*getP(cl,cr)/(cr-cl+1);
        }else{*/
            x = getP(l[i],r[i]);
            y = getP(l[(i+1)%n],r[(i+1)%n]);
            d1 = r[i]-l[i]+1;
            d2 = r[(i+1)%n]-l[(i+1)%n]+1;
            exp += 2000.0*(x*(d2-y)+y*(d1-x)+x*y)/(d1*d2);
        //}
        //printf("%d = %.6f\n",i,exp);
    }
    printf("%.9f\n",exp);
}
