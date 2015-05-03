#include "stdio.h"
#include "stdlib.h"

int sl[256];
int main(){
    int n,i,j,li,hi,ri;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d", &li,&hi,&ri);
        for(j = li; j < ri; j++){
            if(hi>sl[j]) sl[j] = hi;
        }
    }
    for(i = j = 0; i < 256; i++){
        if(sl[i] != j){
            printf("%d %d ", i,sl[i]);
            j = sl[i];
        }
    }
}
