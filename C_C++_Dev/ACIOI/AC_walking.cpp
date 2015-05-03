#include "stdio.h"
#include "algorithm"

int main(){
    int a,k,r,c;
    int i,j;
    char p;
    int jump[20];
    scanf("%d%d", &a, &k);
    for(i = 0; i < a; i++){
        scanf("%d", &jump[i]);
    }
    std::sort(jump, jump+a);
    for(i = 0; i < k; i++){
        scanf("%d%d", &r, &c);
        r--;
        c--;
        p = 0;
        while(!r && !c){
            if(jump[0] >= r){
                for(j = 0; jump[j] <= r; j++);
                r -= jump[j-1];
            }else if(jump[0] >= c){
                for(j = 0; jump[j] <= r; j++);
                c -= jump[j-1];
            }else{
                break;
            }
            p = (p+1)%2;
        }
        printf("%c ", p ? 'Y' : 'X');
    }
}
