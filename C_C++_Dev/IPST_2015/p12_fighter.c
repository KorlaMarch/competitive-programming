#include "stdio.h"

int main(){
    int p,i,s,n,a,b,l;
    scanf("%d",&p);
    a=b=p;
    l=-1;
    for(i=0; i < 2*p; i++){
        scanf("%d",&n);
        if(n%2){
            if(l%2==0||l==-1){
                s = 1;
            }
            if(s>=3) a -= 3;
            else a--;
            if(a<=0){
                printf("1\n%d\n",n);
                break;
            }
        }else{
            if(l%2==1||l==-1){
                s = 1;
            }
            if(s>=3) b -= 3;
            else b--;
            if(b<=0){
                printf("0\n%d\n",n);
                break;
            }
        }
        l = n;
        s++;
    }
}
