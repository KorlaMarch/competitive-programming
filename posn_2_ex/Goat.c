#include "stdio.h"
#include "stdlib.h"

int m,n;
int block[500][500];

struct p{
    int x;
    int y;
};

typedef struct p pos;

pos p[1000];

int flood(int x, int y, int hop){
    int sum = 1;
    int canHop,isfind = 0,h,h2 = block[x][y];
    block[x][y] = -1;
    p[hop].x = x;
    p[hop].y = y;
    //printf("look %d %d\n", x, y);
    if(x+1 == m && y+1 == n){
        return hop;
    }
    if(x > 0 && block[x-1][y] != -1 && block[x-1][y] >= h2-1 && block[x-1][y] <= h2+1){
        h = flood(x-1,y,hop+1);
        if(h) return h;
        isfind = 1;
    }
    if(x+1 < m && block[x+1][y] != -1 && block[x+1][y] >= h2-1 && block[x+1][y] <= h2+1){
        h = flood(x+1,y,hop+1);
        if(h) return h;
        isfind = 1;
    }
    if(y > 0 && block[x][y-1] != -1 && block[x][y-1] >= h2-1 && block[x][y-1] <= h2+1){
        h = flood(x,y-1,hop+1);
        if(h) return h;
        isfind = 1;
    }
    if(y+1 < n && block[x][y+1] != -1 && block[x][y+1] >= h2-1 && block[x][y+1] <= h2+1){
        h = flood(x,y+1,hop+1);
        if(h) return h;
        isfind = 1;
    }
    return 0;
}



int main(){
    int i, j, k,fcount;
    int x,y;
    int h;
    FILE* in;
    FILE* out;
    char inname[15];
    char outname[15];

    for(fcount = 0; fcount < 5; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        in = fopen(inname, "r");
        out = fopen(outname, "w+");

        fscanf(in,"%d%d", &m, &n);
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                fscanf(in,"%d", &block[i][j]);
            }
        }
        h = flood(0, 0, 0);
        if(h){
            fprintf(out, "1\n");
            for(i = 0; i <= h; i++){
                fprintf(out,"%d %d\n", p[i].x+1, p[i].y+1);
            }
        }else{
            fprintf(out, "0");
        }
    }
}
