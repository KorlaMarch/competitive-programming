#include "stdio.h"
#include "algorithm"

int main(){
    int n,m;
    int i,j;
    int nak_tod[100001];
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d", &nak_tod[i]);
    }
    std::sort(nak_tod, nak_tod+n);
    for(i = 0, j = 0; i < n; i++){
        if(j+nak_tod[i] <= m){
            j += nak_tod[i];
        }else{
            break;
        }
    }
    printf("%d %d ",i,j);
}
