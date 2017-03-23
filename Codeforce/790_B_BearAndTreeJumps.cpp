#include "stdio.h"
#include "vector"

int n,k,a,b;
std::vector<int> edge[200005];
long long sumDis[200005];
long long nc[200005][5];
long long sc[200005];
long long ans;

void findAnsD(int x, int p){
	for(int i : edge[x]){
		if(i!=p){
			findAnsD(i,x);
			sc[x] += sc[i];
			for(int j = 0; j < k; j++){
				nc[x][j] += nc[i][(j-1+k)%k];
			}
			sumDis[x] += sumDis[i];
		}
	}
	sumDis[x] += sc[x];
	//for this node
	sc[x]++;
	nc[x][0]++;
}

long long ac[200005][5];

void findAnsU(int x, int p){
	//to upper node
	for(int i = 0; i < k; i++){
		ac[x][i] = nc[x][i];
	}
	if(p!=0){
		sumDis[x] = sumDis[p]+(n-sc[x])-sc[x];
		//update nc
		int newP[10];
		for(int i = 0; i < k; i++){
			newP[i] = ac[p][i]-nc[x][(i-1+k)%k];
		}
		for(int i = 0; i < k; i++){
			ac[x][i] += newP[(i-1+k)%k];
		}
	}
	long long sum2 = sumDis[x];
	for(int j = 1; j < k; j++){
		sum2 += (k-j)*ac[x][j];
	}
	ans += sum2/k;

	for(int i : edge[x]){
		if(i!=p){
			findAnsU(i,x);
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	findAnsD(1,0);
	findAnsU(1,0);

	printf("%I64d\n",ans/2);
}