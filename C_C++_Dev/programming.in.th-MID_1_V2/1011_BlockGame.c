#include "stdio.h"
char map[6][6];
char isV[6][6];
int n,m,l,x,y,s;
char c;

void upBlock(int,int);

void printMap(){
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}
int scanC(int x, int y, char t, char del){

    if(x<0||y<0||x>=m||y>=n||map[x][y] != t||isV[x][y]){
        return 0;
    }
    //printf("SC %d %d %c %d\n",x,y,t,del);
    isV[x][y] = 1;
    if(del) map[x][y] = '-';

    return scanC(x-1,y,t,del)+scanC(x+1,y,t,del)+scanC(x,y-1,t,del)+scanC(x,y+1,t,del)+1;
}
void clearV(){
    int i,j;
    for(i = 0; i< m; i++)
        for(j = 0; j < n; j++)
            isV[i][j] = 0;
}
void upPhy(int p){
    int i,b=m-1;
    //printf("  UP:%d\n", p);
    for(i = m-1; i >= 0; i--){
        if(map[i][p]=='#') b = i-1;
        else if(map[i][p] != '-'){
            if(b!=i){
                map[b][p] = map[i][p];
                map[i][p] = '-';
            }
            b=i-1;
        }
    }
}
void rePhy(){
    int i;
    for(i = 0; i < n; i++) upPhy(i);
}

void upBlock(int x,int y){
    int i,j;
    char t;
    //printf("UB:%d %d\n", x,y);
    for(i = y+1; i=='-'; i++);
    if(i-1!=y){
        map[x][i-1] = map[x][y];
        map[x][y] = '-';
        y = i-1;
    }
    t = map[x][y];
    clearV();
    j = scanC(x,y,map[x][y],1);
    if(j>1){
        s += j*5;
        rePhy();
    }else{
        map[x][y] = t;
    }
}
int main(){
    int i,j,k;
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf(" %c",&map[i][j]);
        }
    }

    scanf("%d",&l);
    for(i = 0; i < l; i++){
        scanf("%d %d %c", &x, &y, &c);
        if(map[x][y] >= 'A' && map[x][y] <= 'Z'){
            if(c == 'L'){
                if(y>0&&map[x][y-1] == '-'){
                    map[x][y-1] = map[x][y];
                    map[x][y] = '-';
                }else{
                    s -= 5;
                }
            }else{
                if(y+1<n&&map[x][y+1] == '-'){
                    map[x][y+1] = map[x][y];
                    map[x][y] = '-';
                }else{
                    s -= 5;
                }
            }
        }else{
            s -= 5;
        }
        rePhy();
        for(j = 0; j < m; j++){
            for(k = 0; k < n; k++){
                clearV();
                //printf("%d %d\n",j,k);
                if(map[j][k] >= 'A' && map[j][k]<= 'Z' && scanC(j,k,map[j][k],0)>1){
                    //printf("in");
                    upBlock(j,k);
                    j=k=0;
                }
            }
        }
        //printMap();
    }
    printf("%d\n",s);
    printMap();
}
