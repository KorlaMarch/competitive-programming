#include "stdio.h"

int n,i,j,k,t,c,y,Z;
char s[1000];

void genSeq(int x){
    int i;
    if(x<=1){
        if(x==1){
            for(y = 1; y <= 3; y++){
                c--;
                if(c<=0) return;
            }
        }else c--;
        return;
    }
    for(i = x==k?1:0; i <= 4; i++){
        s[x/2] = i;
        //printf("x=%d c=%d\n",x,c);
        genSeq(x-2);
        if(c<=0) return;
    }
}

int main(){
    /*n=0,i=0,j=0,k=0,t=0,c=0;
    for(Z=1;Z<=100;Z++){
    printf("\nZ=%4d :",Z);*/
    scanf("%d",&n);
    c = n;
    for(k = 1;c>0;k++){
        genSeq(k);
    }
    for(j = (k-1)/2; j > 0; j--){
        switch(s[j]){
            case 0: putchar('0'); break;
            case 1: putchar('1'); break;
            case 2: putchar('6'); break;
            case 3: putchar('8'); break;
            case 4: putchar('9'); break;
        }
    }
    if(k%2==0){
        switch(y){
            case 1: putchar('0'); break;
            case 2: putchar('1'); break;
            case 3: putchar('8'); break;
        }
    }
    for(j = 1;j <= (k-1)/2; j++){
        switch(s[j]){
            case 0: putchar('0'); break;
            case 1: putchar('1'); break;
            case 2: putchar('9'); break;
            case 3: putchar('8'); break;
            case 4: putchar('6'); break;
        }
    }
}
