#include "stdio.h"

int a,b,i;

int main(){
    scanf("%d%d",&a,&b);
    for(i = 0; a>0&&b>0; i++){
        if(a>b){
            a -= 2;
            b++;
        }else{
            b -= 2;
            a++;
        }
        if(a<0||b<0) break;
        //printf("%d %d\n",a,b);
    }
    printf("%d\n",i);
}
