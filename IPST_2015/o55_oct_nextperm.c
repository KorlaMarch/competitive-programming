#include "stdio.h"

int n,min;
int pmt[1000];
void bsort(int a[],int i, int n){
    int t;
    if(i>=n) return;
    if(a[i-1]>a[i]){
        t = a[i-1];
        a[i-1] = a[i];
        a[i] = t;
    }
    bsort(a,i+1,n);
}
void bbsort(int a[],int i){
    if(i<=1) return;
    bsort(a,1,i);
    bbsort(a,i-1);
}
void scanN(int i, int n){
    if(i>=n) return;
    scanf("%d", pmt+i);
    scanN(i+1,n);
}
void printN(int i, int n){
    if(i>=n) return;
    printf("%d\n", pmt[i]);
    printN(i+1,n);
}
int getCP(int i){
    if(i<1||pmt[i-1]<pmt[i]) return i;
    else return getCP(i-1);
}
int getMinMore(int i, int m){
    int j;
    if(i>=n) return -1;
    else{
        j = getMinMore(i+1,m);
        if(pmt[i]<=m) return j;
        else if(j==-1||pmt[i]<pmt[j]) return i;
        else return j;
    }
}
void next_permu(){
    int cp = getCP(n-1),t;
    int mm = getMinMore(cp,pmt[cp-1]);
    t = pmt[cp-1];
    pmt[cp-1] = pmt[mm];
    pmt[mm] = t;
    bbsort(pmt+cp,n-cp);
}
int main(){
    scanf("%d",&n);
    scanN(0,n);
    next_permu();
    printN(0,n);
}
