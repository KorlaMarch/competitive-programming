#include "stdio.h"

/*
TASK: Library
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

#define SIZE 1000001

int book[SIZE] = {};

int main(){
    int n1, n2, n3,c,i,x;
    int fcount;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 5; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);

        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        scanf("%d%d%d", &n1, &n2, &n3);
        for(i = 0; i < SIZE; i++){
            book[i] = 0;
        }
        c = 0;
        for(i = 0; i < n1; i++){
            scanf("%d", &x);
            if(!book[x]){
                c++;
                book[x] = 1;
            }
        }
        for(i = 0; i < n2; i++){
            scanf("%d", &x);
            if(!book[x]){
                c++;
                book[x] = 1;
            }
        }
        for(i = 0; i < n3; i++){
            scanf("%d", &x);
            if(!book[x]){
                c++;
                book[x] = 1;
            }
        }
        printf("%d\n", c);
    }
}
