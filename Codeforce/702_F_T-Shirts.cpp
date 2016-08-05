#include "stdio.h"
#include "algorithm"
#include "vector"

int n,k;
std::vector<std::pair<int,int> > tsh;
std::vector<int> price;
int c,q,b;

bool cmp(std::pair<int,int> a, std::pair<int,int> b){
	return a.first==b.first?(a.second<b.second):(a.first>b.first);
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&c,&q);
		tsh.push_back({q,c});
	}
	std::sort(tsh.begin(),tsh.end(),cmp);
}