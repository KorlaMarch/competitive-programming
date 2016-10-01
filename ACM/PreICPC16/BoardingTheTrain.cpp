#include "stdio.h"
#include "vector"
#include "queue"

int c,n,k;
char s[25];
std::vector<int> jmp[105];
std::queue<int> qu[2];
int a[105];
bool isV[105];

int main(){
	scanf("%d%d",&c,&n);
	for(int i = 1; i < c; i++){
		scanf("%s %d",s,&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&a[j]);
		}
		for(int j = 0; j < k; j++){
			if(j+1!=k) jmp[a[j]].push_back(a[j+1]);
			if(j!=0) jmp[a[j]].push_back(a[j-1]);
		}
	}
	for(int i = 1; i <= n; i++){
		if(i!=n) jmp[i].push_back(i+1);
		if(i!=1) jmp[i].push_back(i-1);
	}
	qu[0].push(1);
	isV[1] = true;
	for(int i = 0; !qu[i%2].empty(); i++){
		while(!qu[i%2].empty()){
			int x = qu[i%2].front();
			qu[i%2].pop();
			if(x==n){
				printf("%d\n",i);
				return 0;
			}
			for(int j : jmp[x]){
				if(!isV[j]){
					isV[j] = true;
					qu[(i+1)%2].push(j);
				}
			}
		}
	}

}