#include "stdio.h"
#include "vector"
#include "queue"

#define PIL std::pair<int,long long>

int n,m,w,q;
std::vector<int> edge[5005];
std::vector<PIL> store[5005];
std::queue<int> nx[2];
PIL fen[200005];
bool isV[5005];

void addFen(int x, PIL v){
	for(; x < 200005; x += (x&-x)){
		fen[x].first += v.first;
		fen[x].second += v.second;
	}
}

PIL getFen(int x){
	PIL v;
	v.first = 0, v.second = 0;
	for(; x > 0; x -= (x&-x)){
		v.first += fen[x].first;
		v.second += fen[x].second;
	}
	return v;
}

int binaryForR(int ri){
	int x=1,y=200000,m,lm=-1;

	while(x<=y){
		m = (x+y)/2;
		if(getFen(m).first>=ri){
			lm = m;
			y = m-1;
		}else{
			x = m+1;
		}
	}

	return lm;
}

void clearAll(){
	//clear fenwick
	for(int i = 0; i < 200005; i++){
		fen[i] = {0,0};
	}
	//clear isV
	for(int i = 0; i <= n; i++){
		isV[i] = false;
	}

	while(!nx[0].empty()) nx[0].pop();
	while(!nx[1].empty()) nx[1].pop();
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0,xi,yi; i < m; i++){
		scanf("%d%d",&xi,&yi);
		edge[xi].push_back(yi);
		edge[yi].push_back(xi);
	}

	scanf("%d",&w);
	for(int i = 0,ci,ki,pi; i < w; i++){
		scanf("%d%d%d",&ci,&ki,&pi);
		store[ci].push_back({ki,pi});
	}

	scanf("%d",&q);
	for(int k = 0, gi, ri, ai; k < q; k++){
		scanf("%d%d%d",&gi,&ri,&ai);

		clearAll();
		nx[0].push(gi);
		isV[gi] = true;

		bool isP = false;

		for(int d = 0; !isP && !nx[d%2].empty(); d++){
			const int ind = d%2;
			while(!nx[ind].empty()){
				int no = nx[ind].front();
				nx[ind].pop();

				for(PIL pi : store[no]){
					addFen(pi.second,{pi.first,pi.second*pi.first});
				}

				for(int x : edge[no]){
					if(!isV[x]){
						isV[x] = true;
						nx[!ind].push(x);
					}
				}
			}

			//binary search
			int bi = binaryForR(ri);
			if(bi==-1) continue;
			else{
				PIL pi = getFen(bi);
				long long realC = pi.second-(pi.first-ri)*bi;
				if(realC<=ai){
					printf("%d\n",d);
					isP = true;
					break;
				}
			}
		}

		if(!isP){
			printf("-1\n");
		}

	}
}