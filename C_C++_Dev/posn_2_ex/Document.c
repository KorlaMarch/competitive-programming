#include "stdio.h"

/*
TASK: Document
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM: Code::Blocks 12.11
*/

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int i,j,n,m,mi,fcount;
    int time[300][300];
    char inname[15];
    char outname[15];
    FILE* in;
    FILE* out;
    for(fcount = 0; fcount < 10; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname, "output%d.txt", fcount);
        in = fopen(inname, "r");
        out = fopen(outname, "w+");
        fscanf(in,"%d%d", &n, &m);
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                fscanf(in,"%d", &time[j][i]);
            }
        }

        for(i = 1; i < n; i++){
            for(j = 0; j < m; j++){
                if(j){
                    time[i][j] += min(time[i-1][j], time[i-1][j-1]);
                }else{
                    time[i][j] += min(time[i-1][j], time[i-1][m-1]);
                }
            }
        }
        /*for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                printf("%d ", time[j][i]);
            }
            printf("\n");
        }*/
        mi = time[n-1][0];
        for(i = 1; i < m; i++){
            if(time[n-1][i] < mi){
                mi = time[n-1][i];
            }
        }
        fprintf(out,"%d\n", mi);
    }
}
