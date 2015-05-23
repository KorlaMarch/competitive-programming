#include "stdio.h"
int na,nb,i;
int a[1000000],b[1000000];
long long suma,sumb;

int main(){
    scanf("%d%d",&na,&nb);
    for(i = 0; i < na; i++){
        scanf("%d",a+i);
        suma += a[i];
    }
    for(i = 0; i < nb; i++){
        scanf("%d",b+i);
        sumb += b[i];
    }
}
