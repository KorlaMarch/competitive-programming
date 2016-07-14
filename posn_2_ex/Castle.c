#include "stdio.h"

/*
TASK: Castle
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/


int m,n;
int block[500][500];

int flood(int x, int y){
    int sum = 1;
    block[x][y] = 1;
    if(x > 0 && !block[x-1][y]){
        sum += flood(x-1,y);
        //printf("xn\n");
    }
    if(x+1 < m && !block[x+1][y]){
        sum += flood(x+1,y);
        //printf("xp\n");
    }
    if(y > 0 && !block[x][y-1]){
        sum += flood(x,y-1);
        //printf("yn\n");
    }
    if(y+1 < n && !block[x][y+1]){
        sum += flood(x,y+1);
        //printf("yp\n");
    }
    return sum;
}

int main(){
    int i, j, k,maxBlock, count,max,fcount;
    int x,y;
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
        count = 0;
        max = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                fscanf(in,"%d", &block[i][j]);
            }
        }

        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(!block[i][j]){
                    //printf("inj\n");
                    k = flood(i,j);
                    count++;
                    /*for(x = 0; x < m; x++){
                        for(y = 0; y < n; y++){
                            printf("%d ", block[x][y]);
                        }
                        printf("\n");
                    }*/
                    if(k > max){
                        max = k;
                    }
                }
            }
        }

        fprintf(out,"%d\n%d\n", count, max);
    }
}
