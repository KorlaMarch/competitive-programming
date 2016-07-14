#include "stdio.h"

int main(){
    int n,i,c,maxP=0,maxC=0,maxS,sp=0;
    char maxD;
    int xi[100000],hi[100000];
    scanf("%d", &n);
    for(i=c=0; i < n; i++){
        scanf("%d%d", &xi[i], &hi[i]);
        if(maxP>xi[i]) c++;
        else{
            if(c>maxC){
                maxC = c;
                maxS = sp;
                maxD = 'R';
            }
            sp = i+1;
            c = 1;
        }
        if(xi[i]+hi[i]>maxP) maxP = xi[i]+hi[i];

    }
    if(c>maxC){
        maxC = c;
        maxS = sp;
        maxD = 'R';
    }

    for(i=n-1,c=0,maxP = xi[n-1]; i>=0; i--){
        if(maxP<xi[i]) c++;
        else{
            if(c>maxC||(c==maxC&&sp<=maxS)){
                maxC = c;
                maxS = sp;
                maxD = 'L';
            }
            sp = i+1;
            c = 1;
        }
        if(xi[i]-hi[i]<maxP) maxP = xi[i]-hi[i];

    }
    if(c>maxC||(c==maxC&&sp<=maxS)){
        maxC = c;
        maxS = sp;
        maxD = 'L';
    }

    printf("%d %c\n", maxS,maxD);
}
