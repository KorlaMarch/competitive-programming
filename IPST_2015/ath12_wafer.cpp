#include "stdio.h"
#include "algorithm"
#define x first
#define y second
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.y==b.y?a.x>b.x:a.y<b.y;
}
bool cmp2(pair<int,int> a, pair<int,int> b){
    return a.y==b.y?a.x>b.x:a.y>b.y;
}
bool cmp3(pair<int,int> a, pair<int,int> b){
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
bool cmp4(pair<int,int> a, pair<int,int> b){
    return a.y==b.y?a.x<b.x:a.y>b.y;
}
int t,w,l,p,i,j,xi,yi;
long long us;
int h1[1000005],h2[1000005];
pair<int,int> po[100005];
void setH(int a[], int x, int y, int h){
    for(int i = x; i < y; i++) a[i] = h;
}
int main(){
    for(scanf("%d",&t); t>0; t--){
        scanf("%d%d%d",&w,&l,&p);
        for(i = 0; i < p; i++){
            scanf("%d%d",&po[i].x,&po[i].y);
        }
        sort(po,po+p,cmp);
        for(i = 0,xi=w,yi=0; i < p; i++){
            if(po[i].x<=xi){
                yi = po[i].y;
                setH(h1,po[i].x,xi,yi);
                xi = po[i].x;
            }
        }
        setH(h1,0,xi,l);
        ////////////////////////////////////
        sort(po,po+p,cmp2);
        for(i = 0,xi=w,yi=l; i < p; i++){
            if(po[i].x<=xi){
                yi = po[i].y;
                setH(h2,po[i].x,xi,yi);
                xi = po[i].x;
            }
        }
        setH(h2,xi,0,0);

        ////////////////////////////////////
        sort(po,po+p,cmp3);
        for(i = 0,xi=0,yi=0; i < p; i++){
            if(po[i].x>=xi){
                yi = po[i].y;
                for(j = xi; j < po[i].x; j++){
                    if(po[i].y>h1[j]) h1[j] = po[i].y;
                }
                xi = po[i].x;
            }
        }
        setH(h1,xi,w,l);
        ////////////////////////////////////
        sort(po,po+p,cmp4);
        for(i = 0,xi=0,yi=l; i < p; i++){
            if(po[i].x>=xi){
                yi = po[i].y;
                for(j = xi; j < po[i].x; j++){
                    if(yi<h2[j]) h2[j] = yi;
                }
                xi = po[i].x;
            }
        }
        setH(h2,xi,w,0);
        for(us=0,i=0; i<w; i++){
            if(h1[i]>=h2[i]) us += l;
            else us += h1[i]+(l-h2[i]);
        }
        printf("%lld\n",us);
    }
}
