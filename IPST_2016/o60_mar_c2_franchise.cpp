#include "stdio.h"
#include "algorithm"
#include "vector"

#define SIZE 33554440
#define INF 1000000000

int n,k,m;
int v[5005];
int dyn[2][SIZE];
bool isINF[SIZE];
std::vector<int> LP;
//std::vector<char> bitC;

char countOne(int x){
	char co = 0;
	//printf("CO %d : ",x);
	while(x){
		if(x%2){
			co++;
		}
		x /= 2;
	}
	//printf("%d\n",co);
	return co;
}

int calBit(int pos, int bit){
	int co = 0;
	//printf("cal %d %d",pos,bit);
	while(bit){
		if(bit%2){
			co += v[pos];
		}
		bit /= 2;
		pos--;
	}
	//printf(" = %d\n",co);
	return co;
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	while(k>27);
	for(int i = 1; i <= n; i++){
		scanf("%d",&v[i]);
	}
	const int lim = (1<<k);
	const int limM = (lim>>1);

	for(int j = 0; j < lim; j++){
		const char c = countOne(j);
		if(c>m){
			isINF[j] = true;
			dyn[k%2][j] = -INF;
			dyn[(k+1)%2][j] = -INF;
		}else{
			dyn[k%2][j] = calBit(k,j);
			LP.push_back(j);
			//bitC.push_back(c);
		}
	}

	for(int i = k+1; i <= n; i++){
		int* newD = dyn[i%2];
		int* oldD = dyn[(i+1)%2];

		for(int j : LP){
			if(!isINF[j]){
				if(j%2){
					//printf("LOOK %d %d\n",(j>>1),limM||(j>>1));
					newD[j] = std::max(oldD[(j>>1)],oldD[limM|(j>>1)])+v[i];
				}else{
					newD[j] = std::max(oldD[(j>>1)],oldD[limM|(j>>1)]);
				}
				//printf("%d %d : %d\n",i,j,newD[j]);
			}
		}
	}
	int mx = 0;
	for(int j : LP){
		if(!isINF[j]){
			mx = std::max(mx,dyn[n%2][j]);
		}
	}
	printf("%d\n",mx);
}