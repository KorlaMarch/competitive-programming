#include "stdio.h"
#include "unordered_set"
int n,q,i,j,x,y;
int a[50005];

std::unordered_set<int> mp;

int main(){
    scanf("%d",&n);
    for(i = 0; i < n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(i = 0; i < q; i++){
        mp.clear();
        scanf("%d %d",&x,&y);
        for(j = x; j <= y; j++){
            mp.insert(a[j]);
        }
        printf("%d\n",(y-x+1)-mp.size());
    }
}
