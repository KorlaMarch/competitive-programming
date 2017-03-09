#include "stdio.h"
#include "vector"
#include "set"

int n,k,x;
std::vector<int> win[100005];
std::set<int> notw;
int inD[100005];
bool isW[100005];

void setWin(int x){
	isW[x] = true;
	notw.erase(x);
	int i = 0;
	for(auto it = notw.begin(); it != notw.end();){
		while(i<win[x].size()&&win[x][i]<*it){
			i++;
		}
		if(i==win[x].size()||win[x][i]!=*it){
			const int y = *it;
			setWin(y);
			it = notw.upper_bound(y);
		}else it++;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&x);
			win[i].push_back(x);
			inD[x]++;
		}
		notw.insert(i);
	}

	int minD = n+1;
	int minP = 0;
	for(int i = 1; i <= n; i++){
		if(inD[i]<minD){
			minD = inD[i];
			minP = i;
		}
	}
	setWin(minP);

	printf("%d ",n-notw.size());
	for(int i = 1; i <= n; i++){
		if(isW[i]) printf("%d ",i);
	}
}