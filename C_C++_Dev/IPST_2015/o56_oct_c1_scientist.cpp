#include "stdio.h"
#include "queue"
#define LIM 20
typedef struct{
    int a,b,c;
}tran;
tran getTran(int a, int b, int c){
    tran tmp;
    tmp.a = a;
    tmp.b = b;
    tmp.c = c;
    return tmp;
}
tran ma[3];
tran s,e,t;
int minT[LIM][LIM][LIM];
char ch[LIM][LIM][LIM];
char str[10000];
std::queue<tran> qu;
int n,i,sol,st,x,y,z;
void clearA(){
    int i,j,k;
    for(i = 0; i < LIM; i++){
        for(j = 0; j < LIM; j++){
            for(k = 0; k < LIM; k++){
                minT[i][j][k] = 0;
                ch[i][j][k] = 0;
            }
        }
    }
}
void pushQ(int a, int b, int c,int da,int db, int dc, char cr, int t){
    if(a>=0&&b>=0&&c>=0&&a+da<LIM&&b+db<LIM&&c+dc<LIM&&!minT[a+da][b+db][c+dc]){
        ch[a+da][b+db][c+dc] = cr;
        minT[a+da][b+db][c+dc] = t;
        qu.push(getTran(a+da,b+db,c+dc));
    }
}
int main(){
    scanf("%d%d%d",&ma[0].a,&ma[0].b,&ma[0].c);
    scanf("%d%d%d",&ma[1].a,&ma[1].b,&ma[1].c);
    scanf("%d%d%d",&ma[2].a,&ma[2].b,&ma[2].c);
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d %d%d%d",&s.a,&s.b,&s.c,&e.a,&e.b,&e.c);
        clearA();
        qu.push(getTran(s.a,s.b,s.c));
        minT[s.a][s.b][s.c] = 1;
        sol = 0;
        while(!qu.empty()){
            t = qu.front();
            if(t.a==e.a&&t.b==e.b&&t.c==e.c){
                sol = 1;
                break;
            }
            qu.pop();
            pushQ(t.a-1,t.b,t.c,ma[0].a,ma[0].b,ma[0].c,'A',minT[t.a][t.b][t.c]+1);
            pushQ(t.a,t.b-1,t.c,ma[1].a,ma[1].b,ma[1].c,'B',minT[t.a][t.b][t.c]+1);
            pushQ(t.a,t.b,t.c-1,ma[2].a,ma[2].b,ma[2].c,'C',minT[t.a][t.b][t.c]+1);
            pushQ(t.a-ma[0].a,t.b-ma[0].b,t.c-ma[0].c,1,0,0,'a',minT[t.a][t.b][t.c]+1);
            pushQ(t.a-ma[1].a,t.b-ma[1].b,t.c-ma[1].c,0,1,0,'b',minT[t.a][t.b][t.c]+1);
            pushQ(t.a-ma[2].a,t.b-ma[2].b,t.c-ma[2].c,0,0,1,'c',minT[t.a][t.b][t.c]+1);
        }

        if(sol){
            for(st=0,x=e.a,y=e.b,z=e.c; ch[x][y][z];){
                str[st++] = ch[x][y][z];
                switch(ch[x][y][z]){
                case 'a':
                    x = x-1+ma[0].a, y = y+ma[0].b, z = z+ma[0].c;
                    break;
                case 'b':
                    x = x+ma[1].a, y = y-1+ma[1].b, z = z+ma[1].c;
                    break;
                case 'c':
                    x = x+ma[2].a, y = y+ma[2].b, z = z-1+ma[2].c;
                    break;
                case 'A':
                    x = x+1-ma[0].a, y = y-ma[0].b, z = z-ma[0].c;
                    break;
                case 'B':
                    x = x-ma[1].a, y = y+1-ma[1].b, z = z-ma[1].c;
                    break;
                case 'C':
                    x = x-ma[2].a, y = y-ma[2].b, z = z+1-ma[2].c;
                    break;
                }
                //if(!(x>=0&&y>=0&&z>=0&&x<LIM&&y<LIM&&z<LIM)) while(1);
            }
            printf("%d ",minT[e.a][e.b][e.c]-1);
            while(--st>=0){
                putchar(str[st]);
            }
            putchar('\n');
        }else printf("NO SOLUTION\n");
    }
}
