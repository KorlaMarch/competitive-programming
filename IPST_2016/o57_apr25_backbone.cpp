#include "stdio.h"
#include "vector"
#include "algorithm"

struct demand{
	int a,b;
	int dep;
	int no;
	demand(int _a = 0, int _b = 0, int _dep = 0, int _no = 0) : a(_a), b(_b), dep(_dep), no(_no) {}
};

bool cmp(demand a, demand b){
	return a.dep>b.dep;
}

int n,m,a,b,minA;
std::vector<int> edge[300];
std::vector<int> commList[300];
std::vector<std::pair<int,int> > ans,st;

int pa[300],de[300];
int s[400],t[400];
int isCut[400];
demand dem[400];

void rootingTree(int x, int p, int d){
	pa[x] = p;
	de[x] = d;
	for(int i : edge[x]){
		if(i!=p){
			rootingTree(i,x,d+1);
		}
	}
}

void getDemand(int a, int b, int x){
	if(a==b) return;

	dem[x].a = a;
	dem[x].b = b;
	dem[x].dep = std::max(de[a],de[b]);

	if(de[a]==de[b]){
		commList[a].push_back(x);
		commList[b].push_back(x);

		getDemand(pa[a],pa[b],x);
	}else if(de[a]<de[b]){
		commList[b].push_back(x);
		getDemand(a,pa[b],x);
	}else{
		commList[a].push_back(x);
		getDemand(pa[a],b,x);
	}
}

void cut(int x){
	for(int i : commList[x]){
		isCut[i]++;
	}
}

void uncut(int x){
	for(int i : commList[x]){
		isCut[i]--;
	}
}

void findAns(int x, int co){
	if(co>10) return;
	else if(x==m){
		if(st.size()<minA){
			minA = st.size();
			ans.clear();
			for(std::pair<int,int> pii : st){
				ans.push_back(pii);
			}
		}
	}else if(isCut[dem[x].no]){
		findAns(x+1,co);
	}else{
		if(de[dem[x].a]>=de[dem[x].b]){
			cut(dem[x].a);
			st.push_back({dem[x].a,pa[dem[x].a]});
			findAns(x+1,co+1);
			st.pop_back();
			uncut(dem[x].a);
		}
		if(de[dem[x].b]>=de[dem[x].a]){
			cut(dem[x].b);
			st.push_back({dem[x].b,pa[dem[x].b]});
			findAns(x+1,co+1);
			st.pop_back();
			uncut(dem[x].b);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	rootingTree(1,0,0);

	for(int i = 0; i < m; i++){
		scanf("%d%d",&s[i],&t[i]);
		getDemand(s[i],t[i],i);
		dem[i].no = i;
	}

	std::sort(dem,dem+m,cmp);

	minA = 10000;
	findAns(0,0);

	printf("%d\n",minA);
	for(std::pair<int,int> pii : ans){
		printf("%d %d\n",pii.first,pii.second);
	}
}