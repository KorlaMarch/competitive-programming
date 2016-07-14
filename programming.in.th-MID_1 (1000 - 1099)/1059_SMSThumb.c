#include "stdio.h"

char text[200];
int textpt = 0;

void appendChar(char c){
    text[textpt] = c;
    textpt++;
}

void delChar(int time){
    time++;
    textpt -= time;
    if(textpt < 0){
        textpt = 0;
    }
}

void runText(int s, int m){
    m--;
    switch(s){
    case 1:
        delChar(m);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        appendChar((s-2)*3+m%3+'A');
        break;
    case 7:
        appendChar('P' + m%4);
        break;
    case 8:
        appendChar('T' + m%3);
        break;
    case 9:
        appendChar('W' + m%4);
        break;
    }
}

int main(){
    int N, S, M;
    int i,x,y;
    scanf("%d%d%d",&N,&S,&M);
    runText(S, M);
    N--;
    for(i = 0; i < N; i++){
        scanf("%d%d%d",&x,&y, &M);
        S += x+y*3;
        runText(S, M);
    }
    text[textpt] = '\0';
    printf("%s\n", textpt == 0 ? "null" : text);
}
