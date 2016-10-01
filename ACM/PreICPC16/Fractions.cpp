#include "stdio.h"
#include "vector"
#include "algorithm" 

int a,b;
std::vector<int> q;
int main(){
	scanf("%d %d",&a,&b);
	if(a==b){
		q.push_back(0);
	}

	if(a==0){
		q.push_back(0);
	}else while(a!=0&&b!=0){
		//printf("%d %d\n",a,b);
		if(a%b==0&&a/b>1){
			q.push_back(a/b-1);
			a = b;
		}else{
			q.push_back(a/b);
			a %= b;
			std::swap(a,b);
		}
	}

	printf("%d\n",q.size()-1);
	for(int i = 0; i < q.size(); i++){
		printf("%d ", q[i]);
	}
}