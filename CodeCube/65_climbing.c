#include "stdio.h"

int min(int a, int b){
    return a<b?a:b;
}

int main(){
    int n,a,b,c,i;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(i = 0; i < n; i++){
        switch(i%3){
        case 0:
            if(b>a&&c>a) a += (min(b,c)-a)*2;
            else if(b>a) a += (b-a)*2;
            else if(c>a) a += (c-a)*2;
            break;
        case 1:
            if(a>b&&c>b) b += (min(a,c)-b)*2;
            else if(a>b) b += (a-b)*2;
            else if(c>b) b += (c-b)*2;
            break;
        case 2:
            if(a>c&&b>c) c += (min(a,b)-c)*2;
            else if(a>c) c += (a-c)*2;
            else if(b>c) c += (b-c)*2;
            break;
        }
    }
    printf("%d\n%d\n%d\n",a,b,c);
}
