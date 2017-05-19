#include "stdio.h"
#include "vector"
#include "algorithm"
#include "map"

#define INF 100000000000LL
#define MUL 100000LL

typedef std::pair<int,int> PII;

bool cmp(PII a, PII b){
	if(a.second/(float)a.first==b.second/(float)b.first){
		return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
	}else return a.second/(float)a.first>b.second/(float)b.first;
}

int a,n,mxT,mxB,x,y;
std::vector<PII> top,mid,bot;
std::vector<std::pair<long long,int>> dyn[2005];

long long getM(PII a, PII b){
	//find m form a -> b
	//printf("Find M %d %d : %d %d\n",a.first,a.second,b.first,b.second);
	if(b.first==a.first) return INF;
	else return (b.second-a.second)*MUL/(b.first-a.first);
}

int findMx(std::vector<PII>& point){
	point.push_back({a,a});
	for(int i = 0; i < point.size(); i++){
		dyn[i].clear();
		dyn[i].push_back({point[i].second*MUL/point[i].first,1});
	}
	for(int i = 0; i < point.size(); i++){
		//printf("%d\n",i);
		std::sort(dyn.begin(),dyn.end());
		auto it = dyn[i].end();
		auto it2 = dyn[i].end();
		it--,it2--;
		for(it--;; it--){
			it->second = std::max(it->second,it2->second);
			it2 = it;
			if(it == dyn[i].begin()){
				break;
			}
		}
		//printf("1");

		for(int j = i+1; j < point.size(); j++){
			const long long m = getM(point[i],point[j]);
			auto it = std::lower_bound(dyn[i].begin(),dyn[i].end(),{m,0});
			if(it!=dyn[i].end()){
				auto it2 = std::lower_bound(dyn[j].begin(),dyn[j].end(),{m,0});
				if(it2!=dyn[j].end()&&){
					it2->second = it->second+1;
				}else{
				dyn[j].push_back({m,it->second+1});
				//printf("%d %d : %d (%.4f)\n",i,j,dyn[j][m],m);
			}
		}
	}
	//printf("Re : %d\n",dyn[point.size()-1].begin()->second-1);
	return dyn[point.size()-1].begin()->second-1;
}

int main(){
	scanf("%d%d",&a,&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&x,&y);
		if(x==y){
			mid.push_back({x,y});
		}else if(y>x){
			top.push_back({x,y});
		}else{
			bot.push_back({x,y});
		}
	}

	for(PII& pi : bot){
		pi.first = a-pi.first;
		pi.second = a-pi.second;
	}

	std::sort(top.begin(),top.end(),cmp);
	std::sort(bot.begin(),bot.end(),cmp);

	mxT = findMx(top);
	mxB = findMx(bot);

	printf("%d\n",std::max(mxT+mxB,std::max(mxT+(int)mid.size(),mxB+(int)mid.size())));
}