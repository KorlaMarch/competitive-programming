#include "stdio.h"

int main(){
    char c;
    int x=0,y=0;
    while((c=getchar())!='\n'){
        switch(c){
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
            case 'Z': x = 0; y = 0; break;
        }
    }
    printf("%d %d\n",x,y);
}
