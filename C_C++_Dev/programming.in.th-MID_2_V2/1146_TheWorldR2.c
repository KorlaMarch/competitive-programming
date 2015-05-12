#include "stdio.h"
#include "string.h"
char upper(char c){
    return c>='a'?c-0x20:c;
}
int strc(char s[], char m[]){
    int i;
    for(i = 0; m[i]; i++){
        if(s[i]!=m[i]) return 0;
    }
    if(s[i]==m[i]) return 1;
    else return 0;
}

int n,q,p,i;
int town;
char s[6],t[256],isV[4];
int main(){
    scanf("%d%d%d", &n,&p,&q);
    for(i = 0; i < n; i++){
        scanf(" %5s %s", s, t);
        switch(s[0]){
        case 'D':
            if(!strc(t,"Eternal_City_Mac_Anu")) town++;
            isV[0] = 1;
            break;
        case 'O':
            if(!strc(t,"Warring_City_Lumina_Cloth")) town++;
            isV[1] = 1;
            break;
        case 'T':
            if(!strc(t,"Celestial_City_Dol_Dona")) town++;
            isV[2] = 1;
            break;
        case 'S':
            if(!strc(t,"Dual_City_Breg_Epona")) town++;
            isV[3] = 1;
            break;
        }
    }
    printf("%d\n", (isV[0]+isV[1]+isV[2]+isV[3]-1)*p+town*q*2);
}
