#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;
typedef struct{
    bool operator()(pair<int,char> a, pair<int,char> b){
        return a.first>b.first;
    }
}cmp;
int p,i,j,d;
char x,y;
int minD[256];
bool isV[256];
pair<int,char> tmp;
vector<pair<char,int>> edge[256];
priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> qu;
int main(){
    scanf("%d",&p);
    for(i = 0; i < p; i++){
        scanf(" %c %c %d",&x,&y,&d);
        edge[x].push_back(make_pair(y,d));
        edge[y].push_back(make_pair(x,d));
    }
    for(i = 0; i < 256; i++){
        minD[i] = 1<<30;
    }
    qu.push(make_pair(0,'Z'));
    while(!qu.empty()){
        tmp = qu.top();
        qu.pop();
        if(tmp.second>='A'&&tmp.second<'Z'){
            break;
        }else if(!isV[tmp.second]){
            isV[tmp.second] = true;
            for(auto it = edge[tmp.second].begin(); it != edge[tmp.second].end(); ++it){
                if(!isV[it->first]&&it->second+tmp.first < minD[it->first]){
                    minD[it->first] = it->second+tmp.first;
                    qu.push(make_pair(it->second+tmp.first,it->first));
                }
            }
        }
    }
    printf("%c %d\n",tmp.second,tmp.first);
}
