#include "stdio.h"
#include "algorithm"
#include "vector"

struct event{
	int p,st;
	bool isS;

	event(int _p = 0, int _st = 0, bool _isS = false) : p(_p), st(_st), isS(_isS) {}
};

bool cmp(event a, event b){
	if(a.p==b.p){
		if(a.isS==b.isS){
			if(a.isS) return false;
			else return a.st>b.st;
		}else{
			return !a.isS;
		}
	}else return a.p<b.p;
}

int t,n,xi,ri;
std::vector<event> ev;
std::vector<int> comp;
int fen[300005];
long long ans;

void addFen(int x, int v){
	x = std::lower_bound(comp.begin(),comp.end(),x)-comp.begin()+1;
	for(; x <= comp.size(); x+=(x&-x)){
		fen[x] += v;
	}
}

int getFen(int x){
	int v = 0;
	x = std::lower_bound(comp.begin(),comp.end(),x)-comp.begin()+1;
	for(; x > 0; x-=(x&-x)){
		v += fen[x];
	}
	return v;
}

int main(){
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		ev.clear();
		comp.clear();
		ans = 0;

		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d%d",&xi,&ri);
			ev.push_back(event(xi-ri,xi-ri,true));
			ev.push_back(event(xi+ri,xi-ri,false));
			comp.push_back(xi-ri);
			comp.push_back(xi+ri);
			comp.push_back(xi+ri-1);
		}

		std::sort(ev.begin(),ev.end(),cmp);
		std::sort(comp.begin(),comp.end());

		for(event e : ev){
			if(e.isS){
				addFen(e.p,1);
			}else{
				ans += getFen(e.p-1)-getFen(e.st);
				addFen(e.st,-1);
			}
		}

		printf("%lld\n",ans);
	}
}