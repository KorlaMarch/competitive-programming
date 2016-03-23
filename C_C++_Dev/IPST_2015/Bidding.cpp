#include "algorithm"
#include "cliclib.c"

int ni,i,lw,si,pot;
int isW[30005];
int numLi[400];
void place(int x){
    alojzy(x);
    if(x==1){
        n -= pot;
        pot = 1;
    }else{
        pot *= x;
    }
    x = bajtazar();
    if(x==1){
        n -= pot;
        pot = 1;
    }else{
        pot *= x;
    }
}
void passit(){
    //find the least to make stack to pass
    while(i!=si){
        for(i = 0; i < si && numLi[i]<=n; i++){
            if(isW[n-numLi[i]]&&numLi[i]%pot==0){
                if(numLi[i]==pot){
                    place(1);
                    return;
                }else if(!(numLi[i]%2)) place(2);
                else place(3);
                break;
            }
        }
    }
}
void play(){
    int i,j;
    if(isW[n]){

    }else{
        passit();
    }
}

void genNum(int n){
    if(ni>30000) return;
    numLi[si++] = n;
    genNum(ni*2);
    genNum(ni*3);
}

int main(){
    isW[1] = false;
    isW[2] = true;
    isW[3] = true;
    lw = 3;
    for(i = 4; i <= 30000; i++){
        if(lw*3>=i) isW[i] = false;
        else{
            isW[i] = true;
            printf("%d\n",i);
            lw = i;
        }
    }
    genNum(1);
    std::sort(numLi,numLi+si);
    n = inicjuj();
    pot = 1;
    play();
}
