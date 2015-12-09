#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"
#define x first
#define y second
using namespace std;
int v,e,s,t,i,j,ui,vi,wi,d;
vector<pair<int,int>> edge[10005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
pair<int,int> tmp;
int main(){
    scanf("%d%d %d%d",&v,&e,&s,&t);
    for(i = 0; i < e; i++){
        scanf("%d%d%d",&ui,&vi,&wi);
        edge[ui].push_back(make_pair(wi,vi));
    }
    qu.push(make_pair(0,s));
    while(!qu.empty()){
        tmp = qu.top();
        //printf(":%d %d\n",tmp.x,tmp.y);
        qu.pop();
        if(tmp.y == t){
            if(d){
                printf("%d\n",tmp.x);
                break;
            }else{
                d = 1;
            }
        }
        for(vector<pair<int,int>>::iterator it = edge[tmp.y].begin(); it != edge[tmp.y].end(); ++it){
            qu.push(make_pair(it->x+tmp.x,it->y));
        }
    }
}
