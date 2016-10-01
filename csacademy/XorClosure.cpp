#include "stdio.h"
#include "set"
#include "queue"

int n;
int a[100005];
std::set<int> num;
std::queue<int> check;
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		num.insert(a[i]);
		check.push(a[i]);
	}
	while(!check.empty()){
		int x = check.front();
		check.pop();

		for(int y : num){
			if(num.count(x^y)==0){
				num.insert(x^y);
				check.push(x^y);
				printf("Add %d\n",x^y);
			}
		}
	}

}