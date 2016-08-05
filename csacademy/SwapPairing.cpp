#include "stdio.h"
#include "map"

int n;
int a[100005];
int fen[100005];
std::map<int,int> spos;
bool isM[100005];
long long sum;

void addFen(int i, int v){
	for(; i <= n; i += (i&-i)) fen[i] += v;
}

int getFen(int i){
	int v = 0;
	for(; i > 0; i -= (i&-i)) v += fen[i];
	return v;
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		spos[a[i]] = i;
		addFen(i,1);
	}
	for(int i = 1; i <= n; i++){
		if(!isM[i]){
			int sp = spos[a[i]];

			isM[i] = true;
			isM[sp] = true;

			addFen(i,-1);
			sum += getFen(sp)-1;
			addFen(sp,-1);
		}
	}
	printf("%lld\n",sum);
}