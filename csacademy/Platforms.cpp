#include "stdio.h"
#include "algorithm"
#include "vector"
#include "set"

#define INF 500000000

typedef std::pair<int,int> Pii;


int n,m;
Pii pl[100005];
std::vector<Pii> ho;
std::set<Pii> hoSet;
int po[100005];
long long sum;
int dis1,dis2;

bool cmp(Pii a, Pii b){
	return (a.second-a.first)>(b.second-b.first);
}

int distance(Pii a, Pii b){
	if(a.first<=b.first&&a.second>=b.second){
		return 0;
	}else if(a.first<=b.first){
		return b.first-a.first;
	}else if(a.second>=b.second){
		return a.second-b.second;
	}else return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&pl[i].first,&pl[i].second);
	}
	for(int i = 0; i < m; i++){
		scanf("%d",&po[i]);
	}
	std::sort(pl,pl+n,cmp);
	std::sort(po,po+m);
	for(int i = 1; i < m; i++){
		ho.push_back({po[i-1],po[i]});
	}
	ho.push_back({-INF,po[0]});
	ho.push_back({po[m-1],INF});
	std::sort(ho.begin(),ho.end(),cmp);

	for(int i = 0, j = 0; i < n; i++){
		for(; j < ho.size() && !cmp(pl[i],ho[j]); j++){
			hoSet.insert(ho[j]);
		}
		auto it = hoSet.lower_bound(pl[i]);
		dis1 = distance(pl[i],*it);
		if(it!=hoSet.begin()){
			it--;
			dis2 = distance(pl[i],*it);
		}
		sum += std::min(dis1,dis2);
	}
	printf("%lld\n",sum);
}