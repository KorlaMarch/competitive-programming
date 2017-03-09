#include "stdio.h"
#include "algorithm"
#include "vector"

struct Edge{
	int u,v;
	long long d;
	Edge(int _u = 0, int _v = 0, long long _d = 0) : u(_u), v(_v), d(_d) {}
};

bool cmp(Edge a, Edge b){
	return a.d<b.d;
}

typedef std::pair<int,int> PII;

int n,w,h,np;
int x[100005],y[100005];
int p[100005];
PII ep[100005];
std::vector<PII> ey,ex;
std::vector<Edge> ed;
long long sumD;

int unionF(int x){
	return x==p[x]?x:(p[x]=unionF(p[x]));
}

long long getD(int u, int v){
	return (x[u]-x[v])*(long long)(x[u]-x[v]) + (y[u]-y[v])*(long long)(y[u]-y[v]);
}

int main(){
	scanf("%d%d%d",&n,&w,&h);
	np = -1;
	for(int i = 0; i < n; i++){
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]!=0&&y[i]!=0&&x[i]!=w&&y[i]!=h){
			np = i;
		}
	}

	if(np!=-1){
		std::swap(x[np],x[n-1]);
		std::swap(y[np],y[n-1]);
		np = 1;
		n--;
	}else np = 0;


	for(int i = 0; i < n; i++){
		if(y[i]==0){
			ep[i].first = x[i];
			ey.push_back({x[i],i});
		}else if(x[i]==w){
			ep[i].first = w+y[i];
			ex.push_back({y[i],i});
		}else if(y[i]==h){
			ep[i].first = w+h+w-x[i];
			ey.push_back({x[i],i});
		}else{
			ep[i].first = w+h+w+h-y[i];
			ex.push_back({y[i],i});
		}
		
		ep[i].second = i;
	}

	std::sort(ep,ep+n);
	std::sort(ex.begin(),ex.end());
	std::sort(ey.begin(),ey.end());

	for(int i = 1; i < n; i++){
		ed.push_back(Edge( ep[i-1].second,ep[i].second,getD(ep[i-1].second,ep[i].second) ));
	}
	ed.push_back(Edge( ep[0].second,ep[n-1].second,getD(ep[0].second,ep[n-1].second) ));

	for(int i = 1; i < ex.size(); i++){
		if(x[ex[i-1].second]!=x[ex[i].second]){
			ed.push_back(Edge( ex[i-1].second,ex[i].second,getD(ex[i-1].second,ex[i].second) ));
		}
	}

	for(int i = 1; i < ey.size(); i++){
		if(y[ey[i-1].second]!=y[ey[i].second]){
			ed.push_back(Edge( ey[i-1].second,ey[i].second,getD(ey[i-1].second,ey[i].second) ));
		}
	}

	if(np){
		for(int i = 0; i < n; i++){
			ed.push_back(Edge( n,ep[i].second,getD(n,ep[i].second) ));
		}
	}

	std::sort(ed.begin(),ed.end(),cmp);

	for(int i = 0; i <= n; i++){
		p[i] = i;
	}

	for(Edge e : ed){
		if(unionF(e.u)!=unionF(e.v)){
			p[unionF(e.u)] = unionF(e.v);
			sumD += e.d;
		}
	}

	printf("%lld\n",sumD);

}