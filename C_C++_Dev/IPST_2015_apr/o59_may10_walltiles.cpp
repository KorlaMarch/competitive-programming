#include "stdio.h"
#include "algorithm"

int r,c,i,j,k,x,tmp;
int tile[31][1001];
int ans[31][1001];
bool isUse[35][1001];
bool useBF;
int canU[35];
int canUI[35];
int main(){
    scanf("%d%d",&r,&c);
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d",&tile[i][j]);
        }
    }
    for(k = 1; k <= r; k++) canUI[k] = c;
    for(i = 0; i < r; i++){
        for(k = 1; k <= r; k++) canU[k] = canUI[k];
        useBF = false;
        for(j = 0; j < c && !useBF; j++){
            for(k = 0; k < c; k++){
                if(!isUse[tile[i][j]][k]&&!ans[i][k]){
                    for(x = 1; x <= r; x++) if(!isUse[x][k]) canU[x]--;
                    isUse[tile[i][j]][k] = true;
                    ans[i][k] = tile[i][j];
                    canUI[tile[i][j]]--;
                    break;
                }
            }
            if(k==c){
                //printf("CAN'T FIND %d %d : %d\n",i,j,tile[i][j]);
                for(k = 0; k < c; k++){
                    if(!isUse[tile[i][j]][k]&&canU[ans[i][k]]){
                        tmp = ans[i][k];
                        isUse[tile[i][j]][k] = true;
                        isUse[tmp][k] = false;
                        ans[i][k] = tile[i][j];
                        canUI[tile[i][j]]--;
                        break;
                    }
                }
                //printf("swap with : %d (%d)\n",k,tmp);
                if(k==c){
                    useBF = true;
                }else for(k = 0; k < c; k++){
                    if(!ans[i][k]&&!isUse[tmp][k]){
                        for(x = 1; x <= r; x++) if(!isUse[x][k]) canU[x]--;
                        isUse[tmp][k] = true;
                        ans[i][k] = tmp;
                        break;
                    }
                }
            }
        }
        if(useBF){
            std::sort(tile[i],tile[i]+c);
            do{
                for(j = 0; j < c; j++){
                    if(isUse[tile[i][j]][j]) break;
                }
                if(j==c){
                    for(j = 0; j < c; j++){
                        canUI[ans[i][j]]++;
                        ans[i][j] = tile[i][j];
                        canUI[tile[i][j]]--;
                    }
                    break;
                }
            }while(std::next_permutation(tile[i],tile[i]+c));
        }
    }
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
