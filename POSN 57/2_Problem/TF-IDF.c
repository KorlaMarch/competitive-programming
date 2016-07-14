#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* sa[1000];
int feq[1000];

int main(){
    int n,i,j,h,find,max;
    char* s;
    scanf("%d", &n);
    for(i=h=0; i < n; i++){
        s = (char*)malloc(sizeof(char)*64);
        scanf(" %s", s);
        for(j=find=0; j < h&&!find; j++){
            if(strcmp(s,sa[j])==0){
                feq[j]++;
                free(s);
                find = 1;
            }
        }
        if(!find){
            feq[h] = 1;
            sa[h++] = s;
        }
    }
    for(i=1,max=0; i < h; i++){
        if(feq[i]>feq[max]||(feq[i]==feq[max]&&strcmp(sa[i],sa[j])>0)) max = i;
    }
    printf("%s %d\n",sa[max],feq[max]);
}
