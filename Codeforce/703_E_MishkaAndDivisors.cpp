#include "stdio.h"
#include "map"
#include "algorithm"

struct state{
	long long sum;
	std::map<long long, state>::iterator from;
	int id;
	int co;
	state(long long _sum, std::map<long long, state>::iterator _from, int _id, int _co) : sum(_sum), from(_from), id(_id), co(_co) {}
	state() {}
};

int n;
long long k;
long long a[1005];
std::map<long long, state > mp;

void print(std::map<long long, state>::iterator it, int co){
	if(it->second.id == -1){
		printf("%d\n",co);
	}else{
		print(it->second.from, co+1);
		printf("%d ",it->second.id+1);
	}
}

int main(){
	scanf("%d %I64d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%I64d",&a[i]);
	}
	mp[1] = state(0,mp.end(),-1,0);
	for(int i = 0; i < n; i++){
		for(auto pi = std::prev( mp.end() ) ; true ; --pi ){
			long long key = std::__gcd( k, pi->first*a[i] );

			auto it = mp.find(key);
			if(it==mp.end()){
				mp[key] = state(pi->second.sum + a[i] ,pi,i,pi->second.co+1);
			}else if(pi->second.co+1 < it->second.co ||
				(pi->second.co+1 == it->second.co && a[i]+pi->second.sum < it->second.sum)){

				it->second = state(pi->second.sum + a[i] ,pi,i,pi->second.co+1);
			}

			if ( pi == mp.begin() ) {
				break;
			}
		}
	}

	for(auto pi = mp.begin() ; pi != mp.end() ; ++pi ){
		if(pi->first==k){
			print(pi,0);
			return 0;
		}
	}

	printf("-1\n");
}