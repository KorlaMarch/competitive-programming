#include "stdio.h"
#include "vector"
#include "algorithm"

#define MOD 33331

struct Edge{
	int a,b,w;
	Edge(int _a = 0, int _b = 0, int _w = 0) : a(_a),b(_b),w(_w) {}
};

bool cmp(Edge x, Edge y){
	return x.w < y.w;
}

typedef std::pair<int,int> PII;

int n,m,q,a,b,w,mx;
std::vector<Edge> edge;
std::vector<PII> ted[100005];
int mod2[10000005];
int unp[100005];
int p[100005][18];
int jw[100005][18];
int h[100005];

int unionFind(int x){
	return x==unp[x]?x:(unp[x]=unionFind(unp[x]));
}

void rooting(int x, int o, int w, int d){
	p[x][0] = o;
	jw[x][0] = w;
	h[x] = d;
	for(int i = 1; i < 18; i++){
		//make jump
		const int nxP = p[x][i-1];
		jw[x][i] = ( jw[x][i-1] + jw[nxP][i-1] )%MOD;
		p[x][i] = p[nxP][i-1];
	}

	for(PII pi : ted[x]){
		if(pi.first!=o){
			rooting(pi.first,x,mod2[pi.second],d+1);
		}
	}
}

int jumpLCA(int a, int b){
	int sumW = 0;
	//balance a and b height
	if(h[b]>h[a]) std::swap(a,b);

	//jump a
	for(int i = 17; h[a]!=h[b] && i >= 0; i--){
		if(h[p[a][i]]>=h[b]){
			sumW = (sumW+jw[a][i])%MOD;
			a = p[a][i];
		}
	}

	if(a==b) return sumW;

	//jump a and b together
	for(int i = 17; i >= 0; i--){
		if(p[a][i]!=p[b][i]){
			sumW = (sumW+jw[a][i]+jw[b][i])%MOD;
			a = p[a][i];
			b = p[b][i];
		}
	}

	return (sumW + jw[a][0] + jw[b][0])%MOD;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);

	for(int i = 1; i <= n; i++){
		unp[i] = i;
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&a,&b,&w);
		mx = std::max(mx,w);
		edge.push_back(Edge(a,b,w));
	}
	std::sort(edge.begin(),edge.end(),cmp);

	//cal mod 2
	mod2[0] = 1;
	for(int i = 1; i <= mx; i++){
		mod2[i] = (2*mod2[i-1])%MOD;
	}

	for(Edge& x : edge){
		if(unionFind(x.a)!=unionFind(x.b)){
			//printf("MST %d %d : %d\n",x.a,x.b,x.w);
			unp[unionFind(x.b)] = unp[unionFind(x.a)];
			ted[x.a].push_back({x.b,x.w});
			ted[x.b].push_back({x.a,x.w});
		}
	}

	rooting(1,0,0,1);

	for(int i = 0; i < q; i++){
		scanf("%d%d",&a,&b);
		//cal w
		printf("%d\n",jumpLCA(a,b));
	}
}