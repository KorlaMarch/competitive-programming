#include "stdio.h"

int main(){
    int p[2];
    int t,i,combo,bfTeam;
    scanf("%d", &p[0]);
    p[1] = p[0];
    while(1){
        scanf("%d", &t);
        i = (t+1)%2;
        if(bfTeam == t%2){
            combo++;
            if(combo >= 3){
                p[i] -= 3;
            }else{
                p[i]--;
            }
        }else{
            p[i]--;
            combo = 1;
            bfTeam = t%2;
        }
        if(p[i] <= 0){
            printf("%d\n%d\n", t%2, t);
            break;
        }
    }
}
