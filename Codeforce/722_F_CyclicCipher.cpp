#include "stdio.h"
#include "algorithm"
#include "vector"

int n,m;
int ki[100005];
int v[100005][45];
int numFq[100005][45];
std::vector<int> kl[45];
std::vector<int> st;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&ki[i]);
		for(int j = 0; j < ki[i]; j++){
			scanf("%d",&v[i][j]);
		}
		kl[ki[i]].push_back(i);
	}

	for(int i = 0; i < 45; i++){
		if(!kl[i].empty()) for(int j = 0; j < i; j++){
			st.clear();
			for(int x : kl[i]){
				st.push_back(v[x][j]);
			}
			std::sort(st.begin(),st.end());
			int fq = 1;
			for(int k = 1; k < st.size(); k++){
				if(st[k]!=st[k-1]){
					numFq[st[k-1]][i] = std::max(numFq[st[k-1]][i],fq);
					fq = 1;
				}else{
					fq++;
				}
			}
			numFq[st[st.size()-1]][i] = std::max(numFq[st[st.size()-1]][i],fq);
		}
	}

	for(int i = 1; i <= m; i++){
		int sum = 0;
		for(int j = 0; j < 45; j++){
			sum += numFq[i][j];
		}
		printf("%d\n",sum);
	}
}