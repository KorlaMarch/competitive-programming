#include "stdio.h"
#include "vector"
#include "algorithm"
#include "set"

int n,c,l,w;
std::vector<int> hie[500050];
std::set<int> acs;
bool findX(int x, int y, int d){
	//printf("CALL %d %d %d\n",x,y,d);
	while(d>=hie[x].size()&&x<=y) x++;
	if(x>=y) return true;

	//check length
	for(int i = x; i <= y; i++){
		if(d>=hie[i].size()) return false;
	}

	//find first iccs
	int ef = x-1;
	for(int i = x+1; i <= y; i++){
		if(hie[i-1][d]>hie[i][d]){
			ef = i-1;
			break;
		}
	}

	if(ef==x-1){
		//only single iccs (find only max)
		const int mnd = c-hie[y][d]+1;
		const int mxd = c-hie[x][d];
		//delete from acs
		for(auto it = acs.lower_bound(mnd); it != acs.end() && *it <= mxd; ){
			auto it2 = it;
			it++;
			acs.erase(it2);
		}
	}else{
		//check second iccs
		for(int i = ef+2; i <= y; i++){
			if(hie[i-1][d]>hie[i][d]){
				return false;
			}
		}

		if(hie[y][d]>=hie[x][d]) return false;
		else{
			const int mn = c-hie[x][d]+1;
			const int mx = c-hie[y][d];
			//delete from acs
			for(auto it = acs.begin(); it != acs.end() && *it < mn;){
				auto it2 = it;
				it++;
				acs.erase(it2);
			}

			for(auto it = acs.upper_bound(mx); it != acs.end();){
				auto it2 = it;
				it++;
				acs.erase(it2);
			}
		}
	}

	//call recusively
	int lsB = x;
	for(int i = x+1; i <= y; i++){
		if(hie[i-1][d]!=hie[i][d]){
			if(!findX(lsB,i-1,d+1)) return false;
			lsB = i;
		}
	}
	if(!findX(lsB,y,d+1)) return false;

	return true;
}

int main(){
	scanf("%d%d",&n,&c);
	for(int i = 0; i < c; i++){
		acs.insert(i);
	}

	for(int i = 0; i < n; i++){
		scanf("%d",&l);
		for(int j = 0; j < l; j++){
			scanf("%d",&w);
			hie[i].push_back(w);
		}
	}

	if(findX(0,n-1,0)&&!acs.empty()){
		printf("%d\n",*acs.begin());
	}else{
		printf("-1\n");
	}
}