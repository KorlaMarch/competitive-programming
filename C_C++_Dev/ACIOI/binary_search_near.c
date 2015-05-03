#include "stdio.h"

int main(){
    int a[100000];
    int n,m,x,i,j,k;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(k = 0; k < m; k++){
        scanf("%d",&x);
        for(i=0,j=n-1; i<j;){
            if(a[(i+j)/2]==x) i=j=(i+j)/2;
            else if(x>a[(i+j)/2]) i = (i+j)/2+1;
            else j = (i+j)/2-1;
        }
        if(j>=0&&a[j]>x) j--;
        if(j>=0) printf("%d\n", a[j]);
        else printf("-1\n");
    }
}
