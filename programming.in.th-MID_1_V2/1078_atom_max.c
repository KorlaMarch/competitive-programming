#include "stdio.h"
int n,i;
long long int s;
int atom[1000000];
void selection(int a[], int n, int s){
    int i=1,j=n-1,t;
    if(n<=1) return;
    while(i<=j){
        if(a[i]>a[0]&&a[j]<=a[0]){
            t=a[i];
            a[i] = a[j];
            a[j] = t;
        }
        if(a[i]<=a[0]) i++;
        if(a[j]>a[0]) j--;
    }
    t=a[0];
    a[0] = a[j];
    a[j] = t;
    if(j>s) selection(a,j,s);
    else if(j<s) selection(a+j+1,n-j-1,s-j-1);
}
int main(){
    scanf("%d", &n);
    for(i=0; i < n; i++){
        scanf("%d", atom+i);
    }
    selection(atom,n,n/2);
    for(i=s=0,n--; i<n-i; i++){
        s += atom[n-i]-atom[i];
    }
    printf("%lld",s);
}
