#include "stdio.h"
#include "vector"
#include "set"
int r,c,i,j,ti,k,t,lr,in,cu,x;
int ans[35][1005];
int co[35][35];
bool isuse[35],isin[35];
std::set<int> hrow[35];

void printSet(int ind){
    for(int x : hrow[ind]){
        printf("%d ",x);
    }
    printf("\n");
}

bool check(){
    int i,j;
    for(j = 0; j < c; j++){
        for(i = 1; i <= r; i++){
            isuse[i] = false;
        }
        for(i = 0; i < r; i++){
            if(ans[i][j]==0) while(1);
            isuse[ans[i][j]] = true;
        }
        for(i = 1; i <= r; i++){
            if(!isuse[i]){
                return false;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&r,&c);
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d",&ti);
            co[i][ti]++;
        }
    }
    for(j = 0; j < c; j++){
        //color
        //printf("J : %d\n",j);
        for(k = 1; k <= r; k++){
            hrow[k].clear();
            isuse[k] = false;
            isin[k-1] = false;
            for(i = 0; i < r; i++){
                if(co[i][k]) hrow[k].insert(i);
            }
            //printSet(k);
        }
        for(t = 0; t < r; t++){
            lr = -1;
            for(k = 1; k <= r; k++){
                if(!isuse[k]){
                    if(hrow[k].size()==1){
                        lr = k;
                        break;
                    }else lr = k;
                }
            }
            for(in = 0, cu = 0; in < r; in++){
                if(!isin[in]){
                    cu = 0;
                    for(k = 1; k <= r; k++){
                        if(!isuse[k]&&hrow[k].count(in)){
                            cu++;
                            x = k;
                        }
                    }
                    if(cu==1){
                        lr = x;
                        break;
                    }
                }
            }
            if(cu!=1) in = *(hrow[lr].begin());
            //printf("IN = %d %d %d\n",lr,in,hrow[lr].size());
            //while(isin[in]);
            ans[in][j] = lr;
            isin[in] = true;
            isuse[lr] = true;
            for(k = 1; k <= r; k++){
                hrow[k].erase(in);
            }
        }
        for(i = 0; i < r; i++){
            co[i][ans[i][j]]--;
        }
    }
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    //if(check()) while(1);
}
