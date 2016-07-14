#include "stdio.h"
#include "queue"
#include "vector"

int i,k,x,maxS,maxT;
bool isU[1000050];
std::queue<int> qu;
std::vector<int> ans;
int main(){
    for(k = 0; ; k++){
        scanf("%d",&x);
        if(x == 0) break;
        if(isU[x]){
            while(!qu.empty()&&isU[x]){
                isU[qu.front()] = false;
                qu.pop();
            }
        }
        isU[x] = true;
        qu.push(x);
        if(qu.size()>maxS){
            maxS = qu.size();
            if(maxT+1==k){
                ans.push_back(x);
            }else{
                ans.clear();
                while(!qu.empty()){
                    ans.push_back(qu.front());
                    qu.pop();
                }
                for(i = 0; i < ans.size(); i++){
                    qu.push(ans[i]);
                }
            }
            maxT = k;
        }
    }
    for(i = 0; i < ans.size(); i++){
        printf("%d\n",ans[i]);
    }
}
