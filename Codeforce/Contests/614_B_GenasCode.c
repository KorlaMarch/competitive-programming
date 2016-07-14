#include "stdio.h"

int n,i,j,c,isZ;
char s[100020],f[100020];

int isBeau(){
    int r;
    if(s[0]!='1') return 0;
    for(r=1;s[r]&&s[r]=='0';r++);
    if(s[r]) return 0;
    else return r;
}
void addP(){
    int i=isBeau(),j;
    if(i){
        c += i-1;
    }else{
        for(i=j=0; s[j]; i++,j++){
            f[i] = s[j];
        }
        f[i] = '\0';
    }
}

int main(){
    f[0] = '1';
    f[1] = '\0';
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %s",s);
        if(s[0]=='0'&&s[1]=='\0') isZ = 1;
        else addP();
    }
    if(isZ){
        printf("0\n");
    }else{
        printf("%s",f);
        for(i = 0; i < c; i++){
            putchar('0');
        }
    }
}
