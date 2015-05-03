#include "stdio.h"

/*
TASK: Speculator
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

int price[100001];
int n;

int main(){
    int i;
    int sum;
    int fcount;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &price[i]);

        }
        sum = 0;
        for(i = 1; i < n; i++){
            if(price[i] > price[i-1]){
                sum += price[i]-price[i-1];
            }
        }
        printf("%d\n", sum);
    }
}
