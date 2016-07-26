#include "stdio.h"
#include "vector"
#include "algorithm"

#define BUFFER 1000000

int n,m;
int a,b;
int p[100005];
std::vector<int> edge[100005];
std::vector<std::pair<int,int> > querry;
int jumpt[100005][20];
bool isV[100005];
int h[100005];

int unionF(int x){
	return x==p[x]?x:(p[x]=unionF(p[x]));
}

void genjump(int x, int o){
	
}

void flushQuerry(){
	for(int i = 1; i <= n; i++){
		isV[i] = false;
	}
	//do lca (in forest??)
	for(int i = 1; i <= n; i++){
		if(!isV[i]){
			genjump(i,0);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		p[i] = i;
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		if(unionF(a)==unionF(b)){
			querry.push_back({a,b});
		}else{
			edge[a].push_back(b);
			edge[b].push_back(a);
			p[unionF(b)] = unionF(a);
		}
		if(querry.size()>=BUFFER){
			flushQuerry();
		}
	}
	flushQuerry();

}