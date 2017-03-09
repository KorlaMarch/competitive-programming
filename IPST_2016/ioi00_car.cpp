#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"

int n,m,w;
int car[20005],expect[20005];
std::queue<int> invalid[60];
std::vector<std::vector<int>> ans;

int cycleSwap(int ind, int limw, int x){
	int uw = 0, y = x;
	for(; uw+1 < limw; uw++){
		//printf("y = %d (%d %d) : %d %d\n",y,car[y],expect[y],expect[x],car[y]==expect[x]);
		invalid[expect[y]].pop();
		if(car[y]==expect[x]){
			car[x] = car[y];
			ans[ind].push_back(y);
			ans[ind].push_back(x);
			return uw+1;
		}else{
			const int oy = y;
			ans[ind].push_back(y);
			y = invalid[car[oy]].front();
			ans[ind].push_back(y);
		}
	}
	//printf("ly = %d (%d %d) : %d %d\n",y,car[y],expect[y],expect[x],car[y]==expect[x]);
	invalid[expect[y]].pop();
	car[x] = car[y];
	ans[ind].push_back(y);
	ans[ind].push_back(x);
	if(car[x]!=expect[x]){
		invalid[expect[x]].push(x);
	}

	return limw;

}

int main(){
	scanf("%d%d%d",&n,&m,&w);
	for(int i = 1; i <= n; i++){
		scanf("%d",&car[i]);
		expect[i] = car[i];
	}
	
	std::sort(expect+1,expect+n+1);

	for(int i = 1; i <= n; i++){
		if(car[i]!=expect[i]){
			invalid[expect[i]].push(i);
		}
	}

	bool isF = true;
	for(int i = 0; isF; i++){
		
		ans.push_back(std::vector<int>());
		int uw = 0;
		isF = false;
		for(int j = 1; uw+1 < w && j <= m; j++){
			while(!invalid[j].empty()&&uw+1<w){
				//printf("call i = %d %d %d (%d)\n",i,w-uw,invalid[j].front(),j);
				uw += cycleSwap(i,w-uw,invalid[j].front());
				isF = true;
			}
		}
	}

	printf("%d\n",ans.size()-1);
	for(int i = 0; i < ans.size()-1; i++){
		printf("%d ", ans[i].size()/2);
		for(int j = 0; j < ans[i].size(); j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}

}