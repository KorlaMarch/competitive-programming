#include "stdio.h"

typedef struct{
    int h,p;
}pos;

int n,i,stP;
int hi[1000000],sp[1000000],ep[1000000];
pos st[1000000];
pos t,p;
int main(){
    scanf("%d",&n);
    for(i=stP=0; i < n; i++){
        scanf("%d",hi+i);
        for(stP--;stP>=0&&st[stP].h<hi[i];stP--){
            ep[st[stP].p] = i;
        }
        stP++;
        st[stP].h = hi[i];
        st[stP++].p = i;
    }
    for(stP--; stP>=0;stP--){
        ep[st[stP].p] = n;
    }

    for(stP=0,i = n-1; i >= 0; i--){
        for(stP--;stP>=0&&st[stP].h<hi[i];stP--){
            sp[st[stP].p] = i+1;
        }
        stP++;
        st[stP].h = hi[i];
        st[stP++].p = i;
    }
    for(stP--; stP>=0;stP--){
        sp[st[stP].p] = 0;
    }

    for(i = 0; i < n; i++) printf("%d ",ep[i]-sp[i]);
}
