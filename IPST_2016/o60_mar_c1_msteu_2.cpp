#include "stdio.h"
#include "algorithm"
#include "vector"

typedef std::pair<int,int> PII;

struct Edge{
	int x,y;
	long long t;
	Edge(int _x = 0, int _y = 0, long long _t = 0) : x(_x), y(_y), t(_t) {}
};

bool cmp(Edge a, Edge b){
	return a.t < b.t;
}

bool pocmp(PII a, PII b){
	return a.first*(long long)a.first + a.second*(long long)a.second < b.first*(long long)b.first + b.second*(long long)b.second;
}

int n;
PII point[100005];
int p[100005];
std::vector<Edge> edge;
long long sum;
long long mnX,mnY,mxX,mxY;

int unionFind(int x){
	return x==p[x]?x:(p[x]=unionFind(p[x]));
}

long long distance(PII a, PII b){
	return (a.first-b.first)*(long long)(a.first-b.first) + (a.second-b.second)*(long long)(a.second-b.second);
}




int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&point[i].first,&point[i].second);
		if(mnX)
	}

	findMST(0);

	std::sort(edge.begin(),edge.end(),cmp);

	for(Edge ed : edge){
		if(unionFind(ed.x)!=unionFind(ed.y)){
			//printf("ADD %d %d\n",ed.x,ed.y);
			p[unionFind(ed.y)] = unionFind(ed.x);
			sum += ed.t;
		}
	}

	printf("%lld\n",sum);
	
}