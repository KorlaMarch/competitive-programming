#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

int n;
int p[100005];
int minH[100005];
std::vector<int> child[100005];

void findMinH(int x){
	std::priority_queue<int,std::vector<int>,std::greater<int> > qu;
	for(int i : child[x]){
		findMinH(i);
		qu.push(minH[i]);
	}
	if(qu.empty()){
		minH[x] = 0;
		return;
	}else if(qu.size()==1){
		minH[x] = qu.top()+1;
		return;
	}
	//cal minH
	while(qu.size()>1){
		int a = qu.top();
		qu.pop();
		int b = qu.top();
		qu.pop();

		qu.push(std::max(a,b)+1);
	}
	
	minH[x] = qu.top();
}

int main(){
	scanf("%d",&n);
	for(int i = 2; i <= n; i++){
		scanf("%d",&p[i]);
		child[p[i]].push_back(i);
	}

	findMinH(1);

	printf("%d\n",minH[1]);
}