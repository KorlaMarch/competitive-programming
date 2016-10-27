#include "stdio.h"
#include "vector"

int n,m,k,mx,nc,l,r,pc;
int ci[200005];
int cc[200005];
std::vector<int> edge[200005];
char isV[200005];

void findMx(int no){
	if(isV[no]) return;
	isV[no] = 1;

	cc[ci[no]]++;
	nc++;
	if(cc[ci[no]]>mx){
		mx = cc[ci[no]];
	}

	for(int x : edge[no]){
		findMx(x);
	}
}

void clearCC(int no){
	if(isV[no]==2) return;
	isV[no] = 2;

	cc[ci[no]]--;

	for(int x : edge[no]){
		clearCC(x);
	}
}

void paintColor(int no){
	mx = 0;
	nc = 0;
	findMx(no);
	clearCC(no);
	
	if(nc>1) pc += nc-mx;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&ci[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d",&l,&r);
		edge[l].push_back(r);
		edge[r].push_back(l);
	}
	for(int i = 1; i <= n; i++){
		if(!isV[i]){
			paintColor(i);
		}
	}
	printf("%d",pc);
}