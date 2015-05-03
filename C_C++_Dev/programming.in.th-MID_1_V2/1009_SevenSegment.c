#include "stdio.h"
char s[3][45];
char sin[16];
unsigned int a,b,na,nb;
unsigned int getNum(int n){
    unsigned int num=0,i,j;
    for(i = 0; i < 3; i++){
        scanf("%[^\n]",s[i]);
        getchar();
    }
    for(i = 0; i < 3; i++){
        for(j = 0; s[i][j]; j++);
        for(; j < 4*n+3; j++) s[i][j] = ' ';
    }
    for(i = 0; i < n; i++){
        num *= 10;
        if(s[0][4*i+1]==' '){
            if(s[1][4*i]==' '){
                num += 1;
            }else{
                num += 4;
            }
        }else{
            if(s[1][4*i]==' '){
                if(s[2][4*i]==' '){
                    if(s[1][4*i+1]==' '){
                        num += 7;
                    }else{
                        num += 3;
                    }
                }else{
                    num += 2;
                }
            }else{
                if(s[2][4*i] == ' '){
                    if(s[1][4*i+2] == ' '){
                        num += 5;
                    }else{
                        num += 9;
                    }
                }else{
                    if(s[1][4*i+2] == ' '){
                        num += 6;
                    }else{
                        if(s[1][4*i+1] == ' '){
                            num += 0;
                        }else{
                            num += 8;
                        }
                    }
                }
            }
        }
    }
    return num;
}
int main(){
    scanf("%d%d",&na,&nb);
    getchar();
    a = getNum(na);
    b = getNum(nb);
    printf("%u\n", a+b);
}
