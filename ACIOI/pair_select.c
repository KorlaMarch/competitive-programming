#include "stdio.h"
int n,q;
int a[8000],b[8000];
int main(){
    int i,j,x,k,r;
    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d",&a[i]);
    for(i = 0; i < n; i++) scanf("%d",&b[i]);
    scanf("%d", &q);
    for(k = 0; k < q; k++){
        scanf("%d", &x);
        for(i=0,j=n-1,r=1; i<n&&j>=0&&r;){
            if(a[i]+b[j]==x) r = 0;
            else if(a[i]+b[j]>x) j--;
            else i++;
        }
        printf("%c\n", r?'N':'Y');
    }
}
