#include "stdio.h"
#include "algorithm"

int n,t,sol,mn,mnD;
std::pair<int,int> xi[100005];
int vi[100005];
std::pair<int,int> yi[100005];

bool cmp(std::pair<int,int> a, std::pair<int,int> b){
	if(a.first==b.first) return a.second>b.second;
	else return a.first<b.first;
}

int main(){
	scanf("%d%d",&n,&t);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&xi[i].first,&vi[i]);
		xi[i].second = i;
	}
	std::sort(xi,xi+n);

	//reassign number
	for(int i = 0, j = 0; i < n; i++){
		
		if(!i||xi[i].first!=xi[i-1].first){
			j++;
		}

		yi[i].first = xi[i].first+vi[ xi[i].second ]*t;
		yi[i].second = j;
	}

	std::sort(yi,yi+n,cmp);

	sol = 1;
	mn = yi[n-1].second;
	mnD = yi[n-1].first;
	for(int i = n-2; i >= 0; i--){
		if(yi[i].second<mn){
			mn = yi[i].second;
			mnD = yi[i].first;
			sol++;
		}else if(yi[i].second==mn&&yi[i].first==mnD){
			sol++;
		}
	}
	printf("%d\n",sol);
}