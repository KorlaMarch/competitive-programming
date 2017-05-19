#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 1000000000

typedef std::pair<int,int> PII;

struct Edge{
	int u,v,w;
	Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};

bool cmp(Edge a, Edge b){
	return a.w < b.w;
}

bool cmp2(Edge a, Edge b){
	if(a.u==b.u) return a.v < b.v;
	else return a.u < b.u;
}

int n;
int dis[3005][3005];
int rdis[3005][3005];
std::vector<Edge> edge;
int p[3005];
std::vector<Edge> newEdge;
std::vector<PII> adj[3005];
int minW,minU,minV;

int unionF(int x){
	return p[x]==x?x:(p[x]=unionF(p[x]));
}

void calDis(int x, int y, int d, int o){
	rdis[x][y] = d;
	for(PII pi : adj[y]){
		if(pi.first!=o){
			calDis(x,pi.first,d+pi.second,y);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		p[i] = i;
		for(int j = 1; j <= n; j++){
			if(i!=j){
				scanf("%d",&dis[i][j]);
				if(i<j) edge.push_back(Edge(i,j,dis[i][j]));
			}
		}
	}
	std::sort(edge.begin(),edge.end(),cmp);
	for(Edge x : edge){
		if(unionF(x.u)!=unionF(x.v)){
			newEdge.push_back(x);
			adj[x.u].push_back({x.v,x.w});
			adj[x.v].push_back({x.u,x.w});
			p[unionF(x.u)] = unionF(x.v);
		}
	}
	//cal real dis
	for(int i = 1; i <= n; i++){
		calDis(i,i,0,0);
	}
	minW = INF;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			//printf("%d %d : %d %d\n",i,j,dis[i][j],rdis[i][j]);
			if(dis[i][j]!=rdis[i][j]&&i<j){
				if(dis[i][j]<minW){
					minW = dis[i][j];
					minU = i;
					minV = j;
				}
			}
		}
	}
	newEdge.push_back(Edge(minU,minV,minW));

	std::sort(newEdge.begin(),newEdge.end(),cmp2);

	for(Edge x : newEdge){
		printf("%d %d %d\n",x.u,x.v,x.w);
	}

}