#include "stdio.h"
#include "algorithm"
int home[10001];
int binary(int i, int j, int v){
    int m;
    while(i<=j){
        m = (i+j)/2;
        if(home[m]==v) return 1;
        else if(v<home[m]) j = m-1;
        else i = m+1;
    }
    return 0;
}
int main(){
    int t,k,n,h,q,i,j,x,c;
    scanf("%d", &t);
    for(x = 0; x < t; x++){
        scanf("%d%d%d", &n, &h, &q);
        for(i = 0; i < h; i++){
            scanf("%d", &home[i]);
        }
        std::sort(home,home+h);
        for(i=0; i < q; i++){
            scanf("%d", &k);
            for(j=c=0; j < h; j++){
                if(binary(0,j-1,home[j]-k)) c++;
            }
            printf("%d ", c);
        }
        printf("\n");
    }
}
