#include "stdio.h"

int main(){
    int i,j,k;
    char s[10001];
    scanf(" %s", s);
    for(i=0, j=k=1; s[i]&&(j||k); i++){
        if(s[i] >= 'A' && s[i] <= 'Z') k = 0;
        else j = 0;
    }
    if(!j&&!k)
        printf("Mix\n");
    else if(j){
        printf("All Capital Letter\n");
    }else{
        printf("All Small Letter\n");
    }
}
