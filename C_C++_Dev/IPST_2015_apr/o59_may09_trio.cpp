#include "stdio.h"

int n,i,j;
bool isP[505][505];

void printP(){
    int i,j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            printf("%d",isP[i][j]);
        }
        printf("\n");
    }
}

void place(int r, int c, int d){
    if(r>n||c>n) return;
    if(d==1){
        if(isP[r-1][c]||isP[r][c+1]) return;
        isP[r-1][c] = isP[r][c+1] = true;
    }else if(d==2){
        if(isP[r+1][c]||isP[r][c+1]) return;
        isP[r+1][c] = isP[r][c+1] = true;
    }else if(d==3){
        if(isP[r+1][c]||isP[r][c-1]) return;
        isP[r+1][c] = isP[r][c-1] = true;
    }else{
        if(isP[r-1][c]||isP[r][c-1]) return;
        isP[r-1][c] = isP[r][c-1] = true;
    }
    isP[r][c] = true;
    printf("%d %d %d\n",r,c,d);
}

void solvePi(int di, int dj, int b, int mode){
    int i,j;
    if(mode==0){
        place(b,dj-1,1);
        place(b,di+1,4);
        /*for(i = n,j = di+2; j < dj; i--,j++){
            place(i,j,1);
        }*/
    }else{
        place(dj-1,b,2);
        place(di+1,b,1);
        /*for(i = di+2,j = 1; j < dj; i++,j++){
            place(i,j,1);
        }*/
    }
}

void place12(){
    for(i = 0; i < 3; i++){
        place(6-i,1+i,1);
        place(12-i,7+i,1);
        place(5+i,5-i,3);
        place(8+i,8-i,3);
    }
    place(3,1,2);
    place(n,10,4);
    place(8,1,1);
    place(12,5,1);
}

int main(){
    scanf("%d",&n);
    if((int)(n/2.0*(n+1))%3==0&&n%2==0){
        for(i = n,j = 1; j <= n/2; i--,j++){
            place(i,j,1);
        }
        if(n!=2){
            solvePi(3,n,n,0);
            solvePi(1,n-2,1,1);
            if(n==8){
                place(4,1,1);
                place(3,3,3);
                place(8,5,1);
                place(6,6,3);
            }else if(n==12){
                place12();
            }
        }
        //printP();
    }else if(n==9){
        place(2,1,1);
        place(n,1,1);
        place(n,8,1);
        place(3,1,2);
        place(5,1,2);
        place(6,3,2);
        place(7,4,2);
        place(7,6,2);
        place(4,3,4);
        place(5,4,4);
        place(9,5,4);
        place(9,7,4);
        place(7,2,4);
        place(6,5,3);
        printP();
    }else printf("NO\n");
}
