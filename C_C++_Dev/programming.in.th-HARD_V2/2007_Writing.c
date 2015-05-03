#include "stdio.h"
short naF[58];
short checkF[58];
char str[3000];
int w,s,i,j,c;
int main(){
    scanf("%d%d", &w, &s);
    for(getchar(),i=0; i<w; i++){
        naF[getchar()-'A']++;
    }
    for(getchar(),i=0; i<w; i++){
        str[i] = getchar()-'A';
        checkF[str[i]]++;
    }
    for(i=w;i<s;i++){
        for(c++,j=0; j<=57; j++){
            if(naF[j]!=checkF[j]){
                c--; break;
            }
        }
        checkF[str[i%w]]--;
        str[i%w] = getchar()-'A';
        checkF[str[i%w]]++;
    }
    for(c++,j=0; j<=57; j++){
        if(naF[j]!=checkF[j]){
            c--; break;
        }
    }
    printf("%d\n",c);
}
