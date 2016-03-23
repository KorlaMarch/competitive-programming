#include "stdio.h"
#include "math.h"

int n,px,py,i;
double minD,maxD;
int x[100005],y[100005];

void calDis(double a, double b){
    double d = a*a+b*b;
    if(minD==-1||d<minD) minD = d;
    if(d>maxD) maxD = d;
}

void getMM(double a, double b, double& mn, double& mx){
    if(a<b){
        mn = a;
        mx = b;
    }else{
        mn = b;
        mx = a;
    }
}

void getD(int xa, int ya, int xb, int yb, int px, int py){
    double m,d1,d2,mn,mx,x,y;
    if(xb-xa==0){
        getMM(ya,yb,mn,mx);
        if(py>=mn&&py<=mx) calDis(px-xa,0);
        else return;
    }else if(yb-ya==0){
        getMM(xa,xb,mn,mx);
        if(px>=mn&&px<=mx) calDis(py-ya,0);
        else return;
    }else{
        m = (yb-ya)/(double)(xb-xa);
        d1 = ya-m*xa;
        d2 = py+1.0/m*px;
        x = (d2-d1)/(m+1.0/m);
        y = m*x+d1;
        getMM(xa,xb,mn,mx);
        if(px<mn||px>mx) return;
        getMM(ya,yb,mn,mx);
        if(py<mn||py>mx) return;
        calDis(px-x,py-y);
    }
}

int main(){
    minD = -1;
    maxD = 0;
    scanf("%d%d%d",&n,&px,&py);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x[i],&y[i]);
        calDis(px-x[i],py-y[i]);
    }
    for(i = 0; i < n; i++){
        getD(x[i],y[i],x[(i+1)%n],y[(i+1)%n],px,py);
    }
    printf("%.18f\n",3.14159265358979324*(maxD-minD));
}
