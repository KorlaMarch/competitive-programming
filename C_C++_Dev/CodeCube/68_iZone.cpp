#include "stdio.h"

//B R G
int fen[3][1000500];
char color[1000500];
int n,m,i,j,A,x,y,R,G,B;
char c;
void add(char ch, int p, int v){
    for(;p <= n; p += (p&-p)) fen[ch][p] += v;
}
int get(char ch, int p){
    int s;
    for(s = 0; p > 0; p -= (p&-p)) s += fen[ch][p];
    return s;
}
int main(){
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        add(i%3,i,1);
        color[i] = i%3;
    }
    for(i = 0; i < m; i++){
        scanf("%d",&A);
        if(A == 1){
            scanf("%d %c", &x, &c);
            switch(c){
                case 'R': c = 1; break;
                case 'G': c = 2; break;
                case 'B': c = 0; break;
            }
            add(color[x],x,-1);
            add(c,x,1);
            color[x] = c;
        }else{
            scanf("%d %d", &x, &y);
            R = get(1,y)-get(1,x-1);
            G = get(2,y)-get(2,x-1);
            B = get(0,y)-get(0,x-1);
            if(R>G&&R>B) printf("R\n");
            else if(G>R&&G>B) printf("G\n");
            else if(B>R&&B>G) printf("B\n");
            else printf("None\n");
        }
    }
}
