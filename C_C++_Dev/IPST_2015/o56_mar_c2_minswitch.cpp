#include "stdio.h"
#include "vector"
#include "algorithm"

int n,m,i,j,a,b,co,minSW;
std::vector<int> edge[10005];
bool isSe[10005];
int minList[25];
void selectSW(int x, int seC){
    int i,j;
    int assLi[25];
    if(seC >= minSW) return;
    else if(x>n){
        if(seC < minSW){
            minSW = seC;
            for(i=1,j=0; i <= n; i++){
                if(isSe[i]){
                    minList[j++] = i;
                }
            }
        }
    }else if(!isSe[x]){
        //not Select
        if(edge[x].size()<=minSW){
            for(i=j=0; i < edge[x].size(); i++){
                if(!isSe[edge[x][i]]){
                    isSe[edge[x][i]] = true;
                    assLi[j++] = edge[x][i];
                }
            }
            selectSW(x+1,seC+j);
            for(i = 0; i < j; i++){
                isSe[assLi[i]] = false;
            }
        }
        //select
        if(edge[x].size()>1){
            isSe[x] = true;
            selectSW(x+1,seC+1);
            isSe[x] = false;
        }
    }else selectSW(x+1,seC);
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    minSW = 21;
    selectSW(1,co);
    printf("%d\n",minSW);
    for(i = 0; i < minSW; i++){
        printf("%d\n",minList[i]);
    }
}
