#include "stdio.h"
#include "algorithm"
#include "set"

int n;
int x,y;
long long dyn[20000005];
bool isV[20000005];
std::set<std::pair<long long, int> > st;

void canP(int p, long long v){
	if(!isV[p]&&p>0&&p<=2*n&&(dyn[p]==0||v<dyn[p])){
		st.erase({dyn[p],p});
		st.emplace(v,p);
		dyn[p] = v;
	}
}

int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i = 1; i <= 2*n; i++){
		if(i%2==0) dyn[i] = std::min(dyn[i-1]+x,dyn[i/2]+y);
		else dyn[i] = dyn[i-1]+x;
		for(int j = i-1; j > 0; j--){
			if(dyn[j+1]+x<dyn[j]){
				dyn[j] = dyn[j+1]+x;
			}else break;
		}
	}
	printf("%I64d\n",dyn[n]);
}