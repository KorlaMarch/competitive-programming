#include "stdio.h"
#include "vector"
#include "algorithm"

typedef std::pair<int,int> Pii;

bool cmp(Pii a, Pii b){
	if(a.first==b.first) return a.second < b.second;
	else return a.first > b.first;
}

int n,m,ai;
std::vector<int> a[1000000];
int count[1000000];
Pii list[1000000];
int mx, mxP;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&ai);
			a[i].push_back(ai);
		}
		std::sort(a[i].begin(),a[i].end());
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			list[j].first = a[j][i];
			list[j].second = j;
		}
		std::sort(list,list+n,cmp);
		count[list[0].second]++;
	}
	for(int i = 0; i < n; i++){
		if(count[i]>mx){
			mx = count[i];
			mxP = i+1;
		}
	}
	printf("%d\n",mxP);
}