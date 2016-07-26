#include "stdio.h"
#include "algorithm"

int n,m;
std::pair<int,int> x[1005];
bool isU[1005];
int beg,end;
bool islo;

bool cmp(std::pair<int,int> a, std::pair<int,int> b){
	if(a.first==b.first) return a.second>b.second;
	else return a.first<b.first;
}

int b[10],e[10];
int findmin(int d, int uc){
	int minR = 7;
	if(d==m){
		return uc;
	}else{
		const int lm = std::min(6,d+1);
		for(int i = 0; i < lm; i++){
			int tb = b[i],te = e[i];
			if(b[i]==-1){
				b[i] = x[d].first+n;
				e[i] = x[d].second;
				minR = std::min(minR,findmin(d+1,uc+1));
			}else if(x[d].first>e[i]&&x[d].second<b[i]){
				e[i] = x[d].second;
				minR = std::min(minR,findmin(d+1,uc));
			}
			b[i] = tb;
			e[i] = te;
		}
	}
	return minR;
}

int main(){
	scanf("%d%d",&n,&m);
	islo = false;
	for(int i = 0; i < m; i++){
		scanf("%d%d",&x[i].first,&x[i].second);
		if(x[i].first>x[i].second){
			islo = true;
			x[i].second += n;
		}
	}
	std::sort(x,x+m,cmp);
	if(!islo){
		int i;
		for(i = 0; ; i++){
			int j;
			for(j = 0; j < m; j++){
				if(!isU[j]){
					break;
				}
			}
			if(j==m) break;
			end = x[j].second;
			isU[j] = true;
			for(j++; j < m; j++){
				if(!isU[j]&&x[j].first>end){
					isU[j] = true;
					end = x[j].second;
				}
			}
		}
		printf("%d\n",i);
	}else if(m<=10){
		//BF
		for(int i = 0; i < 10; i++) b[i] = -1;
		int r = findmin(0,0);
		printf("%d\n",r);
	}
}