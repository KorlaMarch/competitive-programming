#include "stdio.h"
#include "algorithm"
#include "map"

int n;
int h[1000005];
std::pair<int,int> sh[1000005];
int r,l;
int wl[1000005];
int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&h[i]);
		sh[i].first = h[i];
		sh[i].second = i;
	}
	std::sort(sh,sh+n);
	r=l=sh[n-1].second;
	for(int i = n-2; i >= 0; i--){
		if(sh[i].second<l){
			for(int j = sh[i].second; j < l; j++){
				wl[j] = sh[i].first;
			}
			l = sh[i].second;
		}else if(sh[i].second>r){
			for(int j = sh[i].second-1; j >= r; j--){
				wl[j] = sh[i].first;
			}
			r = sh[i].second;
		}
	}
	for(int i = 0; i < n-1; i++){
		printf("%d ",wl[i]);
	}
}