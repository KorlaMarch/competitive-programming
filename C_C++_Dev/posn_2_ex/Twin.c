#include "stdio.h"

/*
TASK: Twin
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

int give[1000][2];
int n;
int min;

int abs(int n){
    return n <= 0 ? n*-1 : n;
}

void findMin(int sum, int pos){
    //printf("loop %d %d\n", sum, pos);
    if(pos == n){

        if(abs(sum) < min){
            min = abs(sum);
        }
        return;
    }

    findMin(sum-give[pos][0]+give[pos][1], pos+1);
    findMin(sum+give[pos][0]-give[pos][1], pos+1);
}

int main(){
    int fcount,i;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 5; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d%d", &give[i][0], &give[i][1]);
        }
        min = 99999;
        findMin(0, 0);
        printf("%d", min);
    }
}
