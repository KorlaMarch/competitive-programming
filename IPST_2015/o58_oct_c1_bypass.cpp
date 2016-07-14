#include "stdio.h"
#include "vector"
#include "algorithm"
#include "stack"
#define v first
#define cu second
using namespace std;
int n,i,j,a,b,se,mx;
vector<pair<int,int>> edge[100005];
stack<int> oneS;
int deg[100005],sum[100005];
int trk[5];
char isP[100005];

void dfs(int x, int p, int d){
    trk[d] = x;
    if(d>=3){
        int sumA=1,sumB=1;
        for(auto it = edge[p].begin(); it != edge[p].end(); ++it){
            if(it->v != trk[1]){
                sumA += it->cu;
            }
        }
        //printf("\nTH\n");
        for(auto it = edge[x].begin(); it != edge[x].end(); ++it){
            if(it->v != trk[d-1]){
                //printf("(%d %d)",it->v,it->cu);
                sumB += it->cu;
            }
        }
        if(sumA*sumB>mx){
            //printf("MX %d %d %d %d\n",p,x,sumA,sumB);
            //printf("%d %d %d %d %d\n",trk[0],trk[1],trk[2],trk[3],trk[4]);
            mx = sumA*sumB;
        }
    }else{
        for(auto it = edge[x].begin(); it != edge[x].end(); ++it){
            if(!d||trk[d-1]!=it->v) dfs(it->v,p,d+1);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(i=1; i < n; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(make_pair(b,0));
        edge[b].push_back(make_pair(a,0));
        deg[a]++;
        deg[b]++;
    }
    for(i = 1; i <= n; i++){
        if(deg[i]==1){
            oneS.push(i);
            sum[i] = 1;
            isP[i] = 1;
        }
    }
    while(!oneS.empty()){
        se = oneS.top();
        oneS.pop();
        for(vector<pair<int,int>>::iterator it = edge[se].begin();it!=edge[se].end(); ++it){
            if(!isP[it->v]){
                it->cu = n-sum[se];
                sum[it->v] += sum[se];
                deg[it->v]--;
                //printf(":%d %d :%d %d\n",se,it->v,sum[se],it->cu);
                if(deg[it->v]<=1){
                    isP[it->v] = 1;
                    sum[it->v]++;
                    oneS.push(it->v);
                }
            }else{
                it->cu = sum[it->v];
                //printf(" CU = %d %d->%d\n",se,it->v,it->cu);
            }
        }
    }
    for(i = 1; i <= n; i++){
        dfs(i,i,0);
    }
    printf("%d\n",mx);
}
