#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 10000000

int n,c,f,l,x,e;
std::pair<int,int> child[50005];
std::vector<int> fear[50005];
std::vector<int> like[50005];
int dyn[10005][35];
int minAns;

bool isFit(int cnum, int st){
	for(int li : like[cnum]){
		if((st>>li)%2==1) return true;
	}

	for(int fe : fear[cnum]){
		if((st>>fe)%2==0) return true;
	}

	return false;
}

void solve(int inti){
	for(int i = 0; i < 32; i++){
		dyn[0][i] = -1;
	}
	dyn[0][inti] = 0;
	
	int i,k;
	for(i = 1, k = 0; i <= n; i++){
		const int inv = !(i%2);
		for(int j = 0; j < 32; j++){

			const int bef = (j<<1)%32;

			if( i+4>n&&(j>>(n-i+1))!=(inti%(1<<(i+4-n))) ) dyn[i%2][j] = -1;
			else if(dyn[inv][bef]!=-1&&dyn[inv][bef+1]!=-1) dyn[i%2][j] = dyn[inv][bef]+dyn[inv][bef+1];
			else if(dyn[inv][bef]!=-1) dyn[i%2][j] = dyn[inv][bef];
			else if(dyn[inv][bef+1]!=-1) dyn[i%2][j] = dyn[inv][bef+1];
			else dyn[i%2][j] = -1;

		}

		for(; k < c && child[k].first == i; k++){
			for(int j = 0; j < 32; j++){
				if(dyn[i%2][j]!=-1&&isFit(child[k].second,j)){
					dyn[i%2][j]++;
				}
			}
		}

		for(int j = 0; j < 32; j++){
			printf("DYN %d %d : %d\n",i,j,dyn[i%2][j]);
		}
	}

	//update minAns
	for(int i = 0; i < 32; i++){
		if(dyn[n%2][i]!=-1) printf("%d %d : %d\n",inti,i,dyn[n%2][i]);
		if(dyn[n%2][i]!=-1&&dyn[n%2][i]<minAns){
			minAns = dyn[n%2][i];
		}
	}
}

int main(){
	scanf("%d%d",&n,&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d %d",&e,&f,&l);
		child[i].first = e;
		child[i].second = i;
		for(int j = 0; j < f; j++){
			scanf("%d",&x);
			if(x-e>=0&&x-e<5){
				fear[i].push_back(x-e);
			}
		}

		for(int j = 0; j < l; j++){
			scanf("%d",&x);
			if(x-e>=0&&x-e<5){
				like[i].push_back(x-e);
			}
		}

	}

	std::sort(child,child+c);

	minAns = INF;
	for(int i = 0; i < 1; i++){
		solve(i);
	}

	printf("%d\n",minAns);

}