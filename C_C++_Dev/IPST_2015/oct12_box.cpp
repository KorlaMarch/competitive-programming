#include "stdio.h"
#include "algorithm"
#include "queue"
#define f first
#define l second
int n,m,i,j,k;
bool isP;
char s[50][50];
int dis[50][50];
std::queue<std::pair<int,int>> qu;
std::pair<int,int> tmp;
bool canPlace(int x, int y){
    if(x>=0&&y>=0&&x+1<n&&y+1<m&&s[x][y]=='.'&&s[x][y+1]=='.'&&s[x+1][y]=='.'&&s[x+1][y+1]=='.'&&!dis[x][y]) return true;
    else return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf(" %s",s[i]);
    }
    isP = false;
    for(k = 1; k < m && !isP; k++){
        if(canPlace(0,k-1)){
            while(!qu.empty()) qu.pop();
            qu.push(std::make_pair(0,k-1));
            dis[0][k-1] = 1;
            while(!qu.empty()){
                tmp = qu.front();
                qu.pop();
                if(tmp.f == n-2){
                    isP = true;
                    break;
                }
                if(canPlace(tmp.f-1,tmp.l)){
                    qu.push(std::make_pair(tmp.f-1,tmp.l));
                    dis[tmp.f-1][tmp.l] = dis[tmp.f][tmp.l]+1;
                }
                if(canPlace(tmp.f+1,tmp.l)){
                    qu.push(std::make_pair(tmp.f+1,tmp.l));
                    dis[tmp.f+1][tmp.l] = dis[tmp.f][tmp.l]+1;
                }
                if(canPlace(tmp.f,tmp.l-1)){
                    qu.push(std::make_pair(tmp.f,tmp.l-1));
                    dis[tmp.f][tmp.l-1] = dis[tmp.f][tmp.l]+1;
                }
                if(canPlace(tmp.f,tmp.l+1)){
                    qu.push(std::make_pair(tmp.f,tmp.l+1));
                    dis[tmp.f][tmp.l+1] = dis[tmp.f][tmp.l]+1;
                }
            }
        }
    }
    if(isP) printf("yes\n");
    else printf("no\n");
    return 0;
}
