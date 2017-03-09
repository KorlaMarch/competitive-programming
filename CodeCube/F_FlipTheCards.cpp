#include "stdio.h"
#include "vector"
#include "algorithm"

struct card{
	int a,b,num;
};

bool cmp(card a, card b){
	return a.a < b.a;
}

int n,m,vi;
card ca[1005];
int num[1005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&ca[i].a,&ca[i].b);
		ca[i].num = i;
	}
	std::sort(ca,ca+n,cmp);
	for(int i = 0; i < m; i++){
		scanf("%d",&vi);
		for(int j = 0; j < n; j++){
			if(ca[j].a<=vi){
				std::swap(ca[j].a,ca[j].b);
			}
		}
		std::sort(ca,ca+n,cmp);
	}
	for(int i = 0; i < n; i++){
		num[ca[i].num] = ca[i].a;
	}
	for(int i = 0; i < n; i++){
		printf("%d\n",num[i]);
	}
}