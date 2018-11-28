#include <bits/stdc++.h>

int n,k,t;
long long int lcm[10005];
std::vector<int> deg[10005];
int ed1[1000005], ed2[1000005], dis[1000005];
bool sayNo;

int main(){
	scanf("%d", &t);
	for(int a = 0; a < t; a++){
				
		scanf("%d%d",&n,&k);
		
		// clear vector
		for(int i = 0; i <= n; i++){
			deg[i].clear();
		}
		sayNo = false;

		for(int i = 0; i < k; i++){
			scanf("%d%d%d", &ed1[i], &ed2[i], &dis[i]);
			deg[ed1[i]].push_back(dis[i]);
			deg[ed2[i]].push_back(dis[i]);
		}

		// loop though each
		for(int i = 1; i <= n && !sayNo; i++){
 			// cal lcm
			if(deg[i].empty()){
				// skip
				lcm[i] = 1;
				continue;
			}else if (deg[i].size() == 1){
				lcm[i] = deg[i][0];
			}else{
				lcm[i] = 1;
				for(int j = 0; j < deg[i].size(); j++){
					lcm[i] = (lcm[i]*deg[i][j])/std::__gcd((int)lcm[i],deg[i][j]);
					if(lcm[i] > 1000000){
						sayNo = true;
					}
				}
			}
			
			if(lcm[i] > 1000000){
				sayNo = true;
			}
		}

		// check the result
		for(int i = 0; i < k && !sayNo; i++){
			if(std::__gcd(lcm[ed1[i]], lcm[ed2[i]]) != dis[i]){
				sayNo = true;
			}				
		}

		if(sayNo){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}

}

