#include "stdio.h"
#include "string"
#include "map"
#include "set"

using namespace std;

int t,k,i,j,c,n;
int mx;
map<string,int> mp1,mp2;
set<int> st1,st2;
vector<int> edge[1005];
char a[30],b[30];
int na[30],nb[30];
bool se[30];

void dfs(int d){
    int i,j;
    if(d==n){
        st1.clear();
        st2.clear();
        for(i=j=0; i < n; i++){
            if(se[i]){
                st1.insert(na[i]);
                st2.insert(nb[i]);
            }else j++;
        }
        for(i = 0; i < n; i++){
            if(!se[i]){
                if(!st1.count(na[i])||!st2.count(nb[i])){
                    return;
                }
            }
        }
        if(j>mx) mx = j;
    }else{
        se[d] = true;
        dfs(d+1);
        se[d] = false;
        dfs(d+1);
    }
}

void maxflow(){

}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d",&n);
        c = 0;
        mx = 0;
        mp1.clear();
        mp2.clear();
        for(i = 0; i < n; i++){
            scanf( "%s %s",a,b);
            if(mp1.count(string(a))){
                na[i] = mp1[string(a)];
            }else{
                na[i] = c;
                mp1[string(a)] = c++;
            }
            if(mp2.count(string(b))){
                nb[i] = mp2[string(b)];
            }else{
                nb[i] = c;
                mp2[string(b)] = c++;
            }
        }
        //TODO: maxflow here
        //maxflow();
        dfs(0);
        printf("Case #%d: %d\n",k,mx);
    }
}
