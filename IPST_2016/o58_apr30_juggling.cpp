#include "stdio.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"

int m,q,x,y,n;
std::vector<std::pair<int,int> > vec;
std::set<int> st[2];
std::map<int,int> freeT,lastS;

int gcd(int a, int b){
	if(a==0) return b;
	else if(b==0) return a;
	else return std::__gcd(a,b);
}

int main(){
	scanf("%d%d",&m,&q);
	if(q==0){
		//random
		for(int i = 0; i < m; i++){
			scanf("%d%d",&x,&y);
			vec.push_back({x,y});
		}
		std::sort(vec.begin(),vec.end());
		int lt = 1;
		for(std::pair<int,int> pi : vec){
			if(pi.first-lt){
				freeT[lt] = pi.first-1;
			}
			lt = pi.first+1;
			if(lastS.count(pi.second)==0){
				//first time
				if(pi.first%2!=pi.second%2){
					auto it = freeT.begin();
					if(!freeT.empty()){
						if(it->first==it->second){
							freeT.erase(it);
						}else{
							it->second--;
						}
					}else{
						printf("0\n");
						return 0;
					}
				}
				st[pi.first%2].insert(pi.second);
			}else if(st[!(pi.first%2)].count(pi.second)==1){
				st[!(pi.first%2)].erase(pi.second);
				st[pi.first%2].insert(pi.second);
			}else{
				auto it = freeT.upper_bound(lastS[pi.second]);
				//printf("find %d %d : %d : %d %d\n",pi.first,pi.second,lastS[pi.second],it->first,it->second);
				if(it!=freeT.end()){
					if(it->first==it->second){
						freeT.erase(it);
					}else{
						it->second--;
					}
				}else{
					printf("0\n");
					return 0;
				}
			}
			lastS[pi.second] = pi.first;
		}
		printf("-1\n");
	}else if(q==1){
		//odd queue
		int gc = 0;
		int mx = 3;
		for(int i = 0; i < m; i++){
			scanf("%d%d",&x,&y);
			gc = gcd(gc,x-y);
			mx = std::max(mx,y);
		}
		if(gc==0) printf("-1\n");
		else{
			//count divisor
			for(int i = mx%2?mx:mx+1; i <= gc; i += 2){
				if(gc%i==0){
					//printf(":%d\n",i);
					n++;
				}
			}
			printf("%d\n",n);
		}
	}else{
		//even queue
		int gc = 0;
		for(int i = 0; i < m; i++){
			scanf("%d%d",&x,&y);
			if(x%2==1&&y%2==0){
				y--;
			}else if(x%2==0&&y%2==1){
				y++;
			}
			gc = gcd(gc,x-y);
		}
		if(gc==0) printf("-1\n");
		else{
			//count divisor
			for(int i = 4; i <= gc; i += 2){
				if(gc%i==0) n++;
			}
			printf("%d\n",n);
		}
	}
}