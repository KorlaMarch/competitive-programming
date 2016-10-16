#include "stdio.h"
#include "vector"
#include "ratio"

#define SIZE 1000006

int n,a,b;
int xi[SIZE];
int p[SIZE];
long long minNum[SIZE];
long long minDem[SIZE];
std::vector<int> edge[SIZE];
std::vector<int> child[SIZE];

void rooting(int no, int pa){
	p[no] = pa;
	for(int x : edge[no]){
		if(x!=pa){
			child[no].push_back(x);
			rooting(x, no);
		}
	}
}

void dyndown(int no){
	long long mnNum,mnDem;
	bool isF = true;
	for(int x : child[no]){
		dyndown(x);
		if(isF==true|| std::ratio_less< std::ratio<minNum[x],minDem[x]> , std::ratio<mnNum,mnDem> > ){
			mnNum = minNum[x];
			mnDem = minDem[x];
		}
	}

	if(isF || mnNum > mnDem){
		minNum[no] = xi[i];
		minDem[no] = 1;
	}else{
		 typedef std::ratio_multiply< std::ratio<mnNum,mnDem>, std::ratio<xi[i],1> > resu;
		 minNum[no] = resu::num;
		 minDem[no] = resu::dem;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d",&xi[i]);
	}

	rooting(1,0);

	dyndown(0);
}