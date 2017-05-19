#include "stdio.h"
#include "set"
#include "vector"
#include "algorithm"

int n,m;
long long sum;
int k[100005],a[100005];
int oldT[100005];
std::vector<int> compre;
std::set<int> city[100005];
std::multiset<int> ans[100005];

void eraseOne(int ind, int v){
	ans[ind].erase(ans[ind].lower_bound(v));
}

int main(){
	scanf("%d%d",&n,&m);
	compre.push_back(0);
	for(int i = 0; i < m; i++){
		scanf("%d%d",&k[i],&a[i]);
		compre.push_back(a[i]);
	}
	std::sort(compre.begin(),compre.end());
	
	//init value
	for(int i = 0; i < n; i++){
		oldT[i] = 0;
		city[0].insert(i);
		if(i){
			ans[0].insert(1);
		}
	}

	for(int i = 0; i < m; i++){
		a[i] = std::lower_bound(compre.begin(),compre.end(),a[i])-compre.begin();
		if(oldT[k[i]]!=a[i]){
			//del oldT
			auto it = city[oldT[k[i]]].lower_bound(k[i]);
			auto it2 = it;
			if(it!=city[oldT[k[i]]].begin()){
				it2--;
				eraseOne(oldT[k[i]],*it - *it2);
			}
			auto it3 = it;
			it3++;
			if(it3!=city[oldT[k[i]]].end()){
				eraseOne(oldT[k[i]],*it3 - *it);

				if(it!=city[oldT[k[i]]].begin()){
					ans[oldT[k[i]]].insert(*it3 - *it2);
				}
			}
			city[oldT[k[i]]].erase(it);

			//add new a[i]
			auto nit = city[a[i]].lower_bound(k[i]);
			auto nit2 = nit;
			if(nit!=city[a[i]].end()){
				ans[a[i]].insert(*nit - k[i]);
			}
			if(nit2!=city[a[i]].begin()){
				nit2--;
				ans[a[i]].insert(k[i] - *nit2);
				if(nit!=city[a[i]].end()){
					eraseOne(a[i],*nit - *nit2);
				}
			}
			city[a[i]].insert(k[i]);
			oldT[k[i]] = a[i];
		}

		if(!ans[a[i]].empty()){
			sum += *(ans[a[i]].begin());
		}
	}

	printf("%lld\n",sum);
}