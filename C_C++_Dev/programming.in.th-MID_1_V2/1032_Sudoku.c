#include "stdio.h"
int main(){
    int n,i,j,x,y,k,s;
    int ori[9][9];
    int in[9][9];
    int num[2][9];
    scanf("%d",&n);
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            scanf("%d",&ori[i][j]);
        }
    }
    for(k = s = 0; k < n; k++){
        s = 0;
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                scanf("%d",&in[i][j]);
                if((ori[i][j]!=0&&ori[i][j]!=in[i][j]) || in[i][j] == 0){
                    s = 1;
                }
            }
        }
        for(i = 0; i < 9 && !s; i++){
            for(j = 0; j < 9; j++){
                num[0][j] = num[1][j] = 0;
            }
            for(j = 0; j < 9 && !s; j++){
                if(num[0][in[i][j]-1] || num[1][in[j][i]-1]){
                    s = 1;
                }else{
                    num[0][in[i][j]-1] = 1;
                    num[1][in[j][i]-1] = 1;
                }
            }
        }

        for(i = 0; i < 3 && !s; i++){
            for(j = 0; j < 3 && !s; j++){
                for(x = 0; x < 9; x++) num[0][x] = 0;
                for(x = 0; x < 3 && !s; x++){
                    for(y = 0; y < 3 && !s; y++){
                        if(num[0][in[i*3+x][j*3+y]-1]){
                            s = 1;
                        }else{
                            num[0][in[i*3+x][j*3+y]-1] = 1;
                        }
                    }
                }
            }
        }
        if(!s){
            printf("%d\n", k+1);
        }
    }
    printf("END\n");
}
