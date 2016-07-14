#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

struct node{
	int v,i,j;
	node(int _v = 0, int _i = 0, int _j = 0) : v(_v), i(_i), j(_j) {}
	bool operator()(node a, node b){
		return a.v<b.v;
	}
};

int n,k,xi;
int a[10005],b[10005],c[10005];
std::vector<std::pair<int,int> > x[10005];
bool isV[1005];
int selectInd[10005];
std::priority_queue<node,std::vector<node>,node> qu;

int sum;

int main(){
	freopen("generators.in","r",stdin);
	freopen("generators.out","w+",stdout);
	scanf("%d%d",&n,&k);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d",&xi,&a[i],&b[i],&c[i]);
		x[i].push_back({xi,0});
		for(int j = 0; j < c[i]; j++) isV[j] = false;
		isV[xi] = true;
		for(int j = 1; true; j++){
			xi = (a[i]*x[i].back().first+b[i])%c[i];
			if(!isV[xi]){
				x[i].push_back({xi,j});
				isV[xi] = true;
			}else break;
		}
		std::sort(x[i].begin(),x[i].end());
		sum += x[i].back().first;
		if(x[i].size()>1) qu.push(node(x[i][ x[i].size()-2 ].first - x[i].back().first, i, x[i].size()-2));
		selectInd[i] = x[i].size()-1;
	}

	while(!qu.empty() && sum % k == 0){
		auto no = qu.top();
		qu.pop();
		if((sum+no.v)%k!=0){
			sum += no.v;
			selectInd[no.i] = no.j;
		}else{
			x[no.i].pop_back();
			if(x[no.i].size()>1){
				qu.push(node(no.v+x[no.i][x[no.i].size()-2].first-x[no.i].back().first,no.i,no.j-1));
			}
		}
	}
	if(sum%k){
		printf("%d\n",sum);
		for(int i = 0; i < n; i++){
			printf("%d ",x[i][selectInd[i]].second);
		}
	}else printf("-1\n"); 
}