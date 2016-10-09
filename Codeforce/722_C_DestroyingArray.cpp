#include "stdio.h"
#include "set"
#include "map"

int n,od;
int a[100005];
long long qs[100005];
std::map<int, int> itv;
std::multiset<long long> mxS;

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		qs[i] = a[i]+qs[i-1];
	}
	itv.insert({1,n});
	mxS.insert(qs[n]);
	for(int i = 0; i < n; i++){
		scanf("%d",&od);
		auto it = itv.upper_bound(od);
		it--;

		std::pair<int,int> pi = *it;

		itv.erase(it);
		mxS.erase(mxS.lower_bound(qs[pi.second]-qs[pi.first-1]));

		if(od+1<=pi.second){
			itv.insert({od+1,pi.second});
			mxS.insert(qs[pi.second]-qs[od]);
		}

		if(pi.first<=od-1){
			itv.insert({pi.first,od-1});
			mxS.insert(qs[od-1]-qs[pi.first-1]);
		}

		if(!mxS.empty()) printf("%I64d\n",*mxS.rbegin());
		else printf("0\n");
	}
}