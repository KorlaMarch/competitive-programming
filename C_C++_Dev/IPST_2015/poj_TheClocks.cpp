#include "stdio.h"
//                   1 2 3 4 5 6 7 8 9 10
int mat[9][10] =  { {1,1,0,1,0,0,0,0,0,0},
                    {1,1,1,0,1,0,0,0,0,0},
                    {0,1,1,0,0,1,0,0,0,0},
                    {1,0,0,1,1,0,1,0,0,0},
                    {1,0,1,0,1,0,1,0,1,0},
                    {0,0,1,0,1,1,0,0,1,0},
                    {0,0,0,1,0,0,1,1,0,0},
                    {0,0,0,0,1,0,1,1,1,0},
                    {0,0,0,0,0,1,0,1,1,0},
                };
int ans[9];
int minD[9];
int i,x;
/*int getLeading(int n){
    int i;
    for(i = 0; i < 9; i++){
        if(mat[n][i]) return i;
    }
    return -1;
}
void plusRow(int k, int s, int d){
    int i;
    for(i = 0; i < 10; i++){
        mat[d][i] = (mat[d][i]+k*mat[s][i])%4;
    }
}
int gussian(){
    int i,j,led;
    for(i = 0; i < 9; i++){
        led = getLeading(i);
        for(j = i+1; j < 9; j++){
            if(mat[j][led]!=0)
            plusRow((16-mat[j][led])/mat[i][led],i,j);
        }
    }
    for(i = 8; i >= 0; i--){
        for(led = 0; led < 9; led++){
            if(getLeading(led)==i) break;
        }
        ans[i] = mat[led][9]/mat[led][i];
        for(j = i+1; j < 9; j++){
            ans[i] -= ans[j]*mat[led][j];
        }
    }
}*/

void recur(int d){
    if(d==9){

    }
}

int main(){
    int j;
    for(i = 0; i < 9; i++){
        scanf("%d",&x);
        mat[i][9] = (4-x)%4;
    }
    //gussian();
    /*for(i = 0; i < 9; i++){
        for(j = 0; j < 10; j++){
            printf("%d ", mat[i][j]);
        }
        printf(":%d \n",ans[i]);
    }*/

}
