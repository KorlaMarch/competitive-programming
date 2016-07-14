#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int n,i,j;
int num[10];
int deci[3][3][3] = {{{3,3,1},{3,1,2},{1,2,2}},{{1,3,2},{2,1,1},{3,3,2}},{{2,1,3},{1,2,1},{3,2,3}}};
int ask(int n, int r){
    int num1,num2;
    if(r==0) num1=num[1],num2=num[2];
    else if(r==1) num1=num[0],num2=num[2];
    else num1=num[0],num2=num[1];
    return deci[r][num1-1][num2-1];
}

bool checkSt(int n, int x){
    if(n==x){
        //for each attendee
        for(int i = 0; i < n; i++) printf("%d ",num[i]);
        printf(": ");
        int co = 0;
        for(int i = 0; i < n; i++){
            printf("%d ",ask(n,i));
            if(ask(n,i)==num[i]) co++;
            //if(ask(n,i)==num[i]) return true;
        }
        printf(" : CO = %d\n",co);
        //printf("Algo Error\n");
        return true;
    }else{
        //num can be 1 to n
        for(int i = 1; i <= n; i++){
            num[x] = i;
            if(!checkSt(n,x+1)) return false;
        }
    }
    return true;
}



int main(){
    //scanf("%d",&n);
    srand(time(NULL));
    while(1){
        /*for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    deci[i][j][k] = rand()%3+1;
                }
            }
        }*/
        if(checkSt(3,0)){
            printf("Decision : \n");
            int co[3] = {};
            for(int j = 0; j < 3; j++){
                for(int i = 0; i < 3; i++){
                    for(int k = 0; k < 3; k++){
                        printf("%d %d %d : %d\n",i+1,j+1,k+1,deci[i][j][k]);
                        co[deci[i][j][k]-1]++;
                    }
                }
            }
            printf("CO = %d %d %d\n",co[0],co[1],co[2]);
            return 0;
        }
    }
}
