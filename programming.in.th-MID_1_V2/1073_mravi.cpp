#include "stdio.h"
#include "vector"
#include "algorithm"

int l,t,n,tp,p;
char d;
std::vector<int> pos;
int main(){
	scanf("%d%d%d",&l,&t,&n);
	t %= l*2;
	for(int i = 0; i < n; i++){
		scanf("%d %c",&p,&d);
		if(d=='D') tp = p;
		else tp = (l+l-p)%(l*2);

		tp = (tp+t)%(2*l);

		if(tp>l) tp = 2*l-tp;

		pos.push_back(tp);
	}
	std::sort(pos.begin(),pos.end());
	for(int i = 0; i < pos.size(); i++){
		printf("%d ",pos[i]);
	}
}