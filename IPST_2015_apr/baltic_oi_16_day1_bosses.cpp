#include "stdio.h"
#include "queue"
#include "vector"

#define INF 1000000000

int n,ki,x,sum,min,co;
std::vector<int> child[5005];
std::queue<int> qu[2];
bool isV[5005];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&ki);
		for(int j = 0; j < ki; j++){
			scanf("%d",&x);
			child[x].push_back(i);
		}
	}
	min = INF;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) isV[j] = false;
		qu[1].push(i);
		isV[i] = true;
		sum = 0;
		co = 0;
		for(int j = 1; !qu[j%2].empty(); j++){
			while(!qu[j%2].empty()){
				x = qu[j%2].front();
				qu[j%2].pop();
				co++;
				sum += j;
				for(int y : child[x]){
					if(!isV[y]){
						isV[y] = true;
						qu[(j+1)%2].push(y);
					}
				}
			}
		}
		if(co==n&&sum<min) min = sum;
	}
	printf("%d\n",min);
}