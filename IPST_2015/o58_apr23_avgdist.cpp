#include "stdio.h"
#include "vector"
#include "algorithm"

int n,k,q;
int g[30005];
int gc[15];
std::pair<int,int> par[30005];
std::vector<std::pair<int,int> > child[30005];
std::vector<std::pair<int,int> > edge[30005];
bool isV[30005];
int size[30005];
int head;

int getSize(int no, int o){
	int si = 1;
	for(auto pi : edge[no]){
		if(pi.first!=o&&!isV[pi.first]){
			si += getSize(pi.first,no);
		}
	}
	return size[no]=si;
}

int getCentroid(int no, int o, int allsi){
	bool isCen = size[no]<=allsi/2;
	if(isCen){
		for(auto pi : edge[no]){
			if(pi.first != o && !isV[pi.first] && size[pi.first] > allsi/2){
				isCen = false;
			}
		}
		if(isCen) return no;
	}
	for(auto pi : edge[no]){
		if(pi.first != o && !isV[pi.first]){
			int r = getCentroid(pi.first,no,allsi);
			if(r) return r;
		}
	}
	return 0;
}

void genCentroidTree(int node, int p){
	int fullsi = getSize(node,-1);
	int cen = getCentroid(node,-1,fullsi);
	isV[cen] = true;
	par[cen] = p;
	if(p) child[p].push_back(cen);
	else head = cen;
	for(auto pi : edge[cen]){
		if(pi.first != p && !isV[pi.first]){
			genCentroidTree(pi.first,node);
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&g[i]);
		gc[g[i]]++;
	}
	int a,b,l;
	for(int i = 1; i < n; i++){
		scanf("%d%d%d",&a,&b,&l);
		edge[a].push_back({b,l});
		edge[b].push_back({a,l});
	}

	//make a centroid decomposition tree
	genCentroidTree(1,0);

	scanf("%d",&q);
	for(int i = 0; i < q; i++){

	}
}