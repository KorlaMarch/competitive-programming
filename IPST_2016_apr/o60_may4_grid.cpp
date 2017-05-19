#include "stdio.h"
#include "vector"
#include "queue"

int w,h,n,m,a,b;
std::vector<int> edge[10005];
std::vector<int> path;
std::vector<int> deg2;
int deg[10005];
int ori[10005];
int xpos[10005],ypos[10005];

void trackPath(int x){
	if(x==-1) return;
	else{
		trackPath(ori[x]);
		path.push_back(x);
	}
}

void findPath(int a, int b){
	//clear data
	std::queue<int> qu;
	path.clear();
	for(int i = 1; i <= n; i++){
		ori[i] = 0;
	}

	qu.push(a);
	ori[a] = -1;
	while(!qu.empty()){
		int x = qu.front();
		qu.pop();
		if(x==b) break;
		for(int e : edge[x]){
			if(ori[e]==0){
				ori[e] = x;
				qu.push(e);
			}
		}
	}

	trackPath(b);
}

bool tryExpand(int lim){
	std::queue<int> qu[2];

	for(int i = 1; i <= n; i++){
		ori[i] = 0;
	}
	//printf("TRY : ");
	for(int i = 0; i < path.size(); i++){
		xpos[path[i]] = 0;
		ypos[path[i]] = i;
		qu[0].push(path[i]);
		ori[path[i]] = 1;
		//printf("%d ", path[i]);
	}
	//printf("\n");
	
	for(int i = 2; i <= lim; i++){
		const int i2 = i%2;
		//printf("SIZE %d %d\n",qu[i2].size(),qu[!i2].size());
		while(!qu[i2].empty()){
			int no = qu[i2].front();
			qu[i2].pop();

			bool isSet = false;
			for(int j = 0; j < edge[no].size(); j++){
				if(ori[edge[no][j]]==0){
					xpos[edge[no][j]] = i-1;
					ypos[edge[no][j]] = ypos[no];
					ori[edge[no][j]] = i;
					qu[!i2].push(edge[no][j]);
					//printf("SET %d %d\n",i-1,ypos[no]);
					isSet = true;
					break;
				}else if(ori[edge[no][j]]==i){
					return false;
				}
			}

			if(!isSet) return false;
		}
	}
	return true;
}

int main(){
	scanf("%d%d%d",&w,&h,&m);
	n = w*h;
	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	for(int i = 1; i <= n; i++){
		if(deg[i]==2){
			deg2.push_back(i);
		}
	}

	for(int i = 0; i < deg2.size(); i++){
		for(int j = i+1; j < deg2.size(); j++){

			findPath(deg2[i],deg2[j]);

			if(path.size()==w){
				if(tryExpand(h)){
					//inverse
					for(int i = 1; i <= n; i++){
						printf("%d %d\n",ypos[i],xpos[i]);
					}
					return 0;
				}
			}else if(path.size()==h){
				if(tryExpand(w)){
					for(int i = 1; i <= n; i++){
						printf("%d %d\n",xpos[i],ypos[i]);
					}
					return 0;
				}
			}
		}
	}

}