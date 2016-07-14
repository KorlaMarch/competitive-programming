#include "stdio.h"
int n,i,j;
char s[9],s2[9];
char isU[9];

int findANS(int d){
    int i,j;
    if(d>=9){
        return (s2[0]+s2[1]+s2[2]==15)&&(s2[3]+s2[4]+s2[5]==15)&&(s2[6]+s2[7]+s2[8]==15)&&
        (s2[0]+s2[3]+s2[6]==15)&&(s2[1]+s2[4]+s2[7]==15)&&(s2[2]+s2[5]+s2[8]==15)&&
        (s2[0]+s2[4]+s2[8]==15)&&(s2[2]+s2[4]+s2[6]==15);
    }else{
        if(s[d]>='0'&&s[d]<='9'){
            return findANS(d+1);
        }else{
            for(i = 1; i < 10; i++){
                if(!isU[i]){
                    s2[d] = i;
                    if(findANS(d+1)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        for(j = 0; j < 9; j++){
            scanf(" %c",&s[j]);
            s2[j] = s[j]-'0';
            isU[j] = 0;
        }
        for(j = 0; j < 9; j++){
            if(s[j]>='0'&&s[j]<='9') isU[s[j]-'0'] = 1;
        }
        if(findANS(0)){
            printf("Case #%d\n",i);
            for(j=0; j < 9; j++){
                if(!(s[j]>='0'&&s[j]<='9')){
                    printf("%c%c ",s[j],s2[j]+'0');
                }
            }
            printf("\n");
        }else{
            printf("Case #%d\n%d\n",i,0);
        }
    }
}
