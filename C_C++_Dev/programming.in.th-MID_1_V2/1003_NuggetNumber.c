#include "stdio.h"

int main(){
    int n,i;
    int is_nug[101] = {};
    scanf("%d",&n);
    is_nug[6] = is_nug[9] = is_nug[20] = 1;
    for(i = 1; i <= n; i++){
        if((i>=6&&is_nug[i-6])||(i>=9&&is_nug[i-9])||(i>=20&&is_nug[i-20])){
            is_nug[i] = 1;
        }
        if(is_nug[i]) printf("%d\n", i);
    }
    if(n<6) printf("no\n");
}
