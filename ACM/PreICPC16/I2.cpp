#include <stdio.h>

int X,Y;
char temp[1003], m[1001][1001];
int car[1001][1001][4];

bool inrange(int i, int j)
{
    int c = 2;
    if(i<0) c--;
    if(i==X) c--;
    if(j<0) c--;
    if(j==Y) c--;
    if(c==2)
        return true;
    else
        return false;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&X,&Y);
    for(i=0;i<X;i++){
        scanf("%s",&temp);
        for(j=0;j<Y;j++){
            m[i][j] = temp[j];
        }
    }


    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){

           //going down
           if(m[i][j]=='v'){
                if(inrange(i-1,j)){
                    car[i][j][0] = car[i-1][j][0]+1;
                }
                else {
                    car[i][j][0] = 1;
                }
           }

           //going right
           if(m[i][j]=='>'){
                if(inrange(i,j-1)){
                    car[i][j][1] = car[i][j-1][1]+1;
                }
                else{
                    car[i][j][1] = 1;
                }
           }
        }
    }

    for(i=X-1;i>=0;i--){
        for(j=Y-1;j>=0;j--){
           //going up
           if(m[i][j]=='^'){
                if(inrange(i+1,j)){
                    car[i][j][2] = car[i+1][j][2]+1;
                }
                else{
                    car[i][j][2] = 1;
                }
           }

           //going left
           if(m[i][j]=='<'){
                if(inrange(i,j+1)){
                    car[i][j][3] = car[i][j+1][3]+1;
                }
                else{
                    car[i][j][3] = 1;
                }
           }
        }
    }

    int dir[][2] = {{-1,0},{0,-1},{1,0},{0,1}},p,q,its;
    int mn=1000000, mncr[2];

    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            if(m[i][j]=='X'){
                its = 0;
                for(k=0;k<4;k++){
                    p = i + dir[k][0];
                    q = j + dir[k][1];

                    if(inrange(p,q)) {
                        //printf("\t%d\n",car[p][q][k]);
                        its += car[p][q][k];
                    }
                }
                //printf("%d %d %d\n",i,j,its);
                if(its < mn){
                    mn = its;
                    mncr[0] = i+1;
                    mncr[1] = j+1;
                }
           }
        }
    }
    /*for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            printf("%c ",m[i][j]);
        }
        printf("\n");
    }*/
    printf("%d %d",mncr[0],mncr[1]);
    return 0;
}
