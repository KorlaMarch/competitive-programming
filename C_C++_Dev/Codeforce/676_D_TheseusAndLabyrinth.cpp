#include "stdio.h"
#include "queue"

struct pos{
    int x,y,s;
    pos(int _x = 0, int _y = 0, int _s = 0) : x(_x), y(_y), s(_s) {}
};

int n,m,i,j,t;
char c;
bool isD[1005][1005][4];
bool isV[1005][1005][4];
std::queue<pos> qu[2];
pos b,e,no;
//top right bottom left
void setD(int x, int y, bool a, bool b, bool c, bool d){
    isD[x][y][0] = a;
    isD[x][y][1] = b;
    isD[x][y][2] = c;
    isD[x][y][3] = d;
}

void enq(int t, int x, int y, int s, int ox, int oy){
    if(x<1||x>n||y<1||y>m) return;
    if(isV[x][y][s]) return;
    // t = (4-s)%4
    // r = (5-s)%4
    // b = (6-s)%4
    // l = (7-s)%4
    //printf("CK %d %d %d %d %d\n",x,y,ox,oy,s);
    if(x<ox){
        if(!isD[ox][oy][(4-s)%4]||!isD[x][y][(6-s)%4]) return;
    }else if(x>ox){
        if(!isD[ox][oy][(6-s)%4]||!isD[x][y][(4-s)%4]) return;
    }

    if(y<oy){
        if(!isD[ox][oy][(7-s)%4]||!isD[x][y][(5-s)%4]) return;
    }else if(y>oy){
        if(!isD[ox][oy][(5-s)%4]||!isD[x][y][(7-s)%4]) return;
    }
    isV[x][y][s] = true;
    qu[t%2].push(pos(x,y,s));
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            scanf(" %c",&c);
            switch(c){
                case '+': setD(i,j,true,true,true,true); break;
                case '-': setD(i,j,false,true,false,true); break;
                case '|': setD(i,j,true,false,true,false); break;

                case '^': setD(i,j,true,false,false,false); break;
                case '>': setD(i,j,false,true,false,false); break;
                case 'v': setD(i,j,false,false,true,false); break;
                case '<': setD(i,j,false,false,false,true); break;

                case 'U': setD(i,j,false,true,true,true); break;
                case 'R': setD(i,j,true,false,true,true); break;
                case 'D': setD(i,j,true,true,false,true); break;
                case 'L': setD(i,j,true,true,true,false); break;
                case '*': setD(i,j,false,false,false,false); break;
            }
        }
    }
    scanf("%d%d %d%d",&b.x,&b.y,&e.x,&e.y);
    b.s = 0;
    qu[0].push(b);
    isV[b.x][b.y][0] = true;
    for(t = 0; !qu[t%2].empty(); t++){
        while(!qu[t%2].empty()){
            no = qu[t%2].front();
            qu[t%2].pop();
            //printf("get %d : %d %d %d\n",t,no.x,no.y,no.s);
            if(no.x==e.x&&no.y==e.y){
                printf("%d\n",t);
                return 0;
            }
            //stay here
            enq(t+1,no.x,no.y,(no.s+1)%4,no.x,no.y);
            //move
            enq(t+1,no.x+1,no.y,no.s,no.x,no.y);
            enq(t+1,no.x-1,no.y,no.s,no.x,no.y);
            enq(t+1,no.x,no.y+1,no.s,no.x,no.y);
            enq(t+1,no.x,no.y-1,no.s,no.x,no.y);
        }
    }
    printf("-1\n");
    return 0;
}
