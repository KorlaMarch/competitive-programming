#include "stdio.h"
int li[6],isV[6],c;
void findANS(int d){
    int i,mx;
    if(d==5){
        for(i=mx=0;i<2;i++) if(li[i]>mx) mx = li[i];
        for(;i<d&&li[i]<mx;i++);
        if(i<d&&li[i]==5){
            //c++;
            for(i = 0; i < 5; i++){
                printf("%d ",li[i]);
            }
            printf("\n");
        }else if(i==d) c++;
    }else{
        for(i = 1; i <= 5; i++){
            if(!isV[i]){
                li[d] = i;
                isV[i] = 1;
                findANS(d+1);
                isV[i] = 0;
            }
        }

    }
}
int main(){
    findANS(0);
    printf("c:%d\n",c);
}
