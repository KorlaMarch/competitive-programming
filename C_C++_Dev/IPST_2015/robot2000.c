#include "stdio.h"

int main(){
    // O 1 2 3
    // N E S W
    char c,d=0;
    while((c=getchar())!='\n'){
        if(c=='Z'){
            putchar('Z');
            d = 0;
        }else{
            switch(c){
                case 'N': c=0; break;
                case 'E': c=1; break;
                case 'S': c=2; break;
                case 'W': c=3; break;
            }
            while(d!=c){
                putchar('R');
                d = (d+1)%4;
            }
            putchar('F');
        }
    }
}
