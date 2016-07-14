#include "stdio.h"

int m,n;
int pipe[301][301];

int floodPipe(int x, int y, int callX, int callY){
    int sum = 1,i = pipe[x][y];
    if(i == 31){
        if(x > callX){
            pipe[x][y] = 22;
            if(x+1 < m){
                return 1+floodPipe(x+1,y,x,y);
            }else{
                return 1;
            }
        }else if(x < callX){
            pipe[x][y] = 22;
            if(x > 0){
                return 1+floodPipe(x-1,y,x,y);
            }else{
                return 1;
            }
        }else if(y > callY){
            pipe[x][y] = 21;
            if(y+1 < n){
                return 1+floodPipe(x,y+1,x,y);
            }else{
                return 1;
            }
        }else if(y < callY){
            pipe[x][y] = 21;
            if(y > 0){
                return 1+floodPipe(x,y-1,x,y);
            }else{
                return 1;
            }
        }
    }
    pipe[x][y] = 0;
    //N
    if(x-1 != callX && x > 0 && (i == 11 || i == 12 || i == 21) &&
        (pipe[x-1][y] == 13 || pipe[x-1][y] == 14 || pipe[x-1][y] == 21 || pipe[x-1][y] == 31)){
        sum += floodPipe(x-1,y,x,y);
    }
    //S
    if(x+1 != callX && x+1 < m && (i == 13 || i == 14 || i == 21) &&
        (pipe[x+1][y] == 11 || pipe[x+1][y] == 12 || pipe[x+1][y] == 21 || pipe[x+1][y] == 31)){
        sum += floodPipe(x+1,y,x,y);
    }
    //W
    if(y-1 != callY && y > 0 && (i == 11 || i == 13 || i == 22) &&
        (pipe[x][y-1] == 12 || pipe[x][y-1] == 14 || pipe[x][y-1] == 22 || pipe[x][y-1] == 31)){
        sum += floodPipe(x,y-1,x,y);
    }
    //E
    if(y+1 != callY && y+1 < n && (i == 12 || i == 14 || i == 22) &&
        (pipe[x][y+1] == 11 || pipe[x][y+1] == 13 || pipe[x][y+1] == 22 || pipe[x][y+1] == 31)){
        sum += floodPipe(x,y+1,x,y);
    }
    return sum;
}

void printPipeMap(){
    int x,y;
    printf("\n");
    for(x = 0; x < m; x++){
        for(y = 0; y < n; y++){
            printf("%d ", pipe[x][y]);
        }
        printf("\n");
    }
}

int main(){
    int i,j;
    int pl[10000];
    int plPtr = 0;
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &pipe[i][j]);
        }
    }

    for(i = 0; i < m; i++){
        if(pipe[i][0] != 0){
            pl[plPtr] = floodPipe(i,0,i,-1);
            plPtr++;
            //printPipeMap();
        }
        if(pipe[i][n-1] != 0){
            pl[plPtr] = floodPipe(i,n-1,i,n);
            plPtr++;
            //printPipeMap();
        }
    }

    for(i = 0; i < n; i++){
        if(pipe[0][i] != 0){
            pl[plPtr] = floodPipe(0,i,-1,i);
            plPtr++;
            //printPipeMap();
        }
        if(pipe[m-1][i] != 0){
            pl[plPtr] = floodPipe(m-1,i,m,i);
            plPtr++;
            //printPipeMap();
        }
    }
    printf("%d\n", plPtr);
    for(i = 0; i < plPtr; i++){
        printf("%d ", pl[i]);
    }
}
