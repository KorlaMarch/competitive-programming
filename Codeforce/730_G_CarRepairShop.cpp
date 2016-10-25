#include "stdio.h"
#include "set"

int n,si,di;
int s[205],e[205];
std::set<int> sp,ep;

bool checkInter(int s1, int e1, int s2, int e2){
	return (s2<=s1&&s1<=e2)||(s2<=e1&&e1<=e2)||(s1<=s2&&s2<=e1)||(s1<=e2&&e2<=e1);
}

int main(){
	scanf("%d",&n);
	ep.insert(0);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&si,&di);
		bool isIN = false;
		for(int j = 0; j < i; j++){
			if(checkInter(si,si+di-1, s[j], e[j] )){
				isIN = true;
				break;
			}
		}
		if(isIN){
			for(int x : ep){
				if(sp.lower_bound(x+1)==sp.end() || x+di < *sp.lower_bound(x+1)){
					s[i] = x+1;
					e[i] = x+di;
					break;
				}
			}
		}else{
			s[i] = si;
			e[i] = si+di-1;
		}
		sp.insert(s[i]);
		ep.insert(e[i]);
	}
	for(int i = 0; i < n; i++){
		printf("%d %d\n",s[i],e[i]);
	}
}