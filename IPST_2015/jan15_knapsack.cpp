#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"
#define vi first
#define wi second
struct node{
    double hus,wi,vi;
    int i;
    bool operator()(node a, node b){
        return a.hus>b.hus;
    }
};
int n,i,j;
double mw,mv;
std::pair<double,double> a[101];
node t,no;
std::priority_queue<node,std::vector<node>,node> qu;
double gethus(int i, double lw){
    double va;
    for(va = 0; i < n && lw>0.0; i++){
        if(lw>=a[i].wi){
            va += a[i].vi;
            lw -= a[i].wi;
        }else{
            va += a[i].vi/a[i].wi*lw;
            break;
        }
    }
    return va;
}
node getNode(int i, double wi, double vi){
    node tmp;
    tmp.hus = vi+gethus(i,mw-wi);
    tmp.i = i;
    tmp.wi = wi;
    tmp.vi = vi;
    return tmp;
}
bool cmp(std::pair<double, double> x, std::pair<double,double> y){
    return x.vi/x.wi>y.vi/y.wi;
}
int main(){
    scanf("%lf %d",&mw,&n);
    for(i = 0; i < n; i++){
        scanf("%lf",&a[i].vi);
    }
    for(i = 0; i < n; i++){
        scanf("%lf",&a[i].wi);
    }
    std::sort(a,a+n,cmp);
    qu.push(getNode(0,0.0,0.0));
    while(!qu.empty()){
        t = qu.top();
        qu.pop();
        if(t.vi>mv) mv = t.vi;
        if(t.i==n) continue;
        if(t.wi+a[t.i].wi<=mw){
            no = getNode(t.i+1,t.wi+a[t.i].wi,t.vi+a[t.i].vi);
            if(no.hus>mv){
                qu.push(no);
            }
        }
        qu.push(getNode(t.i+1,t.wi,t.vi));
    }
    printf("%.6f\n",mv);
}
