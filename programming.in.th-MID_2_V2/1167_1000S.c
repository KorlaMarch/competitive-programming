#include "stdio.h"
char s[128];
int fq[4],d[2];
int k,i;

int main(){
    scanf(" %s %d",s,&k);
    for(i = 0; s[i]; i++){
        switch(s[i]){
            case 'N': fq[0]++; break;
            case 'S': fq[1]++; break;
            case 'E': fq[2]++; break;
            case 'W': fq[3]++; break;
        }
    }
    if(fq[0]>=fq[1]){
        d[0] += fq[0];
        d[1] += fq[1];
    }else{
        d[0] += fq[1];
        d[1] += fq[0];
    }
    if(fq[2]>=fq[3]){
        d[0] += fq[2];
        d[1] += fq[3];
    }else{
        d[0] += fq[3];
        d[1] += fq[2];
    }

    if(k<=d[1]) printf("%d\n",(d[0]-d[1]+k)*2);
    else printf("%d\n",(d[0]-k+d[1])*2);

}
