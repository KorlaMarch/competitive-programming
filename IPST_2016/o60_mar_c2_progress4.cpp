#include "stdio.h"
#include "math.h"
#include "set"

int n,m,a,b,bsize;
int v[100005];
int bend[1000];
int bstart[1000];
int bsum[1000];
int bans[1000];
std::multiset<int> st;

void calblock(int bl, int st){
	bans[bl] = 0;
	bsum[bl] = 0;
	bstart[bl] = 0;
	bend[bl] = 0;
	for(int i = 0; i < bsize && st+i < n; i++){
		bsum[bl] += v[st+i];
		bstart[bl] += v[st+i];

		if(bstart[bl]<0){
			bstart[bl] = 0;
		}
		if(bstart[bl]>bans[bl]) bans[bl] = bstart[bl];

		if(bsum[bl]>bend[bl]){
			bend[bl] = bsum[bl];
		}
	}
}

int findMax(){
	int mx = 0;
	int sum = 0;
	for(int i = 0, j = 0; i < n; i += bsize, j++){
		if(bans[j]>mx) mx = bans[j];
		if(sum+bend[j]>mx) mx = sum+bend[j];

		if(sum+bsum[j]>bstart[j]) sum += bsum[j];
		else sum = bstart[j];
	}

	if(sum>mx) mx = sum;

	if(mx==0 && *st.rbegin() < 0) return *st.rbegin();
	else return mx;
}

int main(){
	scanf("%d%d",&n,&m);
	bsize = (int)sqrt(n);

	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
		st.insert(v[i]);
	}

	for(int i = 0, j = 0; i < n; i += bsize, j++){
		calblock(j,i);
	}
	
	printf("%d\n",findMax());

	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		st.erase(st.lower_bound(v[a]));
		st.insert(b);
		v[a] = b;
		calblock(a/bsize,a-a%bsize);
		printf("%d\n",findMax());
	}
}