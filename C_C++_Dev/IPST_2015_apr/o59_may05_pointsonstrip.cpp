#include "stdio.h"
#include "pointlib.h"
#include "algorithm"

int n,i,j,mx,xi,px,x;
int dis[3015][3015];
std::pair<int,int> sol[3015];
std::pair<int,int> p[3015];
int isOppo[3015];
bool isF;

void findOP(int x, int y){
    int d = dis[p[x].second][p[y].second];
    if(isOppo[p[x].second]!=isOppo[p[y].second]) while(1);
    for(int i = x+1; i < y; i++){
        if(dis[p[x].second][p[i].second]+dis[p[i].second][p[y].second]!=d) isOppo[p[i].second] = !isOppo[p[x].second];
        else isOppo[p[i].second] = isOppo[p[x].second];
    }
}

int main(){
    n = point_init();
    mx = -1;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            dis[i][j] = query(i,j);
            if(dis[i][j]>mx){
                mx = dis[i][j];
                xi = i;
            }
            //printf("%d ",dis[i][j]);
        }
        //printf("\n");
    }
    if(n==2){
        printf("0 0\n%d 1\n",dis[0][1]-1);
    }else{
        for(i = 0; i < n; i++){
            p[i].first = dis[xi][i];
            p[i].second = i;
            isOppo[i] = -1;
        }
        std::sort(p,p+n);
        isOppo[p[n-1].second] = 1;
        isOppo[p[0].second] = 0;
        isF = false;
        for(i = 1; i < n && !isF; i++){
            for(j = i+1; j < n; j++){
                if(dis[p[0].second][p[i].second]+dis[p[i].second][p[j].second]!=dis[p[0].second][p[j].second]){
                    isOppo[p[j].second] = 0;
                    isOppo[p[i].second] = 1;
                    isF = true;
                    break;
                }
            }
        }
        if(isF){
            i--;
            if(i!=1) findOP(0,j);
            //findOP(i,n-1);
            for(x = i+1; x < n; x++){
                if(dis[p[0].second][p[i].second]+dis[p[i].second][p[x].second]!=dis[p[0].second][p[x].second]) isOppo[p[x].second] = 0;
                else isOppo[p[x].second] = 1;
            }
        }else{
            for(i = 1; i < n; i++){
                isOppo[p[i].second] = 1;
            }
        }

        for(i = 0; i < n; i++){
            if(isOppo[p[i].second]==1){
                sol[p[i].second].first = p[i].first-1;
                sol[p[i].second].second = 1;
            }else{
                sol[p[i].second].first = p[i].first;
                sol[p[i].second].second = 0;
            }
            if(isOppo[p[i].second]==-1||sol[p[i].second].first<0||sol[p[i].second].first>1000000) while(1);
        }
        for(i = 0; i < n; i++){
            printf("%d %d\n",sol[i].first,sol[i].second);
        }
    }
}
