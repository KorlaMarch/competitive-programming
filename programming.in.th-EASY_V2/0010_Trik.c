#include "stdio.h"

int main(){
    int i,b=1;
    char c;
    while((c=getchar())!='\n'){
        if(c == 'A'){
            if(b==1) b = 2;
            else if(b==2) b = 1;
        }else if(c == 'B'){
            if(b==2) b = 3;
            else if(b==3) b = 2;
        }else{
            if(b==1) b = 3;
            else if(b==3) b = 1;
        }
    }
    printf("%d\n",b);
}
