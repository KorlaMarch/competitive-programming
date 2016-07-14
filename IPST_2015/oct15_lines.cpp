#include "stdio.h"
#include "algorithm"
typedef struct{
    double v;
    int i;
}dub;
bool cmp(dub a, dub b){
    return a.v<b.v;
}
int n,i;
long long co;
double m[100000],c[100000];
int a[100000],t[100000];
double x0,x1;
dub point[100000];
void mergeI(int a[], int an, int b[], int bn){
    int i,j;
    for(i=j=0;i<an||j<bn;){
        if(i<an&&(j>=bn||a[i]<b[j])){
            t[i+j] = a[i];
            i++;
        }else{
            t[i+j] = b[j];
            co += an-i;
            j++;
        }
    }
}
void mergesort(int a[],int n){
    int i;
    if(n<=1) return;
    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    mergeI(a,n/2,a+n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}
int main(){
    scanf("%d %lf %lf",&n,&x0,&x1);
    for(i = 0; i < n; i++){
        scanf("%lf %lf",m+i,c+i);
        point[i].i = i;
        point[i].v = m[i]*x0+c[i];
    }
    std::sort(point,point+n,cmp);
    for(i = 0; i < n; i++){
        point[i].v = m[point[i].i]*x1+c[point[i].i];
        point[i].i = i;
    }
    std::sort(point,point+n,cmp);
    for(i = 0; i < n; i++) a[i] = point[i].i;
    mergesort(a,n);
    printf("%lld\n",co);
}
