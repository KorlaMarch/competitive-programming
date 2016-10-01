#include "stdio.h"
#include "algorithm"

int n;
std::pair<int,int> a[10005];
int pl[10005];
long long sum;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}

	std::sort(a,a+n);
	for(int i = 0; i < n; i++){
		//add a
		pl[a[i].second] = a[i].first;
		
	}

}