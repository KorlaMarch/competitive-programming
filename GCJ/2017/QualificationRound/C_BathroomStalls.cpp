#include "stdio.h"
#include "map"

typedef std::pair<long long, long long> PLL;

int t;
long long n,k;
std::map<long long, long long> mp;

int main(){
	scanf("%d",&t);
	for(int te = 1; te <= t; te++){
		mp.clear();
		scanf("%lld %lld",&n,&k);
		mp[n] = 1;
		while(k > 0){
			auto it = mp.end();
			it--;
			PLL pi = *it;
			mp.erase(it);

			if(pi.second<k){
				if(pi.first%2==1){
					mp[pi.first/2] += pi.second*2;
				}else{
					mp[pi.first/2] += pi.second;
					mp[pi.first/2-1] += pi.second;
				}
				k -= pi.second;
			}else{
				if(pi.first%2==1){
					printf("Case #%d: %lld %lld\n",te,pi.first/2,pi.first/2);
				}else{
					printf("Case #%d: %lld %lld\n",te,pi.first/2,pi.first/2-1);
				}
				k = 0;
			}
		}
	}
}