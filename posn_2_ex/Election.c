#include "stdio.h"

/*
TASK: Election
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM: Code::Blocks 12.11
*/

int hash[10001] = {};

int main(){
    int fcount, i, j,x,count;
    int n[5];
    FILE* in;
    FILE* out;
    char inname[15];
    char outname[15];

    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        in = fopen(inname, "r");
        out = fopen(outname, "w+");

        for(i = 0; i <= 10000; i++){
            hash[i] = 0;
        }

        for(i = 0; i < 5; i++){
            fscanf(in,"%d", &n[i]);
        }

        for(i = 0; i < 5; i++){
            for(j = 0; j < n[i]; j++){
                fscanf(in,"%d", &x);
                hash[x]++;
            }
        }
        count = 0;
        for(i = 0; i <= 10000; i++){
            if(hash[i] >= 3){
                count++;
            }
        }
        fprintf(out,"%d\n", count);
    }
}
