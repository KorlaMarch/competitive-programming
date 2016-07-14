#include "stdio.h"

int n;

int main(){
    scanf("%d",&n);
    switch(n%3){
    case 0:
        printf("%d\n",n/3*2);
        break;
    case 1:
    case 2:
        printf("%d\n",n/3*2+1);
        break;
    }
}
