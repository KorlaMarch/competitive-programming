#include "stdio.h"
#include "vector"
#include "algorithm"

#define MOD 1000000007

int n,m;
char s[300005];
std::vector<std::pair<int,long long> > dyn;
long long zs,cs;

int main(){
	while(scanf("%d%d",&n,&m)==2){
		scanf(" %s",s);
		zs = 1;
		dyn.clear();
		for(int i = 0; s[i]; i++){
			s[i] -= '0';
			cs = 0;
			for(auto& pi : dyn){
				pi.first = (pi.first*10+s[i])%m;
				if(pi.first==0){
					cs = (cs+pi.second)%MOD;
				}
			}
			if(zs){
				dyn.push_back({s[i]%m,zs});
				if(s[i]%m==0) cs = (cs+zs);
			}
			std::sort(dyn.begin(),dyn.end());
			int j = 0;
			for(int i = 1; i < dyn.size(); i++){
				if(dyn[i].first==dyn[i-1].first){
					dyn[j].second = (dyn[j].second+dyn[i].second)%MOD;
				}else{
					j++;
					dyn[j].first = dyn[i].first;
					dyn[j].second = dyn[i].second;
				}
			}
			dyn.resize(j+1);
			zs = cs;
			/*for(auto& pi : dyn){
				printf("VC : %d %lld\n",pi.first,pi.second);
			}
			printf("%d : %lld\n",i,zs);*/
		}
		printf("%lld\n",zs);
	}

}