#include "stdio.h"
#include "vector"
#include "algorithm"

int n,minD=-1;
char di[200005];
std::vector<int> rpos,lpos;

int main(){
	scanf("%d %s",&n,di);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		if(di[i]=='R') rpos.push_back(x);
		else lpos.push_back(x);
	}
	for(int x : rpos){
		auto it = std::upper_bound(lpos.begin(),lpos.end(),x);
		if(it!=lpos.end()){
			if(minD==-1||(*it-x)/2<minD){
				minD = (*it-x)/2;
			}
		}
	}
	printf("%d\n",minD);
}