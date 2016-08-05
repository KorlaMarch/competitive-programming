#include "stdio.h"
#include "queue"
#include "algorithm"
#include "math.h"
#include "vector"

typedef std::pair< std::pair<int,int>, int> PDI;
typedef std::pair<int, int> PII;

struct cmp{
	bool operator()(PDI a, PDI b){
		if(a.first.first * (long long) b.first.second==b.first.first * (long long) a.first.second) return a.second>b.second;
		else return a.first.first * (long long) b.first.second < b.first.first * (long long) a.first.second;
	}
};

int v,n,m,tll,th;
int pt[1005];
int co[1005];
int pt2[1005];
int co2[1005];
std::priority_queue<PDI, std::vector<PDI>, cmp> qu;
std::priority_queue<PII, std::vector<PII>, std::greater<PII> > qu2;

void simu(){
	while(!qu.empty()) qu.pop();
	for(int i = 0; i < n; i++){
		co[i] = 0;
		if(pt[i]>=th) qu.push({ {pt[i],1},i});
	}
	for(int i = 0; i < m; i++){
		PDI pii = qu.top();
		qu.pop();
		co[pii.second]++;

		qu.push({ {pt[pii.second],co[pii.second]+1},pii.second});
	}
}

bool canDo(int x, int d, int vi){
	//printf("cando %d %d %d\n",x,d,vi);
	int lv = v-tll;
	long double minqu = vi/(long double)(d+1);
	while(!qu2.empty()) qu2.pop();
	for(int i = 0; i < n; i++){
		pt2[i] = pt[i];
		co2[i] = 0;
		if(i<x){
			qu2.push({std::max(0,std::max(th,(int)ceil(minqu))-pt2[i]),i});
		}else if(i>x){
			qu2.push({std::max(0,std::max(th,(int)floor(minqu+1))-pt2[i]),i});
		}
	}
	co2[x] = d;
	if(qu2.empty()) return false;

	for(int i = d; i < m; i++){
		PII pii = qu2.top();
		qu2.pop();
		lv -= std::max(0,pii.first);
		co2[pii.second]++;
		pt2[pii.second] += std::max(0,pii.first);
		//printf("GET %d %d\n",pii.first,pii.second);
		if(pii.second<x){
			qu2.push({std::max(0,std::max(th,(int)ceil((co2[pii.second]+1)*minqu) )-pt2[pii.second] ),pii.second});
		}else if(pii.second>x){
			qu2.push({std::max(0,std::max(th,(int)floor((co2[pii.second]+1)*minqu+1) )-pt2[pii.second] ),pii.second});
		}
	}

	return lv>=0;

}

int main(){
	scanf("%d%d%d",&v,&n,&m);
	th = (int)ceil(v*0.05);
	for(int i = 0; i < n; i++){
		scanf("%d",&pt[i]);
		tll += pt[i];
	}
	for(int i = 0; i < n; i++){
		pt[i] += v-tll;
		simu();
		pt[i] -= v-tll;

		printf("%d ",co[i]);
	}
	printf("\n");

	if(n==1) printf("%d\n",m);
	else{
		simu();
		for(int i = 0; i < n; i++){
			if(pt[i]<th) printf("0 ");
			else{
				int j;
				for(j = m; j >= 0 && canDo(i, j, pt[i]); j--);
				printf("%d ", j+1);
			}
		}
		printf("\n");
	}
}