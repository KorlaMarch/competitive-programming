#include "stdio.h"

int boss[10001];
bool packet[10001][10001];

void signPacket(int x, int num){
    packet[x]
}

int main(){
    int n,m,t,x,y,i,c = 0;
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d",&t);
        switch(t){
        case 1:
            scanf("%d%d",&x,&y);
            boss[x] = y;
            break;
        case 2:
            scanf("%d", &x);
            signPacket(x, c);
            c++;
            break;
        case 3:
            break;
        }
    }
}
