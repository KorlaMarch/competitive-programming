#include "stdio.h"

struct node{
    struct node* pointer[9];
    char table[9];
};



//0 = nothing
//1 = X win
//2 = O win
//3 = Draw
int checkWin(char t[]){
    int i, j;
    char Xwin = 0, Owin = 0;
    char winH, winV;
    char crossR = 1, crossL = 1;
    for(i = 0; i < 3; i++){
        winH = 1;
        winV = 1;
        for(j = 1; j < 3; j++){
            if(t[i*3 + j] != t[i*3 + (j - 1)]){
                winH = 0;
            }
            if(t[j*3 + i] != t[(j-1)*3 + i]){
                winV = 0;
            }
        }
        printf("%d %d\n", winH, winV);
        if(winH){
            if(t[i*3] == 'X'){
                Xwin = 1;
            }else if(t[i*3] == 'O'){
                Owin = 1;
            }
        }else if(winV){
            if(t[i] == 'X'){
                Xwin = 1;
            }else if(t[i] == 'O'){
                Owin = 1;
            }
        }
        if(i > 0){
            if(t[i*3 + i] != t[4*i - 3 + i-1]){
                crossL = 0;
            }
            if(t[i*2 + 2] != t[(i-1)*3 + (3-i)]){
                crossR = 0;
            }
        }
    }

    if(crossL == 1){
        if(t[0] == 'X'){
            Xwin = 1;
        }else if(t[0] == 'O'){
            Owin = 1;
        }
    }
    if(crossR == 1){
        if(t[2] == 'X'){
            Xwin = 1;
        }else if(t[2] == 'O'){
            Owin = 1;
        }
    }

    if(Xwin && Owin){
        return 3;
    }else if(Xwin){
        return 1;
    }else if(Owin){
        return 2;
    }else{
        return 0;
    }
}

int main(){
    char t[9];
    int n;
    char c;
    for(n = 0; n < 9; ){
        c = getchar();
        if(c != '\n'){
            t[n] = c;
            n++;
        }
    }

    for(n = 0; n < 9; n++){
        printf("%c ", t[n]);
    }
    printf("%d\n", checkWin(t));
}
