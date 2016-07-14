#include "stdio.h"
#include "algorithm"
#include "vector"
using namespace std;
int n,m,i,j,x,y,a,b,cu;
vector<pair<int,int> > sw[102][102];
char isV[105][105],canR[105][105];
bool isadj(int x, int y){
    if(x>1&&isV[x-1][y]) return true;
    if(y>1&&isV[x][y-1]) return true;
    if(x<n&&isV[x+1][y]) return true;
    if(y<n&&isV[x][y+1]) return true;
    return false;
}
void toggle(int x, int y){
    if(!canR[x][y]||isV[x][y]) return;
    isV[x][y] = 1;
    for(vector<pair<int,int> >::iterator it = sw[x][y].begin(); it != sw[x][y].end(); ++it){
        if(!canR[it->first][it->second]&&!isV[it->first][it->second]){
            canR[it->first][it->second] = 1;
            cu++;
            if(isadj(it->first,it->second)) toggle(it->first,it->second);
        }
    }
    if(x>1&&canR[x-1][y]&&!isV[x-1][y]) toggle(x-1,y);
    if(y>1&&canR[x][y-1]&&!isV[x][y-1]) toggle(x,y-1);
    if(x<n&&canR[x+1][y]&&!isV[x+1][y]) toggle(x+1,y);
    if(y<n&&canR[x][y+1]&&!isV[x][y+1]) toggle(x,y+1);
}
int main(){
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d %d%d",&x,&y,&a,&b);
        sw[x][y].push_back(make_pair(a,b));
    }
    canR[1][1] = 1;
    cu = 1;
    toggle(1,1);
    printf("%d\n",cu);
}
