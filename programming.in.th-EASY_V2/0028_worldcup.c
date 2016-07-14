#include "stdio.h"
int i,j,x,m;
char s[4][21],li[4] = {0,1,2,3};
int score[4][4],state[4][3];

int main(){
    for(i=0;i<4;i++) scanf(" %s", s[i]);
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            scanf("%d",&score[i][j]);
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i!=j){
                if(score[i][j] > score[j][i]) state[i][0] += 3;
                else if(score[i][j] == score[j][i]) state[i][0] += 1;
                state[i][1] += score[i][j];
                state[i][2] += score[j][i];
            }
        }
    }
    for(i=0;i<4;i++){
        m=i;
        for(j=i+1;j<4;j++){
            if(state[li[j]][0]!=state[li[m]][0]?state[li[j]][0]>state[li[m]][0]:(
               (state[li[j]][1]-state[li[j]][2]!=state[li[m]][1]-state[li[m]][2])?(state[li[j]][1]-state[li[j]][2]>state[li[m]][1]-state[li[m]][2]):
               state[li[j]][1]>state[li[m]][1])){
                m = j;
            }
        }
        printf("%s %d\n",s[li[m]],state[li[m]][0]);
        li[m] = li[i];
    }

}
