#include "stdio.h"
#include "vector"
#include "algorithm"

#define MOD 1000000007

struct edge{
	int a,b,c;
	edge(int _a = 0, int _b = 0, int _c = 0) : a(_a), b(_b), c(_c) {}
};

bool cmp(edge a, edge b){
	return a.c<b.c;
}

int n,a,b,c;
std::vector<edge> edges;
int p[100005],co[100005];
unsigned long long sum;

int unionF(int x){
	return x==p[x]?x:(p[x]=unionF(p[x]));
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i < n; i++){
		scanf("%d%d%d",&a,&b,&c);
		edges.push_back(edge(a,b,c));
		p[i] = i;
		co[i] = 1;
	}
	p[n] = n;
	co[n] = 1;

	std::sort(edges.begin(),edges.end(),cmp);
	for(edge x : edges){
		sum = (sum+x.c*(unsigned long long)co[unionF(x.a)]*co[unionF(x.b)])%MOD;
		co[unionF(x.a)] += co[unionF(x.b)];
		p[unionF(x.b)] = unionF(x.a);
	}
	printf("%llu\n",sum);

}