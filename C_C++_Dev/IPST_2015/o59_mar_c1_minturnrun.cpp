#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"

int n,m,s,i,j,minT;
char str[1000005];
std::vector<char> mp[1000005];
std::vector<int> dis[1000005];

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(i = 0; i < n; i++){
        scanf(" %s",str);
        for(j = 0; str[j]; j++){
            mp[i].push_back(str[j]);
            dis[i].push_back(10000000);
        }
    }
    dis[s-1][0] = 0;
    for(j = 0; j < m; j++){
        minT = 10000000;
        for(i = 0; i < n; i++){
            if(mp[i][j]=='#'){
                minT = 10000000;
            }else{
                if(minT<dis[i][j]){
                    dis[i][j] = minT;
                }
                if(dis[i][j]+2<minT){
                    minT = dis[i][j]+2;
                }
            }
        }
        minT = 10000000;
        for(i = n-1; i >= 0; i--){
            if(mp[i][j]=='#'){
                minT = 10000000;
            }else{
                if(minT<dis[i][j]){
                    dis[i][j] = minT;
                }
                if(dis[i][j]+2<minT){
                    minT = dis[i][j]+2;
                }
            }
        }
        for(i = 0; i < n; i++){
            if(mp[i][j]!='#'){
                dis[i][j+1] = dis[i][j];
            }
        }
    }
    minT = 10000000;
    for(i = 0; i < n; i++){
        if(mp[i][m-1]!='#'){
            if(dis[i][j]<minT){
                minT = dis[i][j];
            }
        }
    }
    if(minT == 10000000) printf("-1");
    else printf("%d\n",minT);
}
