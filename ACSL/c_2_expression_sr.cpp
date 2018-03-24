#include "stdio.h"

char s[1000];
int loc[10];
bool isFirst;

int getind(char c){
    switch(c){
        case '(': return 1;
        case ')': return 2;
        case '[': return 3;
        case ']': return 4;
        case '{': return 5;
        case '}': return 6;
    }
    return 0;
}

bool isSign(char c){
    return c=='+'||c=='-'||c=='*'||c=='/';
}

int getV(char c){
    if(getind(c)){
        if(getind(c)%2){
            return 1;
        }else{
            return -1;
        }
    }
    return 0;
}

bool checkOper(int x, int y){
    for(int i = x; i <= y; i++){
        if(isSign(s[i])){
            return true;
        }
    }
    return false;
}

void print(int x){
    if(isFirst){
        printf("%d",x);
        isFirst = false;
    }else{
        printf(", %d",x);
    }
}

int main(){
    for(int t = 0; t < 5; t++){
        isFirst = true;
        scanf(" %s",s);
        for(int i = 0; i <= 6; i++){
            loc[i] = -1;
        }
        for(int i = 0; s[i]; i++){
            if(getind(s[i])){
                loc[getind(s[i])] = i;
            }
        }
        for(int i = 1; i <= 6; i++){
            if(loc[i]==-1){
                int stC = 0;
                if(i%2){
                    //open
                    for(int j = loc[i+1]+1; s[j]; j++){
                        stC += getV(s[j]);
                    }
                    for(int j = 0; j < loc[i+1]; j++){
                        //printf("J:%d %d\n",j,stC);
                        if(stC==0&&
                           (j==0||isSign(s[j-1])||getind(s[j-1]))&&!isSign(s[j])&&
                           checkOper(j+1,loc[i+1]-1)){
                            print(j+1);
                        }
                        stC += getV(s[j]);
                    }
                }else{
                    //close
                    for(int j = loc[i-1]; s[j]; j++){
                        //printf("J:%d %d\n",j,stC);
                        if(stC==0&&
                           !isSign(s[j])&&(!s[j+1]||isSign(s[j+1])||getind(s[j+1]))&&
                           checkOper(loc[i-1]+1,j)){
                            print(j+2);
                        }
                        stC += getV(s[j+1]);
                    }
                }
            }
        }
        printf("\n");
    }
}
