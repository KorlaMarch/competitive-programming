#include "stdio.h"
int n,k,a,i,j,c,mp;
int page[100];
char day[100001],read[100001];

int main(){
    scanf("%d%d%d",&n,&k,&a);

    for(i=c=0; i < n; i++){
        scanf("%d", &page[i]);
        for(j = 0; j < page[i]; j++,c++){
            if(c-a>=0){
                if(a>=j) day[c] = day[c-a]+1;
                else day[c] = day[c-a];
                read[c] = read[c-a]+1;
            }else{
                day[c] = read[c] = 1;
            }
        }
    }
    for(i = 0, mp = -1; i < c; i++){
        printf("%d:%d %d %d %d\n",i,day[i],read[i],i-a*k,mp-a*k);
        if(read[i] >= k && (mp==-1||day[i]-day[i-a*k]>day[mp]-day[mp-a*k])) mp = i;
    }
    printf("%d %d\n",mp-a*(k-1)+1,day[mp]);
}
