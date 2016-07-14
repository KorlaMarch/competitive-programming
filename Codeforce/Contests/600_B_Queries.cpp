#include "stdio.h"
#include "algorithm"
using namespace std;
int n,m,i,j;
pair<int,int> b[200005];
int a[200005],ans[200005];

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d",&b[i].first);
        b[i].second = i;
    }
    sort(a,a+n);
    sort(b,b+m);
    for(i=j=0; i < m; i++){
        for(;j<n&&a[j]<=b[i].first;j++);
        ans[b[i].second] = j;
    }
    for(i = 0; i < m; i++){
        printf("%d ",ans[i]);
    }
}
