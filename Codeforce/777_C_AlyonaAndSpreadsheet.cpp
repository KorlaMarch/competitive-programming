#include "stdio.h"
#include "vector"
#include "queue"
#include "set"
#include "algorithm"

typedef std::pair<int,int> PII;

struct query{
	int l,r,id;
	query(int _l = 0, int _r = 0, int _id = 0) : l(_l), r(_r), id(_id) {}

	bool operator()(query a, query b){
		return a.l<b.l;
	}
};

bool cmp(query a, query b){
		return a.r<b.r;
}

bool cmp2(PII a, PII b){
	return a.second < b.second;
}

int n,m,x,k,l,r;
int lastB[100005];
bool sol[100005];
std::vector<int> a[100005];
std::vector<PII> sInterval;
std::vector<query> qu;
std::priority_queue<query,std::vector<query>, query> ev;
std::multiset<int> stP;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++){
		lastB[i] = 1;
	}

	a[0].resize(m,0);

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&x);
			a[i].push_back(x);
			if(a[i-1][j]>x){
				sInterval.push_back({lastB[j],i-1});
				lastB[j] = i;
			}
		}
	}
	for(int j = 0; j < m; j++){
		sInterval.push_back({lastB[j],n});
	}

	scanf("%d",&k);

	for(int i = 0; i < k; i++){
		scanf("%d%d",&l,&r);
		qu.push_back(query(l,r,i));
	}

	std::sort(sInterval.begin(),sInterval.end(),cmp2);
	std::sort(qu.begin(),qu.end(),cmp);

	int x = 0,y = 0;
	for(int i = 1; i <= n; i++){
		for(; x < qu.size() && i >= qu[x].r; x++){
			ev.push(qu[x]);
		}

		for(; y < sInterval.size() && i >= sInterval[y].second; y++){
			const int start = sInterval[y].first;
			while(!ev.empty()&&start<=ev.top().l){
				sol[ev.top().id] = true;
				ev.pop();
			}
		}
	}

	for(int i = 0; i < k; i++){
		if(sol[i]) printf("Yes\n");
		else printf("No\n");
	}
}