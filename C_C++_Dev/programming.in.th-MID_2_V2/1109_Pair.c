#include "stdio.h"
int n,a,b,i,j;
double sum;
long long fen[100001];
int num[100001],co[100001];
void addFen(int p, int v){
    for(;p<=100000; p += (p&-p)) fen[p] += v;
}
long long getFen(int p){
    long long s = 0;
    for(;p>0;p-=(p&-p)) s += fen[p];
    return s;
}
void addCo(int p){
    for(;p<=100000; p += (p&-p)) co[p]++;
}
int getCo(int p){
    int s = 0;
    for(;p>0;p-=(p&-p)) s += co[p];
    return s;
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&a,&b);
        num[b-1] = a;
    }
    for(i = 0; i < n; i++){
        sum += getFen(100000)-getFen(num[i])+num[i]*(double)(getCo(100000)-getCo(num[i]));
        addFen(num[i],num[i]);
        addCo(num[i]);
    }
    printf("%.0lf\n",sum);
}
