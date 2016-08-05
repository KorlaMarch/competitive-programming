#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"


int n,m;
std::vector<std::vector<int> > mtx;
std::priority_queue<std::pair<int,int>> qu;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		mtx.push_back(std::vector<int>(m));
		for(int j = 0; j < m; j++){
			scanf("%d",&mtx[i][j]);
		}
	}
	for(int i = 1; i < n; i++){
		std::sort(mtx[i].begin(),mtx[i].end());
		int x = mtx[i][0], c = 1;
		for(int j = 1; j < m; j++){
			if(mtx[i][j]==mtx[i][j-1]){
				c++;
			}else{
				qu.push({c,x});
				x = mtx[i][j];
				c = 1;
			}
		}
		qu.push({c,x});

		for(int j = 0; j < m; j++){
			auto pi = qu.top();
			qu.pop();
			if(pi.second==mtx[i-1][j]){
				if(qu.empty()){
					printf("-1\n");
					return 0;
				}else{
					auto pi2 = qu.top();
					qu.pop();
					mtx[i][j] = pi2.second;
					pi2.first--;
					if(pi2.first!=0) qu.push(pi2);
					qu.push(pi);
				}
			}else{
				mtx[i][j] = pi.second;
				pi.first--;
				if(pi.first!=0) qu.push(pi);
			}
			printf("%d %d : %d\n",i,j,mtx[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", mtx[i][j]);
		}
		printf("\n");
	}
}